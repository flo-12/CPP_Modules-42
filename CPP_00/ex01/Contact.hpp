/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:43:54 by fbecht            #+#    #+#             */
/*   Updated: 2023/07/05 16:43:56 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <limits>

class Contact
{
private:
	int			_index;
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkSecret;
	std::string	_getUserInput(std::string str);
	std::string	_printLen(std::string str);
public:
	Contact();
	~Contact();

	void		setIndex(int i);
	void		initContact(void);
	void		displayContactTable(void);
	void		displayContactDetail(void);
	bool		hasFirstName(void);
	std::string	getFirstName(void);
};

#endif
