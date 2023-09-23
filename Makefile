# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 13:19:11 by panger           #+#    #+#              #
#    Updated: 2023/08/24 13:41:27 by panger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./srcs/main.c ./srcs/read_arg.c
SRCS_GEN = ./srcs/generator_main.c ./srcs/lib.c ./srcs/generate.c ./srcs/grid_tools.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
OBJS=$(SRCS:.c=.o)
OBJS_GEN=$(SRCS_GEN:.c=.o)
NAME = maze_solver
NAME_GEN = maze_generator
HEADER_DIR    = includes/

generator: gen

all: $(NAME)

%.o : %.c $(HEADER_DIR)ft.h $(HEADER_DIR)ft_gen.h
	$(CC) -c $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

gen: $(OBJS_GEN)
	$(CC) $(CFLAGS) -o $(NAME_GEN) $(OBJS_GEN)

clean:
	rm -f $(OBJS) $(OBJS_GEN)

fclean: clean 
	rm -f $(NAME) $(NAME_GEN)

re: fclean $(NAME)

.PHONY:  all clean fclean re