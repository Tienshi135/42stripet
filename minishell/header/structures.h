/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:45:06 by tienshi           #+#    #+#             */
/*   Updated: 2024/12/19 08:56:44 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "../libft/libft.h"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef enum e_type
{
	WORD,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_IN,
	REDIR_HERE_DOC,
	PIPE,
	OR,
	AND,
}	t_type;

typedef enum e_status
{
	UNQUOTED,
	SINGLE_QUOTED,
	DOUBLE_QUOTED,
}	t_status;

typedef struct s_token
{
	char		*value;
	t_type		type;
	t_status	status;
}	t_token;

typedef struct s_pipeline
{
	t_list	*segments;
	int		**pipes;
	int		num_pipe;
}	t_pipeline;

typedef struct s_data
{
	char		*hist_file;
	t_bool		run;
	char		*input;
	t_list		*tokens;
	t_list		*free_list;
	char		**envp;
	int			(*pid)[2];
	int			nb_pid;
	int			return_v;
	int			backup_fd[3];
	t_pipeline	*pipeline;
}	t_data;

typedef struct s_index
{
	int	i;
	int	j;
	int	start;
	int	end;
	int	cursor;
}	t_index;

typedef struct s_io
{
	char	*red_in;
	char	*red_out;
	char	*red_out_app;
	char	*heredoc_f;
	char	*heredoc_delimiter;
	t_bool	heredoc_quote;
	int		fd_in;
	int		fd_out;
	int		to_dup_in;
	int		to_dup_out;
	t_bool	is_error;
}	t_io;

typedef struct s_segment
{
	t_io	io;
	char	**argv;
	char	*cmd_path;
	t_bool	is_builtin;
	t_bool	prev_builtin;
}	t_segment;

#endif
