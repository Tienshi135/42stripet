/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:49:41 by stripet           #+#    #+#             */
/*   Updated: 2024/03/20 13:15:48 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <stdio.h>
# include "structures.h"

enum	e_errors{
	opencreat_err = -1,
	pipe_err = -2,
	open_err = -3,
	fork_err = -4,
	dup_err = -5,
	split_err = -6,
	join_err = -7,
	badargs_err = -8,
	cmd_err = -9
};

int	msg(t_data data, int err);

#endif