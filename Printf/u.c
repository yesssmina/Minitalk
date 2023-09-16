/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:10:30 by sanaggar          #+#    #+#             */
/*   Updated: 2023/09/13 19:11:23 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(unsigned int nb, int *print)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10, print);
		ft_putnbr(nb % 10, print);
	}
	if (nb < 10)
	{
		ft_putchar_fd(nb + '0', 1);
		(*print)++;
	}
}

void	ft_u(unsigned int d, int	*print)
{
	ft_putnbr(d, print);
}
