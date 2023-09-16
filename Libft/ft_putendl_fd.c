/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:18:08 by sam               #+#    #+#             */
/*   Updated: 2022/12/27 22:36:03 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	lettre;
	char	nl;

	nl = '\n';
	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		lettre = s[i];
		write(fd, &lettre, 1);
		i++;
	}
	write(fd, &nl, 1);
}
