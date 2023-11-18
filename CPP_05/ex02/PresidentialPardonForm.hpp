/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:08:23 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/11 12:08:25 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	PresidentialPardonForm();
	
	std::string	_target;
public:
	PresidentialPardonForm( std::string const target );
	PresidentialPardonForm( const PresidentialPardonForm &other );
	~PresidentialPardonForm();
	PresidentialPardonForm&	operator=( const PresidentialPardonForm &other );

	void	execute( Bureaucrat const & executor ) const;
};





#endif
