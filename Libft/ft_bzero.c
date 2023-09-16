/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_zero.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:36:13 by sanaggar          #+#    #+#             */
/*   Updated: 2022/11/11 16:59:57 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void	*s, size_t n)
{
	ft_memset(s, '\0', n);
}
/*
int	main(void)
{
	char	ptr[10] = "ABC DEF";

	printf("%s\n", ft_bzero(ptr, 5));
	printf("%s\n", bzero(ptr, 5));
}*/
