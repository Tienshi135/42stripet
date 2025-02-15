/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:30:39 by marcgodel         #+#    #+#             */
/*   Updated: 2024/12/27 20:15:19 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/builtins.h"

/*some bash display an error if  there is argument, some other no*/
int	ft_pwd(char **arguments)
{
	char	*buffer;

	(void)arguments;
	buffer = getcwd(NULL, 0);
	if (buffer == NULL)
		return (1);
	ft_printf("%s\n", buffer);
	free(buffer);
	return (0);
}
