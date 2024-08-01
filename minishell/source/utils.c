/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:23:04 by stripet           #+#    #+#             */
/*   Updated: 2024/07/28 10:45:15 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"
#include "../header/parse.h"

int	is_separator(char c, t_status status)
{
	// if (c == ' ' && status == UNQUOTED) add this one back for first version of parsing
	// 	return (1);
	if (c == '<' && status == UNQUOTED)
		return (1);
	if (c == '>' && status == UNQUOTED)
		return (1);
	if (c == '|' && status == UNQUOTED)
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

// int	parse(t_data *data)//for now only handle basic tokenization on < > << >> | and space
// {
// 	t_status	status;
// 	int			i;
// 	int			cursor;

// 	i = 0;
// 	cursor = 0;
// 	status = UNQUOTED;
// 	while (i <= (int) ft_strlen(data->input))
// 	{
// 		get_status(&status, data->input[i]);
// 		printf("Status : %d\n", status);//debug
// 		if (is_separator(data->input[i], status) || !data->input[i])
// 		{
// 			ft_lstadd_back(&data->tokens, ft_lstnew(ft_substr(data->input, cursor, i - cursor)));
// 			if (data->input[i] && data->input[i] != ' ')
// 			{
// 				if (is_separator(data->input[i + 1], status)
// 					&& data->input[i] == data->input[i + 1])
// 					ft_lstadd_back(&data->tokens, ft_lstnew(ft_substr(data->input, i++, 2)));
// 				else
// 					ft_lstadd_back(&data->tokens, ft_lstnew(ft_substr(data->input, i, 1)));
// 			}
// 			cursor = i + 1;
// 		}
// 		i++;
// 	}
// 	print_tokens(data->tokens);
// 	return (0);
// }

char	**argv_extract(char *input, int i, int cursor)
{
	char	**r_val;
	char	*buffer;

	buffer = ft_substr(input, cursor, i - cursor);
	r_val = ft_split(buffer, ' ');
	free(buffer);
	return (r_val);
}
char	*separator_extract(char *input, int *i)//mallocs if !null
{
	int	cursor;

	cursor = *i;
	if (!input[cursor])//not to protect against crash but in case of EOS
		return (NULL);
	if (input[cursor] == input[cursor + 1]
		&& (input[cursor] == '<' || input[cursor] == '>'))
		return (ft_substr(input, cursor, ++*i - cursor + 1));
	return (ft_substr(input, *i, 1));
}

void	parse(t_data *data)//list being on commands rather than tokens
{
	t_status	status;
	t_command	*node;
	char		*buffer;
	int			i;
	int			cursor;

	i = 0;
	status = UNQUOTED;
	buffer = NULL;
	while (data->input[i])//review separator logic + get_status calls have to chance place
	{
		node = ft_calloc(1, sizeof(t_command));
		cursor = i;
		get_status(&status, data->input[i]);
		while (!is_separator(data->input[i], status))//need buffer to be initialized to null, logic : until separator first cmd then arg if separator first, NULL to signal nothing
			get_status(&status, data->input[i++]);
		buffer = separator_extract(data->input, &i);
		node->argv = argv_extract(data->input, i, cursor);
		node->separator = buffer;
		ft_lstadd_back(&data->tokens, ft_lstnew(node));
		i++;
	}
}

int	is_builtin(t_command *command)
{
	if (ft_strncmp(command->argv[0], "exit", 5) == 0)
		return (1);
	if (ft_strncmp(command->argv[0], "cd", 3) == 0)
		return (1);
	if (ft_strncmp(command->argv[0], "pwd", 4) == 0)
		return (1);
	if (ft_strncmp(command->argv[0], "export", 7) == 0)
		return (1);
	if (ft_strncmp(command->argv[0], "unset", 6) == 0)
		return (1);
	if (ft_strncmp(command->argv[0], "env", 4) == 0)
		return (1);
	if (ft_strncmp(command->argv[0], "echo", 5) == 0)
		return (1);
	return (0);
}

void	pwd(void)
{
	char	*buffer;

	buffer = getcwd(NULL, 0);
	printf("%s\n", buffer);
	free(buffer);
}
void	echo(t_command *command)
{
	int	i;

	i = 1;
	while (command->argv[i])
	{
		if (ft_strncmp(command->argv[i], "-n", 3) == 0)
		{
			i++;
			continue ;
		}
		printf("%s", command->argv[i]);
		if (command->argv[i + 1])
			printf(" ");
		i++;
	}
	if (ft_strncmp(command->argv[1], "-n", 3) != 0)
		printf("\n");
}

void	cd(t_command *command)
{
	if (command->argv[2])
	{
		printf("cd: too many arguments\n");
		return ;
	}
	if (chdir(command->argv[1]) == -1)
	{
		printf("cd: %s: No such file or directory\n", command->argv[1]);
	}
}

// void	env(t_command *command)
// {
// 	wtf does env even do
// }

int	execute_builtin(t_data *data, t_command *command)
{
	if (ft_strncmp(command->argv[0], "echo", 5) == 0)
		echo(command);
	else if (ft_strncmp(command->argv[0], "cd", 3) == 0)
		cd(command);
	else if (ft_strncmp(command->argv[0], "pwd", 4) == 0)
		pwd();
	// else if (ft_strncmp(command->argv[0], "export", 7) == 0)
	// 	;
	// else if (ft_strncmp(command->argv[0], "unset", 6) == 0)
	// 	;
	// else if (ft_strncmp(command->argv[0], "env", 4) == 0)
	// 	env(command);
	else if (ft_strncmp(command->argv[0], "exit", 5) == 0)
		data->run = false;
	else
		return (0);
	return (1);
}

char	*findpath(char *cmd)
{
	char	**paths;
	char	*path;
	int		i;

	if (!cmd)
		return (NULL);
	i = 0;
	cmd = ft_strjoin("/", cmd);
	paths = ft_split(getenv("PATH"), ':');
	while (paths[i])
	{
		path = ft_strjoin(paths[i], cmd);
		if (access(path, X_OK) == 0)
		{
			free(cmd);
			ft_split_free(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free(cmd);
	ft_split_free(paths);
	return (NULL);
}

void	execute_command(t_command *command)
{
	char	*path;
	int		pid;

	path = findpath(command->argv[0]);
	if (!path)
	{
		printf("minishell: %s: command not found\n", command->argv[0]);
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		execve(path, command->argv, NULL);
		perror("execve");
		exit(0);
	}
	waitpid(pid, NULL, 0);
	free(path);
}

void	execute(t_data *data)
{
	t_list		*tmp;

	tmp = data->tokens;
	while (tmp)
	{
		if (!execute_builtin(data, tmp->content))
			execute_command(tmp->content);
		tmp = tmp->next;
	}
}
