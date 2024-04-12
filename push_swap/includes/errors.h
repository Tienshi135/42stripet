/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:20:20 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/12 11:11:12 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H
# include "../includes/structures.h"

enum	e_error{
	bad_args = 1,
	bad_lst = 2
};

void	msg(int code);
void	error(t_data *data);

#endif