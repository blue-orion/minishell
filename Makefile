# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/29 05:29:11 by takwak            #+#    #+#              #
#    Updated: 2024/12/29 05:48:13 by takwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAG = -g

OBJ_DIR = objs/
SRC_DIR = srcs/
INCLUDE = includes/
LIBFT = $(SRC_DIR)libft

SRCS = minishell.c

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $^ -I$(INCLUDE) -L$(LIBFT) -lreadline -o $@

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAG) -c $^ -I$(INCLUDE) -o $@

$(OBJ_DIR) :
	mkdir -p $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
