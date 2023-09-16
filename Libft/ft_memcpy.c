/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:07:56 by sanaggar          #+#    #+#             */
/*   Updated: 2022/11/21 18:04:24 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*src1;

	dest = dst;
	src1 = src;
	i = 0;
	if ((dst == NULL) && (src == NULL))
		return (NULL);
	while (i < n)
	{
		dest[i] = src1[i];
		i++;
	}
	return (dest);
}
