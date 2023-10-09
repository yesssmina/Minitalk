/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:24:25 by sannagar          #+#    #+#             */
/*   Updated: 2023/10/10 00:29:47 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_utf_charlen(char c)
{
	if ((unsigned char)c < 0x80)
		return (1);
	if ((unsigned char)c < 0xE0)
		return (2);
	if ((unsigned char)c < 0xF0)
		return (3);
	return (4);
}

void	send_utf_c(const char *c, int pid)
{
	int	len;
	int	i;

	i = 0;
	len = ft_utf_charlen(*c);
	while (i < len)
	{
		send_c(c[i], pid);
		i++;
	}
}

char	*error_mess(char *message)
{
	ft_putstr_fd(message, 1);
	exit(EXIT_FAILURE);
}
