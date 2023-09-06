/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:22:12 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:22:14 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//------------ ORTHODOX CANONICAL FORM ------------//

Bureaucrat::Bureaucrat( ) : _name("default"), _grade(5)
{
	//std::cout << "Created Default Bureaucrat (name: " << _name << ", grade: " << _grade << ")" << std::endl;
}

Bureaucrat::Bureaucrat( const std::string name, const int grade ) : _name(name), _grade(grade)
{
	if ( this->_grade < 1 )
		throw Bureaucrat::GradeTooHighException();
	else if ( this->_grade > 155 )
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat &other )
{
	*this = other;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat &other )
{
	if (this == &other)
		return *this;

	//this->_name = other._name;
	this->_grade = other._grade;
	return *this;
}

//------------------ EXCEPTIONS ------------------//

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "BureaucratException: Grade too High";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "BureaucratException: Grade too Low";
}

//------------- GET- & SET-FUNCTIONS -------------//

std::string	Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

//--------------- MEMBER FUNCTIONS ---------------//

void	Bureaucrat::incGrade()
{
	if ( this->_grade <= 1 )
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::decGrade()
{
	if ( this->_grade >= 150 )
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}


//---------------- PRINT OVERLOAD ----------------//

/* operator<<:
*	ostream operator overload for "std::out << (Bureaucrat)a".
*/
std::ostream	&operator<<( std::ostream &out, const Bureaucrat &bureau )
{
	out << bureau.getName() << ", bureaucrat grade " << bureau.getGrade() << ".";
	return ( out );
}
