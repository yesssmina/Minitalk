/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:46:43 by sanaggar          #+#    #+#             */
/*   Updated: 2022/11/13 15:55:19 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < (dstsize -1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <string.h>

int	main(void)
{
	char	src[50] = "Coucou";
	char	dest[50];
	printf("%lu\n", ft_strlcpy(dest, src, 10));
	printf("%s\n", dest);
	printf("%lu\n", strlcpy(dest, src, 10));
	printf("%s\n", dest);
	return (0);
}*/
