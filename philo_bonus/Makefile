# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 12:04:59 by ninieddu          #+#    #+#              #
#    Updated: 2021/11/04 09:05:34 by ninieddu         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
RM = rm -rf

INCS_DIR = incs
VPATH = srcs
OBJS_DIR = objs

SRCS = $(wildcard $(VPATH)/*.c)
OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

clean :
	$(RM) $(OBJS_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -I $(INCS_DIR) $(OBJS) -o $@

.PHONY: all clean fclean re
