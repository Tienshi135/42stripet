/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:24:33 by marcgodel         #+#    #+#             */
/*   Updated: 2024/12/22 21:39:14 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

void	print_tab_str(char **str);
void	print_segment(t_segment *seg, int i);
void	print_list_seg(t_list *segments);
void	print_lst(t_list *lst);

#endif
