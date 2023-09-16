/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:58:27 by sanaggar          #+#    #+#             */
/*   Updated: 2023/09/13 19:14:04 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (((s1 == NULL || s2 == NULL) && len == 0))
		return (0);
	if (!s2[i])
		return ((char *)s1);
	if ((size_t)ft_strlen(s1) < len)
		len = ft_strlen(s1);
	while (i < len)
	{
		j = 0;
		while (s1[j + i] == s2[j] && i + j < len)
		{
			if (s2[j + 1] == '\0')
				return ((char *)s1 + i);
			j++;
		}
		i++;
	}
	if (j != (size_t)ft_strlen(s2) || len == 0)
		return (0);
	return ((char *)s1 + i);
}
/*
int	main(void)
{
//	char	s1[] = "";
	char	s2[] = "ca roule";

	printf("%s\n", strnstr(NULL,s2, 0));
	printf("%s\n", ft_strnstr(NULL,s2, 0));
}*/
