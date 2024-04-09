/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:50:00 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/09 09:27:33 by tienshi          ###   ########.fr       */
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
}	t_stack;

typedef struct data {
	t_stack	*a;
	t_stack	*b;
}	t_data;

#endif