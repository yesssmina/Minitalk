/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:13:35 by sam               #+#    #+#             */
/*   Updated: 2022/12/27 03:49:13 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_if_n_sup_a_zero(int n)
{
	char	*n_char;
	size_t	i;
	int		n_bis;

	i = 0;
	n_bis = n;
	while (n > 0)
	{
		n = n / 10;
		i ++;
	}
	n = n_bis;
	n_char = malloc(sizeof(char) * (i + 1));
	if (!n_char)
		return (NULL);
	n_char[i] = '\0';
	while (i > 0)
	{
		i--;
		n_char[i] = (n % 10) + '0';
		n = n / 10;
	}
	return (n_char);
}

char	*ft_if_n_inf_a_zero(int n)
{
	char	*n_char;
	size_t	i;
	int		n_bis;

	i = 0;
	n = -n ;
	n_bis = n;
	while (n > 0)
	{
		n = n / 10;
		i ++;
	}
	n = n_bis;
	n_char = malloc(sizeof(char) * (i + 2));
	if (!n_char)
		return (NULL);
	n_char[i + 1] = '\0';
	while (i > 0)
	{
		n_char[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	n_char[i] = '-';
	return (n_char);
}

char	*ft_itoa(int n)
{
	char	*n_char;

	if (n == -2147483648)
	{
		n_char = malloc(sizeof(char) * 12);
		if (!n_char)
			return (NULL);
		ft_strlcpy(n_char, "-2147483648", 12);
		return (n_char);
	}
	if (n >= 0 && n < 10)
	{
		n_char = malloc(sizeof(char) * 2);
		if (!n_char)
			return (NULL);
		n_char[0] = n + '0';
		n_char[1] = '\0';
	}
	if (n > 9)
		n_char = ft_if_n_sup_a_zero(n);
	if (n < 0)
		n_char = ft_if_n_inf_a_zero(n);
	return (n_char);
}

/*
int	main(void)
{
	char	*res;

	res = ft_itoa(1000034);
	printf("%s", res);
	free(res);
}*/