/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:47:06 by jquil             #+#    #+#             */
/*   Updated: 2023/02/15 16:19:21 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_c(char s)
{
	write (1, &s, 1);
	return (1);
}

int	ft_s(char *s)
{
	int	x;

	x = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[x])
	{
		write(1, &s[x], 1);
		x++;
	}
	return (ft_strlen(s));
}

int	ft_deci(int i)
{
	char	*s;
	int		x;
	size_t	len;

	x = 0;
	s = ft_itoa(i);
	if (!s)
		return (0);
	len = ft_strlen(s);
	while (s[x])
	{
		write(1, &s[x], 1);
		x++;
	}
	free(s);
	return (len);
}

int	ft_u(unsigned int x)
{
	char	*s;
	int		y;
	int		len;

	y = 0;
	s = ft_unsigned_itoa(x);
	if (!s)
		return (0);
	len = ft_strlen(s);
	while (s[y])
	{
		write(1, &s[y], 1);
		y++;
	}
	free(s);
	return (len);
}
