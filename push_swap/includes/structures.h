/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:50:00 by tienshi           #+#    #+#             */
/*   Updated: 2024/04/24 11:40:40 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct stack
{
	int				content;
	struct stack	*next;
	struct stack	*previous;
	char			*movesA;
    char            *movesB;
}	t_stack;

typedef struct data {
	t_stack	*a;
	t_stack	*b;
	char	*list;
	int		biggest;
	int		smallest;
}	t_data;

#endif