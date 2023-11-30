/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:20:22 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/11/30 20:17:54 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// #include "minitalk.h"

// void	ft_bin2ascii(int s)
// {
// 	static int	i;
// 	static int	c;
// 	static int	k;

// 	// s += 18;
// 	// write(1, &s, 1);
// 	// s -= 18;
// 	if (!i && !k && !c)
// 	{
// 		i = 0;
// 		k = 0;
// 		c = 7;
// 	}
// 	if (i <= 7 && (s == SIGUSR1 || s == SIGUSR2))
// 	{
// 		k += (s - SIGUSR1) * pow(2, (c - i));
// 		i++;
// 	}
// 	if (i == 8)
// 	{
// 		write(1, &k, 1);
// 		i = 0;
// 		k = 0;
// 	}
// 	return ;
// }

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
		write (1, &s[i], 1);
		i++;
		usleep (10000);
	}
	return ;
}

static char	*ft_strrev(char *s, int len)
{
	int		i;
	char	*ms;

	i = 0;
	len -= 1;
	ms = (char *)malloc(len + 1);
	while (len >= 0)
		ms[i++] = s[len--];
	ms[i] = 0;
	return (ms);
}

void	ft_ascii2bin(int n, int pid)
{
	char	*s;
	int		i;
	int		c;
	int		l;
	int		len;

	i = 0;
	l = n;
	len = 8;
	s = (char *)malloc(len + 1);
	len = 0;
	while (len <= 7)
	{
		c = (n % 2) + 48;
		n /= 2;
		s[i] = c;
		i++;
		len++;
	}
	s[i] = 0;
	s = ft_strrev(s, len);
	ft_send(s, pid);
	return ;
}

int	main(int argc, char **argv)
{
	char	*s;
	char	*piid;
	char	*tmp;
	int		i;

	i = 0;
	// while (argv[1][i])
	// {
	// 	if (argv[1][i])
	// 	s[i] = argv[1][i];
	// 	write (1, &s[i], 1);
	// 	i++;
	// }
	// pid[i] = 0;
	// printf("%s", argv[1]);
	// return (0);
	// if (argc >= 2)
	// {
		while (argv[1][i])
		{
			if (argv[1][i] && (argv[1][i] > 47 || argv[1][i] > 58))
				i++;
			else
				return (0);
		}
		i = 0;
		// printf("%s", argv[1]);
		while (argv[2][i])
		{
			ft_ascii2bin(argv[2][i], ft_atoi(argv[1]));
			i++;
		}
	// }
	return (0);
}
