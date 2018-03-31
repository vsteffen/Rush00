/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:52:44 by quroulon          #+#    #+#             */
/*   Updated: 2018/03/31 14:52:45 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

#include <iostream>

class Entity {

public:
	Entity( std::string name, int xPos, int yPos, int xVel, int yVel, int score, int HP );
	Entity( Entity const & src );
	virtual ~Entity( void );

	Entity &				operator=( Entity const & rhs );

	std::string				getName( void ) const;
	virtual int				getXPos( void ) const;
	virtual int				getYPos( void ) const;
	virtual int				getXVelocity( void ) const;
	virtual int				getYVelocity( void ) const;
	virtual int				getScore( void ) const;
	virtual int				getHitPoints( void ) const;

	void					setName( std::string );
	virtual void			setXPos( int );
	virtual void			setYPos( int );
	virtual void			setXVelocity( int );
	virtual void			setYVelocity( int );
	// virtual void			setScore( int );
	// virtual void			setHitPoints( int );

protected:
	std::string				_name;
	int						_xPos;
	int						_yPos;
	int						_xVelocity;
	int						_yVelocity;
	int						_score;
	int						_hitPoints;

private:
	Entity( void );
	
};

std::ostream &			operator<<( std::ostream & o, Entity const & rhs );

#endif
