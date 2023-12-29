# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aken <aken@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 04:39:30 by ahibrahi          #+#    #+#              #
#    Updated: 2023/12/29 08:37:01 by aken             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra #-Werror
RM = rm -rf

NAME = Minitalk

SRCSS = ft_server.c utility.c
SRCSC = ft_client.c utility.c

BSRCSS = ft_server_b.c utility.c
BSRCSC = ft_client_b.c utility.c

OBJSS = $(SRCSS:.c=.o)
OBJSC = $(SRCSC:.c=.o)
BOBJSS = $(BSRCSS:.c=.o)
BOBJSC = $(BSRCSC:.c=.o)

%.o: %.c

all: $(NAME)

$(NAME): $(OBJSS) $(OBJSC)
	$(CC) $(CFLAGS) $(OBJSS) -o server -lm
	$(CC) $(CFLAGS) $(OBJSC) -o client

bonus: $(BOBJSS) $(BOBJSC)
	$(CC) $(CFLAGS) $(BOBJSS) -o server_bonus -lm
	$(CC) $(CFLAGS) $(BOBJSC) -o client_bonus

clean:
	$(RM) $(OBJSS) $(OBJSC) $(BOBJSS) $(BOBJSC)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus