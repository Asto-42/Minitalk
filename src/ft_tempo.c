/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tempo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:12:26 by jquil             #+#    #+#             */
/*   Updated: 2023/05/31 16:19:16 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

extern int	g_proof;

void	ft_tempo(void)
{
	while (g_proof == 1)
	{
		usleep(100);
	}
}
