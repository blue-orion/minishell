NAME = minishell

CC = cc
CFLAG = -g

OBJ_DIR = objs/
SRC_DIR = srcs/
INCLUDE = includes/
LIBFT = $(SRC_DIR)libft

SRCS = minishell.c	\
	   builtin/ft_cd.c	\
	   builtin/ft_echo.c	\
	   builtin/ft_env.c	\
	   builtin/ft_exit.c	\
	   builtin/ft_export.c	\
	   builtin/ft_pwd.c		\
	   builtin/ft_unset.c		\
	   builtin/getsize.c		\
	   exec/call_builtin_ft.c	\
	   exec/call_execve.c		\
	   exec/command_execve_process.c	\
	   exec/exec_command.c		\
	   exec/exec_tree_node.c	\
	   exec/execve_fail.c		\
	   exec/fork_childs.c		\
	   exec/here_doc.c			\
	   exec/init_info.c			\
		 exec/interpret_wildcard.c	\
	   exec/is_builtin_command.c	\
	   exec/is_builtin_node.c	\
	   exec/list_to_str.c		\
	   exec/logical_separator_process.c	\
	   exec/make_child_process.c	\
	   exec/parenthesis_process.c	\
	   exec/pipe_separator_process.c	\
	   exec/redirect_pipe.c	\
	   exec/redirection_process.c	\
	   exec/separator_process.c	\
	   exec/simple_separator_process.c	\
	   parsing/find_metachar.c	\
	   parsing/find_separator.c	\
	   parsing/find_redirection.c	\
	   parsing/find_token.c		\
	   parsing/ft_getenv.c	\
	   parsing/interpret_env.c	\
	   parsing/is_metachar.c	\
	   parsing/is_redirection.c	\
	   parsing/is_separator.c	\
	   parsing/make_data.c		\
	   parsing/make_list_and_addback.c	\
	   parsing/make_parsing_tree.c	\
	   parsing/make_redirection_list.c	\
	   parsing/make_redirects_list.c	\
	   parsing/make_simple_cmd_list.c		\
	   parsing/move_to_token.c	\
	   parsing/is_type.c		\
	   parsing/parse_node.c		\
	   parsing/parse_node_utils.c	\
	   parsing/parsing.c		\
	   parsing/preprocess_string.c	\
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
	   utils/add_newline.c		\
	   utils/copy_envp.c		\
	   utils/error_exit.c		\
	   utils/free_data.c		\
	   utils/free_pptr.c		\
		 utils/ft_join_free.c	\
	   utils/make_history.c		\
	   utils/print_list.c		\
	   utils/put_error_msg.c	\
	   utils/skip_space.c		\
	   utils/ft_free_resource.c

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
