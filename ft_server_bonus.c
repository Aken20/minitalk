/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:20:17 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/12/25 21:41:37 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bin2ascii(int s)
{
	static int	i;
	static int	k;

	if ((!i && !k) || i > 8)
	{
		i = 0;
		k = 0;
	}
	if (i <= 7 && s == SIGUSR1)
		i++;
	if (i <= 7 && s == SIGUSR2)
	{
		k += 1 * pow(2, (7 - i));
		i++;
	}
	if (i == 8)
	{
		write(1, &k, 1);
		i = 0;
		k = 0;
	}
	return ;
}

int	main(void)
{
	ft_itoa(getpid());
	write(1, "\n", 2);
	signal(SIGUSR1, ft_bin2ascii);
	signal(SIGUSR2, ft_bin2ascii);
	while (1)
		pause ();
	return (0);
}
