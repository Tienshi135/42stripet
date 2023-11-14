/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:05:22 by tienshi           #+#    #+#             */
/*   Updated: 2023/11/14 09:16:28 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fd;

    fd = open("./test.txt", O_RDONLY);
    ft_printf("%s\n", get_next_line(fd));
    return (0);
}