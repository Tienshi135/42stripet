/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:38:58 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/10 16:20:45 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../includes/structures.h"
# include "../libft/libft.h"
# include "../includes/list_utils.h"

int		ps_lstsize(t_stack *stack);
void	ps_lst_free(t_stack *tofree);
int		is_valid(t_data *data, char *str);
void	data_cleanup(t_data data);

#endif