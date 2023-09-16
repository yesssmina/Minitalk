/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 23:57:03 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/16 11:57:12 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*error_mess(char *message)
{
	ft_putstr_fd(message, 1);
	exit(EXIT_FAILURE);
}

void	send_c(char c, pid_t pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

void	send_string(const char *str, pid_t pid)
{
	while (*str)
	{
		send_c(*str, pid);
		str++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
		error_mess("Error\n1er arg: PID server\n2e arg: message a envoyer\n");
	pid = ft_atoi(av[1]);
	if (kill(pid, 0) == -1)
		error_mess("Error\nLe pid n'est pas valide\n");
	send_string(av[2], pid);
	return (EXIT_SUCCESS);
}
