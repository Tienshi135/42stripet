/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:50:00 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/13 13:04:28 by stripet          ###   ########.fr       */
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

typedef struct stack {
	int				content;
	struct stack	*next;
	struct stack	*previous;
	int				index;
	int				position;
	int				target_position;
	int				cost_a;
	int				cost_b;
}	t_stack;

typedef struct data {
	t_stack	*a;
	t_stack	*b;
	char	*list;
}	t_data;

#endif