#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <ICharacter.hpp>

class Character : public ICharacter
{
private:
	
public:
	Character();
	Character( const Character &other );
	~Character();
	Character&	operator=( const Character &other );

	std::string const	&getName() const;
	void				equip( AMateria* m );
	void				unequip( int idx );
	void				use( int idx, ICharacter& target );
};



#endif