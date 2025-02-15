/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_splitting.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:53:10 by marcgodel         #+#    #+#             */
/*   Updated: 2024/12/16 22:23:14 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORD_SPLITTING_H
# define WORD_SPLITTING_H

# include "structures.h"

t_list	*do_split_w_s(t_list *current, t_index ind);
t_list	*word_splitting(t_list *current, t_data *data);
t_list	*split_ifs(t_list *current, char *ifs_str);
t_list	*split_whitespace(t_list *current);

#endif
