/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:08:45 by quroulon          #+#    #+#             */
/*   Updated: 2018/03/31 14:08:46 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

/** ( std::string name, int xPos, int yPos, int xVel, int yVel, int score, int HP ) **/
Character::Character( void ) : Entity( "Character", 1, 0, 0, 1, 1, 0, 5 ) {
	// std::cout << "Character default constructor called" << std::endl;
}

Character::Character( std::string name, int type, int x, int y, int xVel, int yVel, int score, int HP ) :
	Entity( name, type, x, y, xVel, yVel, score, HP ) {
	// std::cout << "Character default constructor called" << std::endl;
}

Character::Character( Character const & src ) : Entity( src ) {
	// std::cout << "Character copy constructor called" << std::endl;
	*this = src;
}

/* ************************************************************************** */
/*                                 DESTRUCTORS                                */
/* ************************************************************************** */

Character::~Character( void ) {
	// std::cout << "Character destructor called" << std::endl;
}

/* ************************************************************************** */
/*                             MEMBERS FUNCTIONS                              */
/* ************************************************************************** */

Character &					Character::operator=( Character const & rhs ) {

	this->Entity::operator=(rhs);
	// std::cout << "Character assignation operator called" << std::endl;
	// this->_name = rhs.getName();

	return *this;
}

bool						Character::touch( Entity * entity ) {
	// 2 == Enemy
	if (entity->getType() % 10 == 2 || entity->getType() % 10 == 3) {
		this->setHitPoints(0);
		return true;
	}
	return false;
	// if (entity->getType() == Enemy::getType()) {
	// 	entity->setHitPoints(0);
	// }
	// else if (entity->getType() == Shoot::getType()) {
	// 	entity->setHitPoints(this->getHitPoints() - damage)
	// }
}


/* ************************************************************************** */
/*                                 SETTERS                                    */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                 GETTERS                                    */
/* ************************************************************************** */

int							Character::getType( void ) const {
	return 1;
}

/* ************************************************************************** */
/*                           NON MEMBERS FUNCTIONS                            */
/* ************************************************************************** */

// std::ostream &			operator<<( std::ostream & o, Character const & rhs ) {
// 	o << rhs.getName() << " at x pos " << rhs.getXPos() << " and y pos " << rhs.getYPos() <<
// 	", HP : " << rhs.getHitPoints() << ", type : " << rhs.getType();
// 	return o;
// }
