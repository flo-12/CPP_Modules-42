/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:57:23 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/11 12:57:25 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//------------ ORTHODOX CANONICAL FORM ------------//

AForm::AForm() 
	: _name("default"), _signed(false), _gradeSign(150), _gradeExec(150)
{
}

AForm::AForm( const AForm &other ) 
	: _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
	if ( this->_gradeSign < 1 || this->_gradeExec < 1 )
		throw AForm::GradeTooHighException();
	else if ( this->_gradeSign > 155 || this->_gradeExec > 155 )
		throw AForm::GradeTooLowException();
}

AForm::AForm( const std::string name, const int gradeSign, const int gradeExec )
	: _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if ( this->_gradeSign < 1 || this->_gradeExec < 1 )
		throw AForm::GradeTooHighException();
	else if ( this->_gradeSign > 150 || this->_gradeExec > 150 )
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
}

AForm&	AForm::operator=( const AForm &other )
{
	if ( this == &other )
		return *this;
	
	_signed = other._signed;
	return *this;
}


//------------------ EXCEPTIONS ------------------//

const char* AForm::GradeTooHighException::what() const throw()
{
	return "FormException: Grade too High";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "FormException: Grade too Low";
}

const char*	AForm::UnsignedFormException::what() const throw()
{
	return "FormException: Unsigned Form";
}


//------------- GET- & SET-FUNCTIONS -------------//

std::string	AForm::getName() const
{
	return this->_name;
}

bool	AForm::getSigned() const
{
	return this->_signed;
}

int	AForm::getGradeSign() const
{
	return this->_gradeSign;
}

int	AForm::getGradeExec() const
{
	return this->_gradeExec;
}

void	AForm::setSigned( const bool s )
{
	_signed = s;
}


//--------------- MEMBER FUNCTIONS ---------------//

void	AForm::beSigned( const Bureaucrat &bureau )
{
	if ( bureau.getGrade() <= this->_gradeSign )
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::execute( Bureaucrat const & executor ) const
{
	if ( executor.getGrade() > this->_gradeExec )
		throw AForm::GradeTooLowException();
	else if ( !this->_signed )
		throw AForm::UnsignedFormException();
}


//--------------- OVERLOAD INSERTION --------------//

std::ostream&	operator<<( std::ostream &out, AForm &form )
{
	out << form.getName() << ", form signed: ";
	if (form.getSigned())
		out << "Yes ";
	else
		out << "No ";
	out << "| gradeSign=" << form.getGradeSign() << " | gradeExec=" << form.getGradeExec() << ".";
	return out;
}
