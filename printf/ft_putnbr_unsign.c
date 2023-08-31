/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:50:01 by jquil             #+#    #+#             */
/*   Updated: 2023/02/15 15:48:10 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_reverse(char *r)
{
	int	x;
	int	y;
	int	tmp;

	x = (ft_strlen(r)) - 1;
	y = 0;
	while (r && x > y)
	{
		tmp = r[y];
		r[y] = r[x];
		r[x] = tmp;
		x--;
		y++;
	}
	return (r);
}

int	ft_putnbr_unsign(uintptr_t nbr, char *base)
{
	long unsigned int	bl;
	unsigned long int	i;
	int					x;
	char				*r;

	r = malloc((18) * sizeof(char));
	if (!r)
		return (0);
	x = 0;
	i = nbr;
	bl = 16;
	while (nbr >= 1)
	{
		i = nbr % 16;
		r[x] = base[i];
		x++;
		nbr = nbr / 16;
	}
	r[x] = '\0';
	ft_putstr("0x");
	r = ft_reverse(r);
	ft_putstr(r);
	bl = ft_strlen(r);
	free(r);
	return (bl + 2);
}
