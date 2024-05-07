/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:50:00 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/07 15:12:42 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include <stdlib.h>
# include "../libft/libft.h"

enum	e_bool
{
	false,
	true
};

typedef struct stack
{
	int				content;
	struct stack	*next;
	struct stack	*previous;
	char			*movesa;
	char			*movesb;
}	t_stack;

typedef struct data {
	t_stack	*a;
	t_stack	*b;
	t_stack	*dupa;
	t_stack	*dupb;
	char	*list;
	char	*moves_left;
}	t_data;

#endif