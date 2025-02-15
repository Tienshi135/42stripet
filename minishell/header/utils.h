/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:22:45 by stripet           #+#    #+#             */
/*   Updated: 2025/01/06 20:20:31 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structures.h"

//prototype: utils.c
int		is_metachara(char c);
int		is_separator(char c);
int		has_red(t_data *data);
int		is_incomplete_cmd(const char *str);
char	*safe_ft_strjoin(char *str1, char *str2, t_data *data);

// to delete in utils.c   to delete_-------________
void	print_lst(t_list *lst); //delete
// to delete

int		has_red(t_data *data);
void	delete_env_last_command(t_data *data);

// prototype: get_command_args.c
char	**get_command_args(t_list *command, t_data *data);

// prototype: free_utils.c
void	free_tab(char **tab);
void	ms_lstdelone(t_list **lst, t_list *to_free);
void	free_pipe(int **pipes, int num_pipe);
void	clear_data(t_data *data);

// prototype: free_utils_2.c
void	free_token(void *to_free);
void	free_for_continue(t_data *data);
void	clean_heredoc(char *heredoc_f);

// prototype: utils_2.c
void	enable_echoctl(void);
void	disable_echoctl(void);
int		string_cmp(char *str1, char *str2);
int		is_redir_type(t_type type);
void	check_builtin_segment(t_list *seg_list);

// prototype free_pipeline.c
void	free_pipeline(t_pipeline *pipeline);

#endif
