NAME = minishell

CC = cc
CFLAG = -g

OBJ_DIR = objs/
SRC_DIR = srcs/
INCLUDE = includes/
LIBFT = $(SRC_DIR)libft

SRCS = minishell.c	\
	   parsing/find_metachar.c	\
	   parsing/find_separator.c	\
	   parsing/find_redirection.c	\
	   parsing/is_metachar.c	\
	   parsing/is_redirection.c	\
	   parsing/is_separator.c	\
	   parsing/make_data.c		\
	   parsing/make_parsing_tree.c	\
	   parsing/parse_node.c		\
	   parsing/parsing.c		\
	   parsing/remove_invalid_quote.c	\
	   parsing/sentense_preprocess.c	\
	   parsing/split_cmd_node.c		\
	   parsing/split_piece.c		\
	   parsing/subsitute_tab.c		\
	   parsing/unit_block.c			\
	   parsing/which_separator.c		\
	   tree/add_node.c				\
	   tree/new_node.c			\
	   tree/print_tree.c			\
	   utils/print_list.c		\
	   utils/free_pptr.c		\

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
