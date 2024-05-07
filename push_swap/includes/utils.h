/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:38:58 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/07 14:33:20 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../includes/structures.h"
# include "../includes/list_utils.h"
# include "../includes/sort_utils.h"

void	ps_lst_free(t_stack *tofree);
int		is_valid(t_data *data, char *str);
void	data_cleanup(t_data *data);
void	sort_init(t_data *data);
t_stack	*ps_lstcopy(t_stack *src);

#endif