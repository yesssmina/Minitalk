/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 00:14:52 by sam               #+#    #+#             */
/*   Updated: 2023/09/13 19:13:37 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_split
{
	char	*set;
	size_t	i;
	size_t	j;
	char	*ss_tab;
	char	**tab;
	char	*s1;
	size_t	nb_list;
	char	tmp_set[2];
}			t_split;

char	*ft_ss_tab(char	*s, char c)
{
	t_split	v;

	v.i = 0;
	v.j = 0;
	while (s[v.i] && s[v.i] == c)
		v.i++;
	while (s[v.i] && s[v.i] != c)
	{
		v.j++;
		v.i++;
	}
	v.ss_tab = malloc(sizeof(char) * (v.j + 1));
	if (!v.ss_tab)
	{
		free(v.ss_tab);
		return (NULL);
	}
	v.i -= v.j;
	v.j = 0;
	while (s[v.i] && s[v.i] != c)
		v.ss_tab[v.j++] = s[v.i++];
	v.ss_tab[v.j] = '\0';
	return (v.ss_tab);
}

char	**fill_tab(char **tab, size_t nb_list, char *s1, char c)
{
	t_split	v;

	v.i = 0;
	v.j = 0;
	while (v.j < nb_list)
	{
		tab[v.j] = ft_ss_tab(s1 + v.i, c);
		if (!tab[v.j])
			return (NULL);
		while (s1[v.i] && s1[v.i] == c)
			v.i++;
		v.i += ft_strlen(tab[v.j]);
		v.j++;
	}
	tab[v.j] = NULL;
	return (tab);
}

size_t	ft_nb_c_in_list(char const *s, char c)
{
	t_split	v;

	v.i = 0;
	v.j = 0;
	while (s[v.i])
	{
		if (v.i == 0 && s[v.i] == c)
		{
			while (s[v.i] == c)
				v.i++;
		}
		if (c == s[v.i] && c != s[v.i + 1] && s[v.i + 1] != '\0')
			v.j++;
		v.i++;
	}
	if (v.i > 0 && s[v.i - 1] == c)
		v.j--;
	return (v.j);
}

char	**ft_split(char const *s, char c)
{
	t_split	v;

	if (!s)
		return (NULL);
	v.tmp_set[0] = c;
	v.tmp_set[1] = '\0';
	v.s1 = ft_strtrim(s, v.tmp_set);
	if (!v.s1 || *v.s1 == '\0')
	{
		free(v.s1);
		v.tab = malloc(sizeof(char *));
		if (!v.tab)
			return (NULL);
		v.tab[0] = NULL;
		return (v.tab);
	}
	v.nb_list = ft_nb_c_in_list(v.s1, c) + 1;
	v.tab = malloc(sizeof(char *) * (v.nb_list + 1));
	if (!v.tab)
		return (NULL);
	v.tab = fill_tab(v.tab, v.nb_list, v.s1, c);
	free(v.s1);
	return (v.tab);
}

//#include <stdio.h>

// int	main(void)
// {
// 	char	**res;
// 	size_t	i;

// 	i = 0;
// 	res = ft_split("5 3 4 5", ' ');
// 	while (res[i] != NULL)
// 	{
// 		printf("%s\n", res[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (res[i] != NULL)
// 	{
// 		free(res[i]);
// 		i++;
// 	}
// 	free(res);
// 	//system("leaks a.out >&2");
// }
