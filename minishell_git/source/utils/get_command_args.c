/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:59:50 by marcgodel         #+#    #+#             */
/*   Updated: 2025/01/07 11:24:04 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../header/utils.h"
#include "../../header/errors.h"
#include <unistd.h>

static int	parse_empty_tok(t_token *token)
{
	if (!token->value)
		return (1);
	else if (token->value[0] == '\0' && token->status == UNQUOTED)
		return (1);
	return (0);
}

static int	get_size_of_args(t_list *command)
{
	int	i;

	i = 0;
	while (command && ((t_token *)command->content)->type == WORD)
	{
		if (parse_empty_tok((t_token *)command->content) == 0)
			i++;
		command = command->next;
	}
	return (i);
}

char	**get_command_args(t_list *command, t_data *data)
{
	t_token	*current;
	char	**argv;
	int		i;

	i = get_size_of_args(command);
	argv = malloc(sizeof(char *) * (i + 1));
	if (!argv)
		exit_err("malloc", data);
	i = 0;
	while (command && ((t_token *)command->content)->type == WORD)
	{
		if (parse_empty_tok((t_token *)command->content) == 0)
		{
			current = command->content;
			argv[i] = ft_strdup(current->value);
			i++;
		}
		command = command->next;
	}
	argv[i] = NULL;
	return (argv);
}
