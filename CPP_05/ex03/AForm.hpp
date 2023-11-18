/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:57:28 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/11 12:57:30 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
# include <exception>
# include "Bureaucrat.hpp"


class Bureaucrat;


class AForm
{
private:
	AForm();

	std::string const	_name;
	bool				_signed;
	int	const			_gradeSign;
	int	const			_gradeExec;
public:
	AForm( const AForm &other );
	AForm( const std::string name, const int gradeSign, const int gradeExec );
	virtual ~AForm();
	AForm&	operator=( const AForm &other );

	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw();
	};
	class UnsignedFormException : public std::exception {
		virtual const char* what() const throw();
	};

	std::string	getName() const;
	bool		getSigned() const;
	int			getGradeSign() const;
	int			getGradeExec() const;
	void		setSigned( const bool s );

	void			beSigned( const Bureaucrat &bureau );
	virtual void	execute( Bureaucrat const &executor ) const = 0;
};

std::ostream&	operator<<( std::ostream &out, AForm &form );



#endif
