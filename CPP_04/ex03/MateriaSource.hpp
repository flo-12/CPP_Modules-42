/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:27:50 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/05 19:27:52 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*_materia[4];
public:
	MateriaSource();
	MateriaSource( const MateriaSource &other );
	~MateriaSource();
	MateriaSource&	operator=( const MateriaSource &other );

	void		learnMateria( AMateria* m );
	AMateria*	createMateria( std::string const & type );
};


#endif
