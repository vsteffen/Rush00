/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapGame.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:09:22 by quroulon          #+#    #+#             */
/*   Updated: 2018/03/31 14:09:23 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MapGame.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

MapGame::MapGame( void ) {
	std::cout << "Default constructor called" << std::endl;
}

MapGame::MapGame( MapGame const & src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/* ************************************************************************** */
/*                                 DESTRUCTORS                                */
/* ************************************************************************** */

MapGame::~MapGame( void ) {
	std::cout << "Destructor called" << std::endl;
}

/* ************************************************************************** */
/*                             MEMBERS FUNCTIONS                              */
/* ************************************************************************** */

MapGame &					MapGame::operator=( MapGame const & rhs ) {
	( void ) rhs;
	std::cout << "Assignation operator called" << std::endl;

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

// std::ostream &			operator<<( std::ostream & o, MapGame const & rhs ) {
// 	o << rhs.getFoo();
// 	return o;
// }

