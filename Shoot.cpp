/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 04:03:40 by quroulon          #+#    #+#             */
/*   Updated: 2018/04/01 04:03:41 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shoot.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

/** ( std::string name, int xPos, int yPos, int xVel, int yVel, int score, int HP ) **/
Shoot::Shoot( void ) : Entity( "Shoot", 3, 0, 0, 1, 2, 0, 1 ) {
}

Shoot::Shoot( int x, int y, bool direction ) : Entity( "Shoot", 3, 0, 0, 1, 2, 0, 1 ) {
	this->_xPos = x;
	this->_yPos = y;
	this->_direction = direction;
}

Shoot::Shoot( std::string name, int type, int x, int y, int xVel, int yVel, int score, int HP ) :
	Entity( name, type, x, y, xVel, yVel, score, HP ) {
}

Shoot::Shoot( Shoot const & src ) : Entity( src ) {
	*this = src;
}

/* ************************************************************************** */
/*                                 DESTRUCTORS                                */
/* ************************************************************************** */

Shoot::~Shoot( void ) {
	// std::cout << "Shoot destructor called" << std::endl;
}

/* ************************************************************************** */
/*                             MEMBERS FUNCTIONS                              */
/* ************************************************************************** */

Shoot &					Shoot::operator=( Shoot const & rhs ) {

	this->Entity::operator=(rhs);
	return *this;
}

bool					Shoot::touch( Entity * entity ) {
	// 2 == Enemy, 1 == Character
	if (entity->getType() % 10 == 2 || entity->getType() == 1 || entity->getType() == 3) {
		// this->setHitPoints(0);
		return true;
	}
	return false;
}

Entity *				Shoot::clone( void ) const {
	return new Shoot(*this);
}

/* ************************************************************************** */
/*                                 SETTERS                                    */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                 GETTERS                                    */
/* ************************************************************************** */

int							Shoot::getType( void ) const {
	return 3;
}

bool						Shoot::getDirection( void ) const {
	return this->_direction;
}


/* ************************************************************************** */
/*                           NON MEMBERS FUNCTIONS                            */
/* ************************************************************************** */
