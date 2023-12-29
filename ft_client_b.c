/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aken <aken@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:20:22 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/12/29 08:11:36 by aken             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_recive(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("Massage Recived");
	exit (0);
}

static void	ft_send(char *s, int pid)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 48)
			if (!kill(pid, SIGUSR1))
				exit (ft_putstr("Wrong PID"));
		if (s[i] == 49)
			if (kill(pid, SIGUSR2))
				exit (ft_putstr("Wrong PID"));
		i++;
		usleep (500);
	}
	free(s);
	return ;
}

static char	*ft_strrev(char *s, int len)
{
	int		i;
	char	*ms;

	i = 0;
	len = 8;
	ms = (char *)malloc(len + 1);
	len--;
	if (!ms)
		return (0);
	while (len >= 0)
		ms[i++] = s[len--];
	ms[i] = 0;
	free (s);
	return (ms);
}

void	ft_ascii2bin(int n, int pid)
{
	char	*s;
	int		len;

	len = 8;
	s = (char *)malloc(len + 1);
	len = 0;
	while (len <= 7)
	{
		if ((n & 1) == 1)
			s[len] = 49;
		else
			s[len] = 48;
		n = (n >> 1);
		len++;
	}
	s[len] = 0;
	s = ft_strrev(s, len);
	ft_send(s, pid);
	return ;
}

int	main(int argc, char **argv)
{
	int		i;

	signal(SIGUSR1, ft_recive);
	i = 0;
	if (argc == 3)
	{
		if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) >= 2147483647)
		{
			ft_putstr("Invalid PID");
			return (0);
		}
		while (argv[2][i])
		{
			ft_ascii2bin(argv[2][i], ft_atoi(argv[1]));
			i++;
		}
		ft_ascii2bin(0, ft_atoi(argv[1]));
	}
	else
		ft_putstr("Invalid Number of Arguments");
	return (0);
}
