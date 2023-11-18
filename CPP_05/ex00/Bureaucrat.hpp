/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:22:17 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:22:19 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat
{
private:
	std::string const	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat( const std::string name, const int grade );
	Bureaucrat( const Bureaucrat &other );
	~Bureaucrat();
	Bureaucrat&	operator=( const Bureaucrat &other );

	class GradeTooHighException : public std::exception	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception	{
		virtual const char* what() const throw();
	};

	std::string	getName() const;
	int			getGrade() const;

	void		incGrade();
	void		decGrade();
};

std::ostream&	operator<<( std::ostream &out, const Bureaucrat &bureau );


#endif
