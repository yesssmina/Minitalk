/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:58:59 by sanaggar          #+#    #+#             */
/*   Updated: 2023/09/13 19:15:14 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lensrc;
	size_t	lendst;

	if ((!dst || !src) && dstsize == 0)
		return (0);
	i = 0;
	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= lendst)
		return (dstsize + lensrc);
	while (src[i] && i < dstsize - 1 - lendst)
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	return (lendst + lensrc);
}
/*
#include <string.h>

int	main(void)
{
	char	src[30] = "Coucou";
	char	dest[30] = "wesh";
	char    src2[30] = "Coucou";
	char    dest2[30] = "wesh";
	printf("****************Moi\n");
	printf("%lu\n", ft_strlcat(dest, NULL, 0));
	printf("%s\n", src);
	printf("%s\n", dest);
	printf("****************officiel\n");
	printf("%lu\n", strlcat(dest2, NULL, 0));
	printf("%s\n", src2);
	printf("%s\n", dest2);
	return (0);
}*/
