/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:08:30 by quroulon          #+#    #+#             */
/*   Updated: 2018/03/31 14:08:31 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

#include <iostream>
#include "Entity.hpp"

class Enemy : virtual public Entity {

public:
	Enemy( void );
	Enemy( std::string, int, int, int, int, int, int, int );
	Enemy( Enemy const & src );
	virtual ~Enemy( void );

	Enemy &				operator=( Enemy const & rhs );

	int					getType( void ) const;

	bool				touch( Entity * entity );

};

// std::ostream &			operator<<( std::ostream & o, Enemy const & rhs );

#endif
