/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:48:29 by sam               #+#    #+#             */
/*   Updated: 2022/12/24 18:59:32 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	begin(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (0);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

size_t	fin(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (0);
	i = ft_strlen(s1) - 1;
	while (i > 0 && ft_strrchr(set, s1[i]))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	beg;
	size_t	fi;

	beg = begin(s1, set);
	fi = fin(s1, set);
	if (!s1 || !set)
		return (NULL);
	if (beg == (ft_strlen(s1)) || (!s1[0] && !set[0]))
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		*str = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * (fi - beg + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + beg, fi - beg + 2);
	return (str);
}
/*
int	main(void)
{
	char	*str;

	str =  ft_strtrim("  \t \t \n   \n\n\n\t", " \n\t");
	printf("%s", str);
	free(str);
}*/