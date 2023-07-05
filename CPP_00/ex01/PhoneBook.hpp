/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:44:16 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/05 16:44:18 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <sstream>
# include <cstdlib>
# include <string>
# include <iomanip>
# include <limits>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact		_contacts[8];
	bool		_validIndex(std::string str);
public:
	PhoneBook();
	~PhoneBook();

	void		addContact(void);
	void		printContacts(void);
	void		searchContact(void);
	bool		phoneBookIsEmpty(void);
};

#endif
