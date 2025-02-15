/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:52:30 by stripet           #+#    #+#             */
/*   Updated: 2024/11/29 14:07:19 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

# include "structures.h"

//prototype: tokenize.c
void	tokenize(t_data *data, t_status status, int quoted, t_index i);

//prototype: tokenize_utils.c
void	get_status(t_status *status, char c);
t_type	get_type(char *string, int cursor);
int		get_tstatus(char *string);

#endif
