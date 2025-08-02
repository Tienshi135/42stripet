/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:24:12 by stripet           #+#    #+#             */
/*   Updated: 2025/08/02 11:56:19 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief frees a double pointer
/// @param void** pointer to free
void	ft_table_free(void **tofree)
{
	char	**p;
	size_t	i;

	i = 0;
	p = (char **) tofree;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
}
