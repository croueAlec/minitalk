/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:09:57 by acroue            #+#    #+#             */
/*   Updated: 2024/02/20 13:19:05 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <stdlib.h>

int	g_is_signal;

int	convert_signals_to_char(char *str)
{
	size_t	i;
	int		res;

	res = 0;
	i = 0;
	while (str[i])
	{
		res = res << 1 | str[i] - 48;
		i++;
	}
	return (res);
}

void	catch_signals(int code)
{
	if (code == 10)
	{
		g_is_signal = 1;
	}
	else if (code == 12)
	{
		g_is_signal = 0;
	}
}

void	print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
}

int	main(int argc, char const *argv[])
{
	size_t	i;
	char	str[9];

	ft_memset(str, '0', 8);
	str[8] = '\0';
	i = 7;
	g_is_signal = -1;
	print_pid();
	signal(SIGUSR1, &catch_signals);
	signal(SIGUSR2, &catch_signals);
	while (1)
	{
		if (g_is_signal != -1)
		{
			str[i] = g_is_signal + 48;
			if (--i == -1)
			{
				ft_putchar_fd(convert_signals_to_char(str), 1);
				i = 7;
			}
			g_is_signal = -1;
		}
	}
	return (0);
}
