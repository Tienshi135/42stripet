/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:50:30 by tienshi           #+#    #+#             */
/*   Updated: 2025/04/15 16:22:00 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Contacts.hpp"

class PhoneBook
{

private:
	Contacts PB[8];

public:
	PhoneBook(void);//constructor
	~PhoneBook(void);//destructor
	void AddContact(void);
	void SearchContact(void) const;
};

#endif