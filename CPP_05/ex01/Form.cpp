/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:22:12 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:22:14 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//------------ ORTHODOX CANONICAL FORM ------------//

Form::Form() : _name("default"), _signed(false), _gradeSign(150), _gradeExec(150)
{
}

Form::Form( const Form &other ) : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
	if ( this->_gradeSign < 1 || this->_gradeExec < 1 )
		throw Form::GradeTooHighException();
	else if ( this->_gradeSign > 155 || this->_gradeExec > 155 )
		throw Form::GradeTooLowException();
}

Form::Form( const std::string name, const bool s, const int gradeSign, const int gradeExec )
	: _name(name), _signed(s), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if ( this->_gradeSign < 1 || this->_gradeExec < 1 )
		throw Form::GradeTooHighException();
	else if ( this->_gradeSign > 150 || this->_gradeExec > 150 )
		throw Form::GradeTooLowException();
}

Form::~Form()
{
}

Form&	Form::operator=( const Form &other )
{
	if ( this == &other )
		return *this;
	
	_signed = other._signed;
	_gradeSign = other._gradeSign;
	_gradeExec = other._gradeExec;
	return *this;
}


//------------------ EXCEPTIONS ------------------//

const char* Form::GradeTooHighException::what() const throw()
{
	return "FormException: Grade too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "FormException: Grade too Low";
}


//------------- GET- & SET-FUNCTIONS -------------//

std::string	Form::getName() const
{
	return this->_name;
}

bool	Form::getSigned() const
{
	return this->_signed;
}

int	Form::getGradeSign() const
{
	return this->_gradeSign;
}

int	Form::getGradeExec() const
{
	return this->_gradeExec;
}


//--------------- MEMBER FUNCTIONS ---------------//

void	Form::beSigned( const Bureaucrat &bureau )
{
	if ( bureau.getGrade() <= this->_gradeSign )
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}


//--------------- OVERLOAD INSERTION --------------//

std::ostream&	operator<<( std::ostream &out, Form &form )
{
	out << form.getName() << ", form signed: ";
	if (form.getSigned())
		out << "Yes ";
	else
		out << "No ";
	out << "| gradeSign=" << form.getGradeSign() << " | gradeExec=" << form.getGradeExec() << ".";
	return out;
}
