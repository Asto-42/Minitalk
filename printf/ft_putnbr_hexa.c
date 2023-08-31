/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:56:17 by jquil             #+#    #+#             */
/*   Updated: 2023/02/15 16:22:28 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *r)
{
	int	x;

	x = 0;
	while (r[x])
	{
		write(1, &r[x], 1);
		x++;
	}
}

unsigned int	ft_powerr(unsigned int nbr)
{
	unsigned long int	x;
	unsigned int		y;

	x = 1;
	y = 1;
	if (nbr == 0)
		return (1);
	while (x < nbr)
	{
		x = x * 10;
		y++;
	}
	if (x > nbr)
	{
		x = x / 10;
		y--;
	}
	return (y);
}

int	ft_powerp(unsigned int nbr)
{
	unsigned long int	p;

	p = 1;
	while (nbr > p)
		p = p * 16;
	p = p / 16;
	return (p);
}

char	*ft_convert(unsigned int nbr, int p, char *base, int pow)
{
	int		i;
	int		x;
	char	*str;

	str = malloc((pow + 1) * sizeof(char));
	if (!str)
		return (NULL);
	x = 0;
	while (p >= 1)
	{
		if (p >= 1)
			i = nbr / p;
		str[x] = base[i];
		x++;
		if (p >= 1)
			nbr = nbr % p;
		p = p / 16;
	}
	str[x] = '\0';
	return (str);
}

int	ft_putnbr_hexa(unsigned int nbr, char *base)
{
	int		rank;
	int		p;
	char	*str;
	size_t	len;

	if (nbr == 16)
		return (write(1, "10", 2));
	rank = ft_powerr(nbr);
	p = ft_powerp(nbr);
	if (p == 0)
		p = 1;
	str = ft_convert(nbr, p, base, rank);
	if (!str)
		return (0);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
