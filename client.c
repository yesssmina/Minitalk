/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 23:57:03 by sannagar          #+#    #+#             */
/*   Updated: 2023/10/10 00:39:25 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_signal = 0;

char	*error_mess(char *message)
{
	ft_putstr_fd(message, 1);
	exit(EXIT_FAILURE);
}

void	server_answer(int sig)
{
	if (sig == SIGUSR1)
		g_signal = 1;
	if (sig == SIGUSR2)
		g_signal = 2;
}

void	send_bit(int pid, int bit)
{
	g_signal = 0;
	if ((bit & 0x01) != 0)
	{
		if (kill(pid, SIGUSR1) == -1)
			error_mess("Error\n");
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			error_mess("Error\n");
	}
	while (1)
	{
		if (g_signal == 1)
			break ;
		else if (g_signal == 2)
			break ;
	}
}

void	send_c(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		send_bit(pid, (c >> bit) & 0x01);
		bit++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*message;

	if (ac != 3)
		error_mess("Error\n1st arg: Server PID\n2nd arg: Message to send\n");
	pid = ft_atoi(av[1]);
	if (kill(pid, 0) == -1)
		error_mess("Error\nInvalid PID\n");
	message = av[2];
	signal(SIGUSR1, server_answer);
	signal(SIGUSR2, server_answer);
	while (*message)
	{
		send_c(*message, pid);
		message++;
	}
	send_c('\0', pid);
	return (EXIT_SUCCESS);
}
