/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:36:47 by marcgodel         #+#    #+#             */
/*   Updated: 2024/12/21 12:58:52 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# define HEREDOC_TMP_NAME "here_doc_tmp_"

# include "structures.h"

//prototype heredoc.c
void	handle_heredoc(t_data *data, t_token *curr, char *delimiter);

#endif
