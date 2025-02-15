/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:41:09 by stripet           #+#    #+#             */
/*   Updated: 2024/12/20 08:48:04 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils.h"
#include <stdio.h>
#include <readline/history.h>

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_pipe(int **pipes, int num_pipe)
{
	int	i;

	i = 0;
	while (i < num_pipe)
	{
		free(pipes[i]);
		i++;
	}
	if (num_pipe != 0)
		free(pipes);
}

void	ms_lstdelone(t_list **lst, t_list *to_free)
{
	t_list	*cursor;

	if (!lst || !to_free)
		return ;
	cursor = *lst;
	if (cursor == to_free)
	{
		*lst = cursor->next;
		if (*lst)
			(*lst)->previous = NULL;
		ft_lstdelone(to_free, free_token);
		return ;
	}
	while (cursor->next != to_free)
		cursor = cursor->next;
	cursor->next = to_free->next;
	if (to_free->next)
		to_free->next->previous = cursor;
	ft_lstdelone(to_free, free_token);
}

void	clear_data(t_data *data)
{
	clear_history();
	enable_echoctl();
	if (data->pipeline)
		free_pipeline(data->pipeline);
	ft_lstclear(&data->tokens, free_token);
	free_tab(data->envp);
	ft_lstclear(&data->free_list, free);
	if (data->hist_file)
		free(data->hist_file);
}
