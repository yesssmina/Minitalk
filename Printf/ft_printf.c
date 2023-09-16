/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:09:56 by sanaggar          #+#    #+#             */
/*   Updated: 2023/05/03 16:24:27 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	choice(char c, va_list args, int *print)
{
	if (c == '%')
	{
		write(1, &c, 1);
		(*print)++;
	}
	if (c == 'x')
		ft_x(va_arg(args, size_t), print);
	if (c == 'X')
		ft_upperx(va_arg(args, size_t), print);
	if (c == 'd' || c == 'i')
		ft_d(va_arg(args, int), print);
	if (c == 'c')
		ft_c(va_arg(args, int), print);
	if (c == 's')
		ft_s(va_arg(args, char *), print);
	if (c == 'p')
		ft_p(va_arg(args, size_t), print);
	if (c == 'u')
		ft_u(va_arg(args, size_t), print);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		print;
	int		i;

	i = 0;
	print = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			choice(format[i + 1], args, &print);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			print++;
		}
		i++;
	}
	va_end(args);
	return (print);
}

// int	main(void)
// {	
// 	char	*ptr;

// 	ptr = "42";
// 	printf("ret ft = %d\n", ft_printf("\001\002\007\v\010\f\r\n"));
// 	write(1, "\n", 1);
// 	printf("ret = %d\n", printf("\001\002\007\v\010\f\r\n"));
// 	return (0);
// }
