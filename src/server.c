/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:33:50 by ctaboada          #+#    #+#             */
/*   Updated: 2025/05/16 12:08:59 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	signal_handler(int signal_number)
{
	static int				bit;
	static unsigned char	byte;

	if (signal_number == SIGUSR1)
	{
		byte |= (1 << (7 - bit));
	}
	bit++;
	if (bit == 8)
	{
		write(1, &byte, 1);
		if (byte == 0)
			printf("\n");
		bit = 0;
		byte = 0;
	}
}

int	main(void)
{
	ft_putstr_fd("PID SERVER : ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
