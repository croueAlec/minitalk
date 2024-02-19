/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:09:57 by acroue            #+#    #+#             */
/*   Updated: 2024/02/19 21:27:34 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <stdlib.h>

int	value;

int	convert_signals_to_char(char *str)
{
	size_t	i;
	int		res;

	res = 0;
	while (str[i])
	{
		res = res << 1 | str[i] - 48;
		i++;
	}
	ft_memset(str, '0', 9);
	return (res);
}

void	catch_signals(int code)
{
	if (code == 10)
	{
		value = 1;
	}
	else if (code == 12)
	{
		value = 0;
	}
}

void	received_one(int code)
{
	printf("1\n");
}

void	received_two(int code)
{
	printf("0\n");
}

int main(int argc, char const *argv[])
{
	pid_t	pid;
	size_t	i;
	char	str[9];

	i = 8;
	pid = getpid();
	printf("%d\n", pid);
	signal(SIGUSR1, &received_one);
	signal(SIGUSR2, &received_two);
	while (1)
		;
	// while (1)
	// {
	// 	if (i == 0)
	// 	{
	// 		convert_signals_to_char(str);
	// 		i = 8;
	// 	}
	// 	signal(SIGUSR1, &catch_signals);
	// 	signal(SIGUSR2, &catch_signals);
	// 	str[i] = value + 48;
	// 	i--;
	// }
	return (0);
}
