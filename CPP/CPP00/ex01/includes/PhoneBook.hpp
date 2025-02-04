/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:50:30 by tienshi           #+#    #+#             */
/*   Updated: 2024/11/30 12:41:41 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
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