/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:36:39 by ctaboada          #+#    #+#             */
/*   Updated: 2025/05/19 12:07:33 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	atob(int server_pid, char *str)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if ((*str >> bit) & 1)
		{
			kill(server_pid, SIGUSR1);
		}
		else
		{
			kill(server_pid, SIGUSR2);
		}
		usleep(500);
	}
}
