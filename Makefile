# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 04:39:30 by ahibrahi          #+#    #+#              #
#    Updated: 2023/12/25 21:46:18 by ahibrahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CFILES = ft_client utilitys \

SFILES = ft_server utilitys \

B_CFILES = ft_client_bonus utilitys \

B_SFILES = ft_server_bonus utilitys \

CSRCS = $(addsuffix .c, $(CFILES))

SSRCS = $(addsuffix .c, $(SFILES))

B_CSRCS = $(addsuffix .c, $(B_CFILES))

B_SSRCS = $(addsuffix .c, $(B_SFILES))


all: client server

bonus: client_bonus server_bonus

client: $(CSRCS)
	$(CC) $(CFLAGS) $(CSRCS) -o client

server: $(SSRCS)
	$(CC) $(CFLAGS) $(SSRCS) -o server

client_bonus: $(B_CSRCS)
	$(CC) $(CFLAGS) $(B_CSRCS) -o client_bonus

server_bonus: $(B_SSRCS)
	$(CC) $(CFLAGS) $(B_SSRCS) -o server_bonus

clean:
	$(RM) client server

fclean:
	$(RM) client server client_bonus server_bonus

re: clean all

.PHONY: all clean fclean re bonus