/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:36:34 by marcgodel         #+#    #+#             */
/*   Updated: 2024/11/29 13:38:04 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

// Prototype: history.c
void	update_history(t_data *data);
void	update_history_file(char *command, t_data *data);

#endif
