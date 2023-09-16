/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:08:12 by sanaggar          #+#    #+#             */
/*   Updated: 2023/05/03 16:08:17 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(char	*base, size_t	nb, int *print)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (nb >= base_len)
	{
		ft_putnbr_base(base, nb / base_len, print);
		ft_putnbr_base(base, nb % base_len, print);
	}
	if (nb < base_len)
	{
		ft_putchar_fd(base[nb], 1);
		(*print)++;
	}
}

void	ft_d(int nb, int *print)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*print) += 11;
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nb = -nb;
		(*print)++;
	}
	ft_putnbr_base("0123456789", nb, print);
}
