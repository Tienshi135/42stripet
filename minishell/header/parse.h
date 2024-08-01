/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:50:37 by stripet           #+#    #+#             */
/*   Updated: 2024/07/26 18:14:34 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef enum e_status
{
	UNQUOTED,
	SINGLE_QUOTED,
	DOUBLE_QUOTED,
	ERROR
}	t_status;

int		count_tokken(char *input);
void	get_status(t_status *status, char c);

#endif