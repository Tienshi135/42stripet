/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:38:58 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/05 09:43:49 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../includes/structures.h"
# include "../libft/libft.h"

t_stack	*ps_lstnew(int value);
void	ps_lstadd_back(t_stack **lst, t_stack *new);
int		ps_lstsize(t_stack *stack);
void	ps_lst_free(t_stack *tofree);
t_stack	*ps_lstlast(t_stack *lst);
int		pa(t_stack a, t_stack b);
int		pb(t_stack a, t_stack b);

#endif