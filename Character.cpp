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
Character::Character( void ) : Entity( "Character", 0, 0, 1, 1, 0, 5 ) {
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character( std::string name, int x, int y, int xVel, int yVel, int score, int HP ) : 
	Entity( name, x, y, xVel, yVel, score, HP ) {
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character( Character const & src ) : Entity( src ) {
	std::cout << "Character copy constructor called" << std::endl;
	*this = src;
}

/* ************************************************************************** */
/*                                 DESTRUCTORS                                */
/* ************************************************************************** */

Character::~Character( void ) {
	std::cout << "Character destructor called" << std::endl;
}

/* ************************************************************************** */
/*                             MEMBERS FUNCTIONS                              */
/* ************************************************************************** */

Character &					Character::operator=( Character const & rhs ) {
	
	this->Entity::operator=(rhs);
	std::cout << "Character assignation operator called" << std::endl;
	// this->_name = rhs.getName();

	return *this;
}

/* ************************************************************************** */
/*                                 SETTERS                                    */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                 GETTERS                                    */
/* ************************************************************************** */

/* ************************************************************************** */
/*                           NON MEMBERS FUNCTIONS                            */
/* ************************************************************************** */

// std::ostream &			operator<<( std::ostream & o, Entity const & rhs ) {
// 	o << rhs.getFoo();
// 	return o;
// }
