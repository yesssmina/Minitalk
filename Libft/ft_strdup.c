/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:35:44 by sanaggar          #+#    #+#             */
/*   Updated: 2022/12/31 16:10:25 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char	*src)
{
	int		i;
	char	*copy;

	copy = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (src == NULL)
		return (NULL);
	i = 0;
	if (!copy)
		return (NULL);
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*
int	main(int ac, char	**av)
{
	if (ac == 2)
	{
		printf("La copie de str est %s\n", strdup(av[1]));
		printf("La copie de str est %s\n", ft_strdup(av[1]));
	}
}*/
