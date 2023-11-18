/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:58:04 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/11 12:58:05 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
private:
	static std::string	_forms[3];
	AForm* 				(*_formCreator[3])( const std::string target );
	static AForm*		_createPPF( const std::string target );
	static AForm*		_createRRF( const std::string target );
	static AForm*		_createSCF( const std::string target );

public:
	Intern();
	Intern( const Intern &other );
	~Intern();
	Intern&	operator=( const Intern &other );

	AForm*	makeForm( const std::string form, const std::string target );
};


#endif
