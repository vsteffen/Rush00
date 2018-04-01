/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 04:03:48 by quroulon          #+#    #+#             */
/*   Updated: 2018/04/01 04:03:50 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOOT_H
# define SHOOT_H

#include <iostream>
#include "Entity.hpp"

class Shoot : virtual public Entity {

public:
	Shoot( void );
	Shoot( int x, int y, bool direction);
	Shoot( std::string, int, int, int, int, int, int, int );
	Shoot( Shoot const & src );
	virtual ~Shoot( void );

	Shoot &				operator=( Shoot const & rhs );

	int						getType( void ) const;
	bool					getDirection( void ) const;

	bool					touch( Entity * entity );

private:

};

// std::ostream &			operator<<( std::ostream & o, Shoot const & rhs );

#endif
