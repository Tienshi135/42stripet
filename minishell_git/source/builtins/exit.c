/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:47:37 by marcgodel         #+#    #+#             */
/*   Updated: 2024/10/18 14:19:16 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/builtins.h"

#define MAX_NUMBER_LONG 19

static int	ft_isstrlong(char *str)
{
	size_t	i;
	size_t	sign;

	i = 0;
	sign = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		sign = 1;
	}
	while (str[i] && i < MAX_NUMBER_LONG + sign)
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (i >= MAX_NUMBER_LONG + sign)
		return (0);
	return (1);
}

static long	ft_strtolong(char *str)
{
	size_t	i;
	int		neg_sign;
	long	number;
	long	temp;

	i = 0;
	neg_sign = 1;
	temp = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg_sign = -1;
		i++;
	}
	while (str[i])
	{
		number = (temp * 10) + (str[i] - 48);
		i++;
		temp = number;
	}
	return (number * neg_sign);
}

static void	error_message(char *arg, char *str)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(str, 2);
}

void	ft_exit(t_data *data, char **arguments)
{
	int		i;
	long	number;

	i = 0;
	number = 0;
	ft_putstr_fd("exit\n", 1);
	while (arguments[i])
		i++;
	if (i == 1)
		exit(0);
	if (i > 2)
	{
		error_message(arguments[1], ": too many arguments\n");
		return ;
	}
	if (ft_isstrlong(arguments[1]))
	{
		number = ft_strtolong(arguments[1]);
		clear_data(data);
		exit(number % 256);
	}
	error_message(arguments[1], ": numeric argument required\n");
	clear_data(data);
	exit(2);
}

// en interactif, cela va afficher la commande, "exit\n"
// si plus que 1 argument erreur:
//"minishell: exit: "too many arguments" en stderr (2)
// et il ne quitte pas !!!
// 
// si nombre plus grand q'un long, ou pas un nombre, alors:
// message d'erreur:
//"minishell: exit: argumentdonner: numeric argument required"
// dans ce cas, il quitte quand meme!!! code de sortie (2).
//
//
// operations:
// message exit:
// clean
// sortir avec code en argument % 256.
