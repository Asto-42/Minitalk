/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:25:04 by jquil             #+#    #+#             */
/*   Updated: 2022/12/07 13:33:03 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p(uintptr_t i)
{
	unsigned long int	r;
	int					x;
	char				*n;

	x = 0;
	if (i == 0)
	{
		n = "(nil)";
		ft_putstr(n);
		return (5);
	}
	r = ft_putnbr_unsign(i, "0123456789abcdef");
	return (r);
}

int	ft_pourcent(char p, char i, va_list list)
{
	int	x;

	x = 0;
	if (p != '%')
		return (0);
	if (i == 'c')
		x = ft_c((char)(va_arg(list, int)));
	if (i == 's')
		x = ft_s(va_arg(list, char *));
	if (i == 'd' || i == 'i')
		x = ft_deci(va_arg(list, int));
	if (i == 'u')
		x = ft_u(va_arg(list, unsigned int));
	if (i == '%')
	{
		write(1, "%", 1);
		x = 1;
	}
	if (i == 'x')
		x = ft_putnbr_hexa(va_arg(list, unsigned int), "0123456789abcdef");
	if (i == 'X')
		x = ft_putnbr_hexa(va_arg(list, unsigned int), "0123456789ABCDEF");
	if (i == 'p')
		x = ft_p(va_arg(list, uintptr_t));
	return (x);
}

int	ft_printf(const char *c, ...)
{
	int		x;
	int		tot;
	va_list	list;

	if (!c)
		return (-1);
	va_start(list, c);
	x = ft_strlen(c);
	tot = 0;
	x = 0;
	while (c[x])
	{
		if (c[x] == '%')
		{
			tot += ft_pourcent(c[x], c[x + 1], list);
			x++;
		}
		else
			tot += write(1, &c[x], 1);
		x++;
	}
	va_end(list);
	return (tot);
}
/*
#include <stdio.h>
int	main(void)
{
	unsigned int	s;
	int i;
	unsigned int	u ;
	//void	*p = NULL;
	int	ret;
	int ret2;

	s = -958;
	i = INT_MAX;
	u = UINT_MAX;
	ret = ft_printf("%d ", INT_MAX);
	printf("ret = %i\n", ret);
	ret2 = printf("%d ", INT_MAX);
	printf("ret = %i\n", ret2);
	if (ret == ret2)
		printf("OK");
	else
		printf("KO");
	return (0);
}
*/
