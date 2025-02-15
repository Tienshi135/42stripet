/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:24:20 by marcgodel         #+#    #+#             */
/*   Updated: 2024/12/13 09:51:37 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEGMENT_H
# define SEGMENT_H

# include "structures.h"

//prototype segment.c
void	creat_segment(t_data *data);

//prototype segment_utils.c
int		handle_redir_out(t_data *data, t_io *io, char *f_name,
			char *value);
int		handle_redir_append(t_data *data, t_io *io, char *f_name,
			char *value);
int		handle_redir_in(t_data *data, t_io *io, char *f_name,
			char *value);
int		handle_redir_heredoc(t_data *data, t_io *io, char *f_name);

#endif
