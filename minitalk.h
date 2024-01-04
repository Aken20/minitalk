/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:28:20 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/04 22:15:27 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

void	ft_ascii2bin(int n, int pid);
int		ft_itoa(long long n);
int		ft_atoi(const char *str);
int		ft_putstr(char *s);
void	ft_recive(int sig);

#endif
