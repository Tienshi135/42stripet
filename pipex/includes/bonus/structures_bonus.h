/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:26:57 by stripet           #+#    #+#             */
/*   Updated: 2024/03/20 15:54:04 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_BONUS_H
# define STRUCTURES_BONUS_H

typedef struct s_data{
	int		input;
	int		output;
	int		pipe[2];
	int		id1;
	int		id2;
	char	*paths;
	int		rval;
}	t_data;

#endif