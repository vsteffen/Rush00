/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BoardGame.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:09:57 by quroulon          #+#    #+#             */
/*   Updated: 2018/03/31 14:09:58 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARDGAME_H
# define BOARDGAME_H

#include <iostream>
#include "Entity.hpp"
#include "Character.hpp"

class BoardGame {

public:
	typedef struct		s_list {
		Entity*			entity;
		struct s_list*	next;
	}					t_list;

	BoardGame( void );
	BoardGame( BoardGame const & src );
	virtual ~BoardGame( void );

	BoardGame &				operator=( BoardGame const & rhs );
	bool					addEntity( Entity * perso );
	bool					push( Entity* );
	void					deleteEntity( int x, int y );
	void					deleteEntity( Entity * entity );

	bool					moveUp( Entity * perso );
	// bool					moveDown( Entity * entity );
	// bool					moveLeft( Entity * entity );
	// bool					moveRight( Entity * entity );

	int						getNbEntities( void ) const;
	void					getBoard( void ) const;
	void					getEntities( void ) const;

protected:
	static int				_nbEntities;
	static int				_nbPlayers;

	Entity***				_entities;
	int						_nbLines;
	int						_nbCols;
	t_list*					_list;

private:

};

// std::ostream &			operator<<( std::ostream & o, BoardGame const & rhs );

#endif
