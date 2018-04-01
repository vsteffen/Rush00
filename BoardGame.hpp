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
#include "Enemy.hpp"
#include "Shoot.hpp"

#include "ft_retro.hpp"

class BoardGame {

public:
	typedef struct		s_list {
		Entity*			entity;
		struct s_list*	next;
	}					t_list;

	BoardGame( int nbLines, int nbCols );
	BoardGame( BoardGame const & src );
	virtual ~BoardGame( void );

	BoardGame &				operator=( BoardGame const & rhs );
	bool					addEntity( Entity * perso );
	bool					push( Entity* );
	void					deleteEntity( int x, int y );
	void					deleteEntity( Entity * entity );

	void					printBoard( void ) const;

	bool					moveUp( Entity * entity );
	bool					moveDown( Entity * entity );
	bool					moveLeft( Entity * entity );
	bool					moveRight( Entity * entity );
	bool					solveMove( Entity * entity1, Entity * entity2 );
	bool					shoot( Entity * entity );

	bool					resolve( void );

	int						getNbEntities( void ) const;
	void					getBoard( void ) const;
	void					getEntities( void ) const;

protected:
	int						_nbEntities;
	int						_nbPlayers;

	Entity***				_entities;
	int						_nbLines;
	int						_nbCols;
	t_list*					_list;

	t_list*					_save;

private:
	BoardGame( void );

};

// std::ostream &			operator<<( std::ostream & o, BoardGame const & rhs );

#endif
