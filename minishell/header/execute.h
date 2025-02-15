/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:50:25 by stripet           #+#    #+#             */
/*   Updated: 2025/01/08 11:14:35 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "structures.h"

//prototype: execute.c
void	handle_pipe(t_data *data, int i, t_io io);
void	execute(t_data *data);

//prototype: execute_utils.c
int		findpath(char *cmd, t_segment *segment, t_data *data);
int		is_executable(char *cmd_path);

//prototype: redirections.c
int		red(t_io *io);

//prototype: redirections_utils.c
void	save_fd(int *backup_fd);
void	restore_fd(int *backup_fd);
void	backup_std_fd(int *backup_fd);

//prototype: redirection_access.c
int		check_access_redir_in(const char *file);
int		check_access_redir_output(const char *file);

//prototype: pipes.c
int		has_pipe(t_list *lst);
void	child_process(t_data *data);
int		pipex_exec(t_data *data);
int		count_pipe(t_list *lst);
void	creat_pipe(t_data *data, t_pipeline *pipeline);

//prototype: pipe_utils.c
void	close_child_pipe(t_data *data, int current_cmd, t_bool prev_builtin);
void	close_rest_pipe(t_data *data, int current_cmd);
void	close_all_pipe(t_data *data, int num_pipe);
void	close_used_pipe(t_data *data, int curr_cmd);

//prototype: wait_process.c
void	wait_process(t_data *data);
void	wait_heredoc(t_data *data, int pid);

//prototype: execute_script.c
void	execute_script(t_segment *segment, t_data *data);

#endif
