/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:06:39 by sanaggar          #+#    #+#             */
/*   Updated: 2022/12/02 21:19:00 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s || (!s && start == 0 && len == 0))
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len <= (size_t)ft_strlen(s + start))
		str = malloc(sizeof(char) * (len + 1));
	else
		str = malloc(sizeof(char) * (ft_strlen(s + start) + 1));
	if (!str)
		return (NULL);
	while (s[start] && i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char *s = ft_substr("hola", 2, 3);
// 	printf("%s\n", s);
// 	// printf("%s\n", ft_substr("hola", 2, 3));
// 	system("leaks a.out");
// 	return (0);
// }
