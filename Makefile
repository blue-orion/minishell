NAME = minishell

CC = cc
CFLAG = -g

OBJ_DIR = objs/
SRC_DIR = srcs/
INCLUDE = includes/
LIBFT = $(SRC_DIR)libft

# exec/exec_parsing_tree.c	
# exec/list_to_str.c		
SRCS = minishell.c	\
	   builtin/cd.c	\
	   builtin/echo.c	\
	   builtin/env.c	\
	   builtin/exit.c	\
	   builtin/export.c	\
	   builtin/pwd.c		\
	   builtin/unset.c		\
	   parsing/find_metachar.c	\
	   parsing/find_separator.c	\
	   parsing/find_redirection.c	\
	   parsing/find_token.c		\
	   parsing/is_metachar.c	\
	   parsing/is_redirection.c	\
	   parsing/is_separator.c	\
	   parsing/make_data.c		\
	   parsing/make_list_and_addback.c	\
	   parsing/make_parsing_tree.c	\
	   parsing/make_redirection_list.c	\
	   parsing/make_redirects_list.c	\
	   parsing/make_simple_cmd_data.c		\
	   parsing/move_to_token.c	\
	   parsing/is_type.c		\
	   parsing/parse_node.c		\
	   parsing/parse_node_utils.c	\
	   parsing/parsing.c		\
	   parsing/remove_invalid_quote.c	\
	   parsing/split_sentense_to_list.c	\
	   parsing/split_cmd_node.c		\
	   parsing/split_piece.c		\
	   parsing/split_redirects_node.c	\
	   parsing/subsitute_tab.c		\
	   parsing/unit_block.c			\
	   parsing/which_separator.c		\
	   signal/handler_sigint.c			\
	   signal/signal_setup.c		\
	   tree/add_node.c				\
	   tree/new_node.c			\
	   tree/print_tree.c			\
	   tree/treeclear.c		\
	   utils/free_pptr.c		\
	   utils/print_list.c		\
	   utils/skip_space.c		\
	   utils/error_exit.c		\
	   utils/free_data.c		

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
OBJ_SUBDIRS = $(sort $(dir $(OBJS)))

all : $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) -s -C $(LIBFT)
	$(CC) $(CFLAG) -I$(INCLUDE) $^ -L$(LIBFT) -lft -lreadline -o $@

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_SUBDIRS)
	$(CC) $(CFLAG) -I$(INCLUDE) -c $^ -o $@

$(OBJ_SUBDIRS) :
	mkdir -p $@

clean :
	@$(MAKE) -s -C $(LIBFT) clean
	@rm -rf $(OBJ_DIR)

fclean : clean
	@$(MAKE) -s -C $(LIBFT) fclean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
