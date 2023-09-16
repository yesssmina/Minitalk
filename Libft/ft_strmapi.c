/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:48:39 by sam               #+#    #+#             */
/*   Updated: 2022/12/27 21:37:01 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	ma_ft;
	char	*s1;

	i = 0;
	if (!s)
		return (NULL);
	while (i < ft_strlen(s))
		i++;
	s1 = malloc(sizeof(char) * (i + 1));
	if (!s1)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		ma_ft = (*f)(i, s[i]);
		s1[i] = ma_ft;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

// int main(void)
// {
//     char s[] = "hello";
//     char *result = ft_strmapi(s, upper);
//     printf("%s\n", result);
//     free(result);
//     return 0;
// }