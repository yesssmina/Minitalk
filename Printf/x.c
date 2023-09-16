/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:10:46 by sanaggar          #+#    #+#             */
/*   Updated: 2023/09/13 19:11:51 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_upperx(unsigned int d, int	*print)
{
	ft_putnbr_base("0123456789ABCDEF", d, print);
}

void	ft_x(unsigned int d, int	*print)
{
	ft_putnbr_base("0123456789abcdef", d, print);
}
