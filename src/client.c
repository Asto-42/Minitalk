/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:12:05 by jquil             #+#    #+#             */
/*   Updated: 2023/05/31 16:20:46 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

volatile int	g_proof = 0;

int	ft_atoi(const char *nptr)
{
	int	x;
	int	s;
	int	i;

	x = 0;
	s = 1;
	i = 0;
	while ((nptr[x] >= 9 && nptr[x] <= 13) || nptr[x] == 32)
		x++;
	if (nptr[x] == '-')
		s = -1;
	if (nptr[x] == '-' || nptr[x] == '+')
		x++;
	while (nptr[x] >= 48 && nptr[x] <= 57)
	{
		i = i + (nptr[x] - 48);
		if (nptr[x + 1] >= 48 && nptr[x + 1] <= 57)
			i = i * 10;
		x++;
	}
	i = i * s;
	if (i < 300 || i > 4194304)
		ft_printf("Error\n");
	return (i);
}

void	ft_atob(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		ft_tempo();
		g_proof = 1;
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
	}
}

void	ft_itob(int pid, int len)
{
	int	bit;

	bit = 0;
	while (bit < 31)
	{
		ft_tempo();
		g_proof = 1;
		if ((len & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
	}
}

int	ft_proof(int sig)
{
	if (sig == SIGUSR1)
		g_proof = 0;
	return (-1);
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	unsigned int		len;
	struct sigaction	sb;

	sb.sa_handler = (void *)ft_proof;
	sigemptyset(&sb.sa_mask);
	sb.sa_flags = 0;
	i = -1;
	if (argc != 3)
	{
		ft_printf("Error\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 300 || pid > 4194304)
		return (0);
	len = (ft_strlen(argv[2]) + 1);
	sigaction(SIGUSR1, &sb, 0);
	ft_itob(pid, len);
	while (argv[2][++i] != '\0')
		ft_atob(pid, argv[2][i]);
	ft_atob(pid, '\0');
	return (1);
}
