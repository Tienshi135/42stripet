/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:45:37 by tienshi           #+#    #+#             */
/*   Updated: 2024/07/27 14:57:21 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"
#include "../header/utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>


//all of this to delete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat_strings(char **strings) {
    // Calculate total length
    int total_length = 0;
    for (int i = 0; strings[i] != NULL; i++) {
        total_length += strlen(strings[i]);
    }
    total_length += 1; // Add space for null terminator

    // Allocate memory for the concatenated string
    char *result = (char *)malloc(total_length * sizeof(char));
    if (result == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Copy strings into the result
    result[0] = '\0'; // Initialize the result string
    for (int i = 0; strings[i] != NULL; i++) {
        strcat(result, strings[i]);
    }

    return result;
}

void	print_tokens(t_list *tokens)
{
	t_list		*tmp;
	t_command	*buffer;
	char		*string;

	tmp = tokens;
	while (tmp)
	{
		buffer = tmp->content;
		string = concat_strings(buffer->argv);
		printf("Token : %s, Separator : %s\n", string, buffer->separator);
		free(string);
		tmp = tmp->next;
	}
}

//until here

void	command_free(void *content)
{
	t_command	*node;

	node = content;
	if (node->separator)
		free(node->separator);
	if (node->argv)
		ft_split_free(node->argv);
	free(node);
}

void	clean_exit(t_data *data)
{
	free(data->input);
	ft_lstclear(&data->tokens, command_free);
}

int	main(void)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	data.run = true;
	while (data.run)
	{
		free(data.input);
		ft_lstclear(&data.tokens, command_free);
		data.input = readline("minishell$ ");
		printf("Input before parsing : %s\n", data.input);//debug
		parse(&data);
		print_tokens(data.tokens);//debug
		execute(&data);
	}
	clean_exit(&data);
	return (0);
}
