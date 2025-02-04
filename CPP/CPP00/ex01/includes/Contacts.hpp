/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:50:33 by tienshi           #+#    #+#             */
/*   Updated: 2024/11/30 13:10:29 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#include <iostream>

class Contacts
{

private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	bool initialized;

public:
	Contacts(void);//constructor
	~Contacts(void);//destructor
	bool isInit(void) const;
	void setFirstName(std::string input);
	void setLastName(std::string input);
	void setNickname(std::string input);
	void setPhoneNumber(std::string input);
	void setDarkestSecret(std::string input);
	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickname(void) const;
	std::string getPhoneNumber(void) const;
	std::string getDarkestSecret(void) const;
};
#endif