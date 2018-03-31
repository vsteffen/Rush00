/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BoardGame.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:09:49 by quroulon          #+#    #+#             */
/*   Updated: 2018/03/31 14:09:50 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BoardGame.hpp"

/* ************************************************************************** */
/*                                CONSTRUCTORS                                */
/* ************************************************************************** */

BoardGame::BoardGame( void ) : _nbLines(10), _nbCols(10) {
	std::cout << "BoardGame default constructor called" << std::endl;

	// Initialisation [][] entitites
	this->_entities = new Entity**[this->_nbLines];

	for (int i = 0; i < this->_nbLines; ++i) {
        this->_entities[i] = new Entity*[this->_nbCols];
        for (int j = 0; j < this->_nbCols; ++j) {
            this->_entities[i][j] = NULL;
        }
    }

    // Initialisation list
    this->_list = NULL;
}

BoardGame::BoardGame( BoardGame const & src ) {
	std::cout << "BoardGame copy constructor called" << std::endl;
	*this = src;
}

/* ************************************************************************** */
/*                                 DESTRUCTORS                                */
/* ************************************************************************** */

BoardGame::~BoardGame( void ) {
	std::cout << "BoardGame destructor called" << std::endl;

	// Delete [][] _entities
	for (int i = 0; i < this->_nbLines; ++i) {
		delete [] this->_entities[i];
	}
	delete [] this->_entities;
	// Delete t_list _list
	t_list		*tmp;
	t_list		*list;

	list = this->_list;
	while (list != NULL) {
		tmp = list;
		list = tmp->next;

		std::cout << "ICI " << tmp->entity->getName() << std::endl;

		delete tmp->entity;
		delete tmp;
	}
	this->_list = NULL;
}

/* ************************************************************************** */
/*                             MEMBERS FUNCTIONS                              */
/* ************************************************************************** */

int							BoardGame::_nbEntities = 0;
int							BoardGame::_nbPlayers = 1;

/* ************************************************************************** */
/*                             MEMBERS FUNCTIONS                              */
/* ************************************************************************** */

BoardGame &					BoardGame::operator=( BoardGame const & rhs ) {
	( void ) rhs;
	std::cout << "BoardGame assignation operator called" << std::endl;

	return *this;
}

bool						BoardGame::addEntity( Entity * entity ) {

	if (entity == NULL) {
		return false;
	}

	// Y == LINES, X == COLS
	int			x = (entity)->getXPos();
	int			y = (entity)->getYPos();

	if (y > this->_nbLines || y < 0 || x > this->_nbCols || x < 0) {
		std::cout << "ERROR" << std::endl;
		return false;
	}

	// TODO NE PEUX PAS ADD SI DEJA QUELQUE CHOSE 

	this->_nbEntities++;
	this->_entities[y][x] = entity;
	this->push(entity);
	return true;
}

bool						BoardGame::push( Entity* entity ) {
	t_list*				list;
	t_list*				newList = new (t_list);

	list = this->_list;
	newList->entity = entity;
	newList->next = NULL;

	if (list != NULL) {
		while (list->next)
			list = list->next;
		list->next = newList;
	}
	else {
		std::cout << " NEW LIST " << std::endl;
		this->_list = newList;
	}

	return true;
}

void						BoardGame::deleteEntity( int x, int y ) {
	if (this->_entities[y][x] != NULL) {
		deleteEntity(this->_entities[y][x]);
	}
	else {
		std::cout << "Entity not found" << std::endl;
	}
}

void						BoardGame::deleteEntity( Entity * entity ) {
	t_list*			list;
	t_list*			tmp = NULL;
	t_list*			tmp2 = NULL;

	list = this->_list;
	while (list != NULL) {
		if (entity == list->entity) {

			std::cout << "FOUND DELETE " << *(list->entity) << std::endl;
			tmp2 = list->next;
			this->_entities[list->entity->getYPos()][list->entity->getXPos()] = NULL;

			delete list->entity;
			delete list;
			list = NULL;

			if (tmp != NULL) {
				tmp->next = tmp2;
			}
			else {
				this->_list = NULL;
			}
			return;
		}
		tmp = list;
		list = list->next;
	}
	std::cout << "Entity not found" << std::endl;

}

/* ************************************************************************** */
/*                                   MOVE                                     */
/* ************************************************************************** */

bool						BoardGame::moveUp( Entity * perso ) {
	int				x = perso->getXPos();
	int				y = perso->getYPos();

	if (y - 1 < 0) {
		return false;
	}
	this->_entities[y - 1][x] = this->_entities[y][x];
	this->_entities[y][x] = NULL;

	perso->setYPos(y - 1);
	return true;

}

// bool						BoardGame::moveDown( Entity * entity ) {

// }

// bool						BoardGame::moveLeft( Entity * entity ) {

// }

// bool						BoardGame::moveRight( Entity * entity ) {

// }

/* ************************************************************************** */
/*                                 SETTERS                                    */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                 GETTERS                                    */
/* ************************************************************************** */

int							BoardGame::getNbEntities( void ) const {
	return this->_nbEntities;
}

void						BoardGame::getBoard( void ) const {
	for (int i = 0; i < this->_nbLines; ++i) {
		for (int j = 0; j < this->_nbCols; ++j) {

			if (this->_entities[i][j] != NULL) {
				std::cout << "FOUND ARRAY i(y) : " << i << " j(x) " << j << " "<<this->_entities[i][j]->getXPos() << std::endl;
			}
		}
	}
}

void						BoardGame::getEntities( void ) const {
	t_list*			list;

	list = this->_list;
	while (list != NULL) {
		std::cout << list->entity->getName() << std::endl;
		list = list->next;
	}
}

/* ************************************************************************** */
/*                           NON MEMBERS FUNCTIONS                            */
/* ************************************************************************** */

// std::ostream &			operator<<( std::ostream & o, BoardGame const & rhs ) {
// 	o << rhs.getFoo();
// 	return o;
// }
