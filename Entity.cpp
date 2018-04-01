/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:49:02 by quroulon          #+#    #+#             */
/*   Updated: 2018/03/31 15:49:04 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

Entity::Entity( void ) {
	// std::cout << "Entity default constructor called" << std::endl;
}

Entity::Entity( std::string name, int xPos, int yPos, int xVel, int yVel, int score, int HP ) : 
	_name(name), _xPos(xPos), _yPos(yPos), _xVelocity(xVel), _yVelocity(yVel),
	_score(score), _hitPoints(HP) {
	// std::cout << "Entity default constructor called" << std::endl;
}

Entity::Entity( Entity const & src ) {
	// std::cout << "Entity copy constructor called" << std::endl;
	*this = src;
}

/* ************************************************************************** */
/*                                 DESTRUCTORS                                */
/* ************************************************************************** */

Entity::~Entity( void ) {
	// std::cout << "Entity destructor called" << std::endl;
}

/* ************************************************************************** */
/*                             MEMBERS FUNCTIONS                              */
/* ************************************************************************** */

Entity &					Entity::operator=( Entity const & rhs ) {
	this->_name = rhs.getName();
	this->_xPos = rhs.getXPos();
	this->_yPos = rhs.getYPos();
	this->_xVelocity = rhs.getXVelocity();
	this->_yVelocity = rhs.getYVelocity();
	this->_score = rhs.getScore();
	this->_hitPoints = rhs.getHitPoints();

	std::cout << "Entity assignation operator called" << std::endl;

	return *this;
}

/* ************************************************************************** */
/*                                 SETTERS                                    */
/* ************************************************************************** */

void						Entity::setName( std::string name ) {
	this->_name = name;
}

void						Entity::setXPos( int xPos ) {
	this->_xPos = xPos;
}

void						Entity::setYPos( int yPos ) {
	this->_yPos = yPos;
}

void						Entity::setXVelocity( int xVel ) {
	this->_xVelocity = xVel;
}

void						Entity::setYVelocity( int yVel ) {
	this->_yVelocity = yVel;
}

void						Entity::setHitPoints( int HP ) {
	this->_hitPoints = HP;
}

void						Entity::setScore( int score ) {
	this->_score = score;
}

/* ************************************************************************** */
/*                                 GETTERS                                    */
/* ************************************************************************** */

std::string					Entity::getName( void ) const {
	return this->_name;
}

int							Entity::getXPos( void ) const {
	return this->_xPos;
}

int							Entity::getYPos( void ) const {
	return this->_yPos;
}

int							Entity::getXVelocity( void ) const {
	return this->_xVelocity;	
}

int							Entity::getYVelocity( void ) const {
	return this->_yVelocity;
}

int							Entity::getScore( void ) const {
	return this->_score;
}

int							Entity::getHitPoints( void ) const {
	return this->_hitPoints;
}

/* ************************************************************************** */
/*                           NON MEMBERS FUNCTIONS                            */
/* ************************************************************************** */

std::ostream &				operator<<( std::ostream & o, Entity const & rhs ) {
	o << rhs.getName() << " at x pos " << rhs.getXPos() << " and y pos " << rhs.getYPos() <<
	", HP : " << rhs.getHitPoints() << ", type : " << rhs.getType();
	return o;
}
