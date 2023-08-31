/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:29:56 by jquil             #+#    #+#             */
/*   Updated: 2023/02/15 15:48:15 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_unsigned_itoa2(char *str, int p, unsigned int n)
{
	int	c;
	int	x;
	int	a;

	x = 1;
	a = 0;
	c = 0;
	str[p] = '\0';
	while (a < p - 1)
	{
		x = x * 10;
		a++;
	}
	while (c < p)
	{
		str[c] = (n / x) + 48;
		c++;
		n = n % x;
		x = x / 10;
	}
	return (str);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	unsigned int		x;
	int					p;
	char				*str;

	p = 0;
	x = 1;
	while (x <= (n / 10))
		x = x * 10;
	while (x > 0)
	{
		p++;
		x = x / 10;
	}
	str = malloc((p + 1) * sizeof(char));
	if (!str)
		return (0);
	str = ft_unsigned_itoa2(str, p, n);
	return (str);
}
