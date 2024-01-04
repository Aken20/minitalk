# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 04:39:30 by ahibrahi          #+#    #+#              #
#    Updated: 2023/12/30 10:36:34 by ahibrahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = client
NAME2 = server
NAMEB = client_bonus
NAMEB2 = server_bonus

SRCSS = ft_server.c utility.c
SRCSC = ft_client.c utility.c

BSRCSS = ft_server_b.c utility.c
BSRCSC = ft_client_b.c utility.c

OBJSS = $(SRCSS:.c=.o)
OBJSC = $(SRCSC:.c=.o)
BOBJSS = $(BSRCSS:.c=.o)
BOBJSC = $(BSRCSC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) $(NAME2)

$(NAME): $(OBJSC)
	$(CC) $(CFLAGS) $(OBJSC) -o $(NAME)

$(NAME2): $(OBJSS)
	$(CC) $(CFLAGS) $(OBJSS) -o $(NAME2)	

bonus: $(NAMEB) $(NAMEB2)

$(NAMEB): $(BOBJSC)
	$(CC) $(CFLAGS) $(BOBJSC) -o $(NAMEB)

$(NAMEB2): $(BOBJSS)
	$(CC) $(CFLAGS) $(BOBJSS) -o $(NAMEB2)

clean:
	$(RM) $(OBJSS) $(OBJSC) $(BOBJSS) $(BOBJSC)

fclean: clean
	$(RM) $(NAME) $(NAME2) $(NAMEB) $(NAMEB2)

re: clean all

.PHONY: all clean fclean re bonus