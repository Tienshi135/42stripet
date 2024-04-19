/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:50:00 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/19 10:38:40 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include <stdlib.h>

typedef struct stack
{
	int				content;
	struct stack	*next;
	struct stack	*previous;
	int				index;
	int				sort_index;
	char			*moves;
}	t_stack;

typedef struct data {
	t_stack	*a;
	t_stack	*b;
	char	*list;
}	t_data;

#endif