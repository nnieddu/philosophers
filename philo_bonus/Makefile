# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 12:04:59 by ninieddu          #+#    #+#              #
#    Updated: 2021/11/06 10:58:35 by ninieddu         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
RM = rm -rf

INCS = incs/philo.h
VPATH = srcs

SRCS = srcs/init.c srcs/main.c srcs/philo.c srcs/utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

$(NAME) : $(OBJS) $(INCS)
	$(CC) $(CFLAGS) -I $(INCS) $(OBJS) -o $(NAME)

.PHONY: all clean fclean re
