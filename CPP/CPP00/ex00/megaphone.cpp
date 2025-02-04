/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:42:04 by tienshi           #+#    #+#             */
/*   Updated: 2024/11/26 18:00:51 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	std::string input;
	int			i;

	i = 0;
	if (argc > 1)
	{
		for (i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				input += toupper(argv[i][j]);
			if (i + 1 < argc)
				input += " ";
		}
		std::cout << input << std::endl;
		return (0);
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (1);
}