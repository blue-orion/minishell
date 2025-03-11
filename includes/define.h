/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:45:40 by takwak            #+#    #+#             */
/*   Updated: 2025/03/11 15:44:54 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define CMD_NOT_FOUND "command not found"
# define PERMISSION_DENIED "Permission denied"
# define NO_FILE_OR_DIR "No such file or directory"
# define IS_DIR "Is a directory"
# define NOT_A_DIR "Not a directory"
# define TOO_MANY_ARGS "too many arguments"
# define INVALID_IDENTIFIER "not a valid identifier"
# define NON_NUMERIC_ARGS "numeric argument required"
# define HOME_NOT_SET "HOME not set"
# define INPUT 1
# define OUTPUT 0
# define LEFT 0
# define RIGHT 1

enum e_unit
{
	SENTENSE = 1,
	SINGLE_QUOTE = '\'',
	DOUBLE_QUOTE = '\"',
	PARENTHESIS = '(',
	CMD = 2,
	FILE_NAME = 3,
	SEPARATOR = 4,
	REDIRECTS = 5,
	EMPTY = 6,
	SIMPLE_CMD = 8,
};

enum e_separator
{
	PIPE = 16,
	AND,
	OR,
	AMPER,
	SEMI
};

enum e_redirect
{
	IN = 32,
	OUT,
	HERE_DOC,
	APPEND
};
#endif
