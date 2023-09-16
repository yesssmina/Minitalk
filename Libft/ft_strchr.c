/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:17:38 by sanaggar          #+#    #+#             */
/*   Updated: 2022/11/28 19:49:55 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char	*s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c % 256)
		i++;
	if (s[i] == c % 256)
		return ((char *)s + i);
	return (NULL);
}
/*
#include <string.h>

int main(void)
{
    char    str[20] = "tripouille";
    
    printf("%s\n", strchr((char *)str[0], 't'));
    printf("%s\n", ft_strchr((char *)str[0], 't'));

}*/
