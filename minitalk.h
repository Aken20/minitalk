/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aken <aken@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:28:20 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/12/01 21:25:17 by aken             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <math.h>

# ifndef S_TIME
#  define S_TIME 5000
# endif

void	ft_ascii2bin(int n, int pid);
void	ft_bin2ascii(int s);
int		ft_itoa(long long n);
int		ft_atoi(const char *str);

#endif