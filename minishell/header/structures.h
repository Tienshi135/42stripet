/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:45:06 by tienshi           #+#    #+#             */
/*   Updated: 2024/07/26 18:41:49 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "../libft/libft.h"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_command
{
	char	*separator;
	int		argc;
	char	**argv;
}	t_command;

typedef struct s_data
{
	t_bool	run;
	char	*input;
	t_list	*tokens;
}	t_data;

#endif