/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:35:29 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/12/30 10:06:44 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int			aoi;
	int			i;

	i = 0;
	if (str[i] == 0)
		return (0);
	if (str[i] > 48 && str[i] <= 57)
		aoi = (str[i++] - 48);
	else
		return (0);
	while (str[i] >= 48 && str[i] <= 57)
		aoi = (aoi * 10) + (str[i++] - 48);
	return (aoi);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s != 0 && s[i] != 0)
		write(1, &s[i++], 1);
	return (i);
}

static	int	ft_counting(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static	char	*ft_set(char *s, long long n, int len)
{
	long long	c;
	long long	l;

	l = 10;
	if (n < 0)
	{
		s[0] = '-';
		n = n * -1;
	}
	len--;
	if (n > 0)
		s[len] = (n % 10) + 48;
	len--;
	while (n >= l)
	{
		l *= 10;
		c = (n % l);
		s[len] = c / (l / 10) + 48;
		len--;
	}
	return (s);
}

int	ft_itoa(long long n)
{
	char	*s;
	int		len;

	if (n == 0)
		return (ft_putstr("0"));
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	len = ft_counting(n);
	if (n != 0)
	{
		s = malloc(len + 1);
		if (!s)
			return (0);
		s = ft_set(s, n, len);
		s[len] = 0;
		ft_putstr(s);
		free(s);
		return (len);
	}
	return (0);
}
