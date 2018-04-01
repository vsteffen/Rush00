/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:08:55 by quroulon          #+#    #+#             */
/*   Updated: 2018/03/31 14:08:56 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

#include <iostream>
#include "Entity.hpp"

class Character : virtual public Entity {

public:
	Character( void );
	Character( std::string, int, int, int, int, int, int, int );
	Character( Character const & src );
	virtual ~Character( void );

	Character &				operator=( Character const & rhs );

	int						getType( void ) const;

	bool					touch( Entity * entity );

private:

};

// std::ostream &			operator<<( std::ostream & o, Character const & rhs );

#endif
