/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapGame.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:09:17 by quroulon          #+#    #+#             */
/*   Updated: 2018/03/31 14:09:18 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPGAME_H
# define MAPGAME_H

#include <iostream>

class MapGame {

public:
	MapGame( void );
	MapGame( MapGame const & src );
	virtual ~MapGame( void );

	MapGame &				operator=( MapGame const & rhs );

private:

};

// std::ostream &			operator<<( std::ostream & o, MapGame const & rhs );

#endif
