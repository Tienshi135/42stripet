/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:50:00 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/15 14:24:00 by stripet          ###   ########.fr       */
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
}	t_stack;

typedef struct data {
	t_stack	*a;
	t_stack	*b;
	char	*list;
}	t_data;

#endif