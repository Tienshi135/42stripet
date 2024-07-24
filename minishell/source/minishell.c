/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:45:37 by tienshi           #+#    #+#             */
/*   Updated: 2024/07/24 12:58:36 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"
#include "../header/utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(void)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	data.run = true;
	while (data.run)
	{
		free(data.input);
		ft_lstclear(&data.tokens, free);
		data.input = readline("minishell$ ");
		if (ft_strncmp(data.input, "exit", 4) == 0)
			exit(0);
		printf("Input before parsing : %s\n", data.input);
		parse(&data);
	}
	return (0);
}
