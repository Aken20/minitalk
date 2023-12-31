/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:20:22 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/04 22:17:33 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_isdigit(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] >= '0' && c[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

static void	ft_send(char *s, int pid)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 48)
			kill(pid, SIGUSR1);
		if (s[i] == 49)
			kill(pid, SIGUSR2);
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

	i = 0;
	if (argc == 3)
	{
		if (!ft_isdigit(argv[1]))
		{
			ft_putstr("Invalid PID");
			return (0);
		}
		if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) >= 2147483647)
		{
			ft_putstr("Invalid PID");
			return (0);
		}
		i = 0;
		while (argv[2][i])
		{
			ft_ascii2bin(argv[2][i], ft_atoi(argv[1]));
			i++;
		}
	}
	else
		ft_putstr("Invalid Number of Arguments");
	return (0);
}
