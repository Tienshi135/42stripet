/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:51:07 by stripet           #+#    #+#             */
/*   Updated: 2025/02/10 14:58:54 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain{
    private:
        std::string _ideas[100];
    public:
        Brain();
        ~Brain();
        Brain(const Brain &copy);
        Brain &operator=(const Brain &copy);
};