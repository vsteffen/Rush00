/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:08:35 by quroulon          #+#    #+#             */
/*   Updated: 2018/03/31 14:08:36 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

/** ( std::string name, int xPos, int yPos, int xVel, int yVel, int score, int HP ) **/
Enemy::Enemy( void ) : Entity( "Enemy", 2, 0, 0, 1, 1, 5, 1 ) {
	// std::cout << "Enemy default constructor called" << std::endl;
}

Enemy::Enemy( std::string name, int type, int x, int y, int xVel, int yVel, int score, int HP ) :
	Entity(name, type, x, y, xVel, yVel, score, HP) {
	// std::cout << "Enemy default constructor called" << std::endl;
}

Enemy::Enemy( Enemy const & src ) : Entity( src ) {
	// std::cout << "Enemy copy constructor called" << std::endl;
	*this = src;
}

/* ************************************************************************** */
/*                                 DESTRUCTORS                                */
/* ************************************************************************** */

Enemy::~Enemy( void ) {
	// std::cout << "Enemy destructor called" << std::endl;
}

/* ************************************************************************** */
/*                             MEMBERS FUNCTIONS                              */
/* ************************************************************************** */

Enemy &					Enemy::operator=( Enemy const & rhs ) {

	this->Entity::operator=(rhs);
	// std::cout << "Enemy assignation operator called" << std::endl;

	return *this;
}

bool					Enemy::touch( Entity * entity ) {
	// 3 == SHOOT, 2 == ENEMY
	if (entity->getType() == 3 || entity->getType() % 10 == 2) {
		this->setHitPoints(0);
		return true;
	}
	return false;
}

/* ************************************************************************** */
/*                                 SETTERS                                    */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                 GETTERS                                    */
/* ************************************************************************** */

int						Enemy::getType( void ) const {
	return this->_type;
}


/* ************************************************************************** */
/*                           NON MEMBERS FUNCTIONS                            */
/* ************************************************************************** */

// std::ostream &			operator<<( std::ostream & o, Enemy const & rhs ) {
// 	o << rhs.getFoo();
// 	return o;
// }
