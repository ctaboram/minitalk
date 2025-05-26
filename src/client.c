/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:01:53 by ctaboada          #+#    #+#             */
/*   Updated: 2025/05/19 12:07:22 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	main(int ac, char **av)
{
	int	i;
	int	server_pid;

	if (ac < 3)
	{
		ft_putstr_fd("You have to introduce 2 arguments!!\n", 2);
		return (EXIT_FAILURE);
	}
	else
	{
		i = 0;
		server_pid = atoi(av[1]);
		if (server_pid <= 0)
		{
			ft_putstr_fd("Invalid PID\n", 2);
			return (EXIT_FAILURE);
		}
		while (av[2][i] != '\0')
			atob(server_pid, &av[2][i++]);
		atob(server_pid, "\n");
	}
	return (EXIT_SUCCESS);
}
