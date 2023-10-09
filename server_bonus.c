/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:21:50 by sannagar          #+#    #+#             */
/*   Updated: 2023/10/10 00:28:38 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	*g_message = NULL;

char	*error_mess(char *message)
{
	ft_putstr_fd(message, 1);
	exit(EXIT_FAILURE);
}

void	handle_exit(int sig)
{
	(void)sig;
	free(g_message);
	exit(0);
}

char	*add_char(char *str, char c)
{
	char	*final_string;
	int		i;

	final_string = malloc(sizeof(char) * ft_strlen(str) + 2);
	i = 0;
	while (str[i])
	{
		final_string[i] = str[i];
		i++;
	}
	final_string[i] = c;
	final_string[i + 1] = 0;
	free(str);
	return (final_string);
}

void	sig_received(int sig, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static int	i = 0;

	(void)context;
	if (sig == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		g_message = add_char(g_message, i);
		if (i == '\0')
		{
			ft_printf("%s\n", g_message);
			free(g_message);
			g_message = malloc(1);
			g_message[0] = 0;
			kill(info->si_pid, SIGUSR2);
		}
		else
			kill(info->si_pid, SIGUSR1);
		i = 0;
		bit = 0;
	}
	else
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	g_message = malloc(1);
	g_message[0] = 0;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	signal(SIGINT, handle_exit);
	sa.sa_sigaction = sig_received;
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (0);
}
