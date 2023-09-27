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

SRCS = ./srcs/read_arg.c $(SRCS_SOLVE_BF) $(SRCS_GEN) $(SRCS_LIBS)

SRCS_GEN = ./srcs/generator_main.c ./srcs/generate.c ./srcs/grid_tools.c $(SRCS_GEN_DFS)
SRCS_GEN_DFS = ./srcs/generating/dfs_gen.c

SRCS_SOLVE_A = ./srcs/solving/A/a_solve.c
SRCS_SOLVE_BF = ./srcs/solving/breadth_first/bf_solve.c

SRCS_LIBS = ./srcs/libs/lib.c ./srcs/libs/lists.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
OBJS=$(SRCS:.c=.o)
OBJS_GEN=$(SRCS_GEN:.c=.o)
NAME = maze_solver
NAME_GEN = maze_generator
HEADER_DIR    = ./includes/

all: $(NAME)

generator: gen

%.o : %.c $(HEADER_DIR)ft.h
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