/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aken <aken@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:20:17 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/12/25 15:44:49 by aken             ###   ########.fr       */
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
	int			pid;

	pid = info->si_pid;
	context = 0;
	if ((!i && !k) || i > 8)
	{
		i = 0;
		k = 0;
	}
	if (i <= 7 && s == SIGUSR1)
		i++;
	if (i <= 7 && s == SIGUSR2)
		k += 1 * pow(2, (7 - i++));
	if (i == 8)
	{
		if (k == 0)
			ft_send_recive(pid);
		write(1, &k, 1);
		i = 0;
		k = 0;
	}
	return ;
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
