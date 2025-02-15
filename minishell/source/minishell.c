/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:45:37 by tienshi           #+#    #+#             */
/*   Updated: 2025/01/07 13:59:41 by mgodel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header/minishell.h"
#include "../header/tokenize.h"
#include "../header/ft_signal.h"
#include "../header/expansions.h"
#include "../header/structures.h"
#include "../header/utils.h"
#include "../header/environ.h"
#include "../header/execute.h"
#include "../header/history.h"
#include "../header/segment.h"
#include "../header/parsing.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>

void	handle_stop(t_data *data)
{
	write(STDOUT_FILENO, "exit\n", 5);
	clear_data(data);
	enable_echoctl();
	rl_clear_history();
	exit(data->return_v);
}

static int	is_empty_line(const char *input)
{
	if (!input)
		return (1);
	while (*input != '\0' && isspace(*input))
		input++;
	if (*input == '\0')
		return (1);
	else
		return (0);
}

static void	work_with_input(t_data *data)
{
	t_index	i;

	ft_bzero(&i, sizeof(t_index));
	handle_incomplete_cmd(&data->input, data);
	if (g_sig != SIGINT)
	{
		add_history(data->input);
		update_history_file(data->input, data);
		tokenize(data, UNQUOTED, 0, i);
		expansion(data);
		if (pars_token(data) == 0)
		{
			creat_segment(data);
			if (g_sig == 0)
				execute(data);
		}
	}
	free_for_continue(data);
}

static void	run_readline(t_data *data)
{
	while (data->run)
	{
		if (g_sig != SIGINT)
		{
			g_sig = 0;
			data->input = readline("minishell$ ");
		}
		else
		{
			g_sig = 0;
			rl_on_new_line();
			rl_replace_line("", 1);
			printf("\n");
			data->input = readline("minishell$ ");
		}
		if (!data->input)
			handle_stop(data);
		if (is_empty_line(data->input) == 0 && g_sig == 0)
			work_with_input(data);
		if (data->input)
			free(data->input);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	(void)argc;
	(void)argv;
	signal_setup();
	init_env(&data, env);
	data.run = true;
	update_history(&data);
	disable_echoctl();
	run_readline(&data);
	return (0);
}
