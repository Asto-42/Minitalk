/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:12:13 by jquil             #+#    #+#             */
/*   Updated: 2023/05/31 16:19:48 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

extern int	g_proof;

int	ft_btoi(int sig)
{
	static int	bit;
	static int	i;
	int			res;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	if (sig == SIGUSR1 || sig == SIGUSR2)
		bit++;
	if (bit == 31)
	{
		bit = 0;
		res = i;
		i = 0;
		return (res);
	}
	return (0);
}

int	ft_end_str(char *str, int pid, int x)
{
	(void)x;
	ft_printf("%s", str);
	(void)pid;
	return (0);
}

int	ft_btoa(int sig, char *str, int len, int pid)
{
	static int	bit;
	static int	i;
	static int	x;

	if (sig == SIGUSR1)
		i |= (0x01 << bit % 8);
	bit++;
	if (bit % 8 == 0)
	{
		str[x] = (char)i;
		i = 0;
		x++;
	}
	kill(pid, SIGUSR1);
	if (x == len)
	{
		x = ft_end_str(str, pid, x);
		bit = 0;
		i = 0;
		len = 0;
		return (1);
	}
	return (0);
}

void	ft_step(int sig, siginfo_t *sa, void *sa2)
{
	static int	len;
	static int	proof_len;
	static char	*str;
	int			pid;

	(void)sa2;
	pid = sa->si_pid;
	if (sig != SIGUSR1 && sig != SIGUSR2)
		return ;
	if (proof_len++ < 31)
	{
		len = ft_btoi(sig);
		kill(pid, SIGUSR1);
		return ;
	}
	if (!str)
		str = malloc ((len) * sizeof(char));
	if (!str)
		return ;
	if (ft_btoa(sig, str, len, pid))
	{
		proof_len = 0;
		free(str);
		str = NULL;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = ft_step;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	argv[0] = argv[0];
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	pid = getpid();
	ft_printf("pid : %i\n", pid);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (42)
		;
	return (1);
}
