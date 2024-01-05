/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:20:17 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/05 05:17:05 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_recive(int pid)
{
	kill(pid, SIGUSR1);
}

void	ft_bin2ascii(int s, siginfo_t *info, void *context)
{
	static int	i;
	static int	k;

	context = 0;
	if ((!i && !k) || i > 8)
	{
		i = 0;
		k = 0;
	}
	k = k << 1;
	if (i <= 7 && s == SIGUSR1)
		i++;
	if (i <= 7 && s == SIGUSR2)
	{
		k = (k | 1);
		i++;
	}
	if (i == 8)
	{
		if (k == 0)
			ft_send_recive(info->si_pid);
		write(1, &k, 1);
		i = 0;
		k = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = ft_bin2ascii;
	sa.sa_flags = SA_SIGINFO;
	ft_itoa(getpid());
	write(1, "\n", 2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause ();
	return (0);
}
