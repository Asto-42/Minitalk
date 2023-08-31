/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:52:54 by jquil             #+#    #+#             */
/*   Updated: 2022/12/07 13:22:08 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <unistd.h>
# include <strings.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <stdint.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
int		ft_printf(const char *c, ...);
int		ft_putnbr_hexa(unsigned int nbr, char *base);
void	ft_putstr(char *r);
void	ft_putchar(char r);
int		ft_putnbr_unsign(uintptr_t nbr, char *base);
char	*ft_unsigned_itoa(unsigned int n);
int		ft_c(char s);
int		ft_s(char *s);
int		ft_deci(int i);
int		ft_u(unsigned int x);

#endif
