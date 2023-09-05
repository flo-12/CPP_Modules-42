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
	Bureaucrat( const Bureaucrat &other );
	~Bureaucrat();
	Bureaucrat&	operator=( const Bureaucrat &other );

	std::string	getName() const;
	int			getGrade() const;

	void		incGrade(); // e .g. from 3->2
	void		decGrade();
};

std::ofstream	operator<<( const Bureaucrat lame );

Bureaucrat::Bureaucrat( ) : _name("default"), _grade(50)
{
	std::cout << "Created Default Bureaucrat (name: " << _name << ", grade: " << _grade << ")" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
}


#endif
