/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:08:36 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/11 12:08:38 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <stdlib.h>
# include <time.h> 
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	RobotomyRequestForm();

	std::string	_target;
public:
	RobotomyRequestForm( std::string const target );
	RobotomyRequestForm( const RobotomyRequestForm &other );
	~RobotomyRequestForm();
	RobotomyRequestForm&	operator=( const RobotomyRequestForm &other );

	void	execute( Bureaucrat const & executor ) const;
};



#endif
