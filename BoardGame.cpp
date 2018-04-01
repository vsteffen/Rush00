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

BoardGame::BoardGame( int nbLines, int nbCols ) : _nbLines(nbLines), _nbCols(nbCols) {
	std::cout << "BoardGame default constructor called" << std::endl;

	// Initialisation [][] entities
	this->_entities = new Entity**[this->_nbLines];

	for (int i = 0; i < this->_nbLines; ++i) {
        this->_entities[i] = new Entity*[this->_nbCols];
        for (int j = 0; j < this->_nbCols; ++j) {
            this->_entities[i][j] = NULL;
        }
    }

    // Initialisation list
    this->_list = NULL;
    this->_nbEntities = 0;
    this->_nbPlayers = 1;
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

		delete tmp->entity;
		delete tmp;
	}
	this->_list = NULL;
}

/* ************************************************************************** */
/*                                 ATTRIBUTES                                 */
/* ************************************************************************** */

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

	// // 1 == Character
	// if (entity->getType() == 1) {
	// }

	list = this->_list;
	while (list != NULL) {
		if (entity == list->entity) {

			// std::cout << "FOUND DELETE " << *(list->entity) << std::endl;
			tmp2 = list->next;
			this->_entities[list->entity->getYPos()][list->entity->getXPos()] = NULL;
			this->_nbEntities--;

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
	// std::cout << "Entity not found" << std::endl;

}

/* ************************************************************************** */
/*                                   PRINT                                    */
/* ************************************************************************** */


void						BoardGame::printBoard( void ) const {
	for (int i = 0; i < this->_nbLines; i++) {
		for (int j = 0; j < this->_nbCols; j++) {
			if (this->_entities[i][j] != NULL) {
				if (this->_entities[i][j]->getType() == 1) {
					mvprintw(i, j, "O");
				}
				else {
					mvprintw(i, j, "M");
				}
			}
		}
	}
}

/* ************************************************************************** */
/*                                 RESOLVE                                    */
/* ************************************************************************** */


bool						BoardGame::resolve( void ) {
	t_list *				list;
	t_list *				tmp;

	list = this->_list;
	while (list != NULL) {
		tmp = list->next;
		if (list->entity->getType() == 1) {

		}
		else if (list->entity->getType() == 2) {
			this->moveDown(list->entity);
			// Si l'ennemi est tout en bas il disparait
			if (list->entity->getYPos() >= this->_nbLines - 1) {
				deleteEntity(list->entity);
			}
		}
		list = tmp;
	}

	if (this->_nbEntities < (this->_nbCols / 3)) {
		int random = rand() % this->_nbCols - 1;
		if (random % 5 == 1) {
			Entity * newEnemy = new Enemy("enemy", random, 1, 1, 1, 5, 1);
			this->addEntity(newEnemy);
		}
	}
	return true;
}


/* ************************************************************************** */
/*                                   MOVE                                     */
/* ************************************************************************** */

bool						BoardGame::solveMove( Entity * entity1, Entity * entity2 ) {

	bool tmp1 = entity1->touch(entity2);
	bool tmp2 = entity2->touch(entity1);

	if (tmp1 == true && entity1->getType() != 1) {
		deleteEntity(entity1);
		return false;
	}
	if (tmp2 == true && entity2->getType() != 1) {
		deleteEntity(entity2);
	}
	return true;
}

bool						BoardGame::moveUp( Entity * entity ) {
	int				x = entity->getXPos();
	int				y = entity->getYPos();

	if (y - 1 <= 0) {
		return false;
	}

	if (this->_entities[y - 1][x] != NULL) {
		if (solveMove(this->_entities[y][x], this->_entities[y - 1][x]) == false)
			return false;
	}

	this->_entities[y - 1][x] = this->_entities[y][x];
	this->_entities[y][x] = NULL;

	entity->setYPos(y - 1);
	return true;

}

bool						BoardGame::moveDown( Entity * entity ) {
	int				x = entity->getXPos();
	int				y = entity->getYPos();

	if (y + 1 >= this->_nbLines) {
		return false;
	}

	if (this->_entities[y + 1][x] != NULL) {
		if (solveMove(this->_entities[y][x], this->_entities[y + 1][x]) == false)
			return false;
	}

	this->_entities[y + 1][x] = this->_entities[y][x];
	this->_entities[y][x] = NULL;

	entity->setYPos(y + 1);
	return true;
}

bool						BoardGame::moveLeft( Entity * entity ) {
	int				x = entity->getXPos();
	int				y = entity->getYPos();

	if (x - 1 <= 0) {
		return false;
	}

	if (this->_entities[y][x - 1] != NULL) {
		if (solveMove(this->_entities[y][x], this->_entities[y][x - 1]) == false)
			return false;
	}

	this->_entities[y][x - 1] = this->_entities[y][x];
	this->_entities[y][x] = NULL;

	entity->setXPos(x - 1);
	return true;
}

bool						BoardGame::moveRight( Entity * entity ) {
	int				x = entity->getXPos();
	int				y = entity->getYPos();

	if (x + 1 >= this->_nbCols) {
		return false;
	}

	if (this->_entities[y][x + 1] != NULL) {
		if (solveMove(this->_entities[y][x], this->_entities[y][x + 1]) == false)
			return false;
	}

	this->_entities[y][x + 1] = this->_entities[y][x];
	this->_entities[y][x] = NULL;

	entity->setXPos(x + 1);
	return true;
}

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
	for (int i = 0; i < this->_nbLines; i++) {
		for (int j = 0; j < this->_nbCols; j++) {

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
