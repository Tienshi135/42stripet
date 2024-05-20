/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:28:30 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/16 17:46:07 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int main(int argc, char **argv, char **envp)
{
    if (argc < 5 || argc > 6)
        return (error(bad_args));
    if (argc == 5)
        return (4);
    if (argc == 6)
        return (5);
    if (argv && envp)
        return (1);
    return (0);
}