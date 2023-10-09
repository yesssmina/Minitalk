/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:22:42 by sannagar          #+#    #+#             */
/*   Updated: 2023/10/10 00:27:30 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include "./Libft/libft.h"
# include "./Printf/ft_printf.h"

extern int	g_signal;
void	send_c(char c, int pid);
void	server_answer(int sig);
void	send_bit(int pid, int bit);
int		ft_utf_charlen(char c);
void	send_utf_c(const char *c, int pid);
char	*error_mess(char *message);

#endif