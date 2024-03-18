/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:26:57 by stripet           #+#    #+#             */
/*   Updated: 2024/03/18 16:02:18 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

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