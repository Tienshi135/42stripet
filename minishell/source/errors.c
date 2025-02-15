/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 04:28:38 by tienshi           #+#    #+#             */
/*   Updated: 2024/12/23 01:54:05 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"
#include "../header/structures.h"
#include <stdio.h>

int	err_mess(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (1);
}

int	err_mess_2(char *str, char *str2)
{
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(" \"", STDERR_FILENO);
	ft_putstr_fd(str2, STDERR_FILENO);
	ft_putstr_fd(" \"", STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (1);
}

void	err_clean(t_data *data)
{
	clear_data(data);
	perror("minishell: ");
	exit (1);
}

void	exit_err(char *str, t_data *data)
{
	clear_data(data);
	ft_putstr_fd(str, STDERR_FILENO);
	exit (1);
}

void	err_token(char *str, t_data *data)
{
	ft_putstr_fd(str, STDERR_FILENO);
	ft_lstclear(&data->tokens, free_token);
}
