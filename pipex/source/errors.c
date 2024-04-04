/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:49:19 by stripet           #+#    #+#             */
/*   Updated: 2024/04/04 16:44:18 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/errors.h"
#include "../libft/libft.h"
#include <stdlib.h>

int	msg(t_data data, int err)
{
	if (err == open_err)
		perror("Error opening the input file ");
	else if (err == opencreat_err)
		perror("Error opening or creating the output file ");
	else if (err == pipe_err)
		perror("Error creating the pipe ");
	else if (err == fork_err)
		perror("Error forking ");
	else if (err == dup_err)
		perror("Error dupping fds ");
	else if (err == split_err)
		perror("Error during split ");
	else if (err == join_err)
		perror("Error durring join ");
	else if (err == cmd_err)
		perror("Error with cmd ");
	else if (err == badargs_err)
		ft_printf("Bad number of arguments expected 4");
	if (data.paths)
		free(data.paths);
	exit (err);
}
