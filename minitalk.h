/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aken <aken@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:28:20 by ahibrahi          #+#    #+#             */
/*   Updated: 2023/12/25 15:39:04 by aken             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H


# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <math.h>

void	ft_ascii2bin(int n, int pid);
int		ft_itoa(long long n);
int		ft_atoi(const char *str);
int		ft_putstr(char *s);
void	ft_recive(int sig);

#endif
