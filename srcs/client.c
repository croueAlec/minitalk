/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:43:59 by acroue            #+#    #+#             */
/*   Updated: 2024/02/20 12:23:23 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int	int_to_binary(int decimal_num)
{
	int		remainder;
	int		binary_num;
	size_t	i;

	i = 1;
	binary_num = 0;
	while (decimal_num != 0)
	{
		remainder = decimal_num % 2;
		decimal_num /= 2;
		binary_num += remainder * i;
		i *= 10;
	}
	return (binary_num);
}

void	send_char(int ch, pid_t pid)
{
	size_t	i;

	i = 0;
	while (i < 8)
	{
		if (i == 0)
			printf("%d\n", int_to_binary(ch));
		if (ch & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		ch = ch >> 1;
		usleep(1);
		i++;
	}
}

void	send_str(char *str, pid_t pid)
{
	size_t	i;
	i = 0;
	printf("%s\n\n", str);
	while (str[i])
	{
		send_char(str[i], pid);
		usleep(1);
		i++;
	}
}

int main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		return (ft_dprintf(2, "Error : ./client SERVER_PID MESSAGE\n"));
	pid = ft_atoi(argv[1]);
	send_str(argv[2], pid);
	return (0);
}

