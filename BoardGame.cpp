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
	// Initialisation [][] entities
	this->_entities = new Entity**[this->_nbLines];

	for (int i = 0; i < this->_nbLines; i++) {
		this->_entities[i] = new Entity*[this->_nbCols];
		for (int j = 0; j < this->_nbCols; j++) {
			this->_entities[i][j] = NULL;
		}
	}

    // Initialisation list
    this->_list = NULL;
    this->_nbEntities = 0;
    this->_nbPlayers = 1;
    this->_save = NULL;
}

BoardGame::BoardGame( BoardGame const & src ) {
	*this = src;
}

/* ************************************************************************** */
/*                                 DESTRUCTORS                                */
/* ************************************************************************** */

BoardGame::~BoardGame( void ) {

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

	this->_nbEntities = rhs.getNbEntities();
	this->_nbPlayers = rhs.getNbPlayers();
	this->_nbLines = rhs.getNbLines();
	this->_nbCols = rhs.getNbCols();
	this->_save = NULL;

	t_list *		current = this->_list;
	t_list *		save = NULL;
	while (current != NULL) {
		save = current;
		current = current->next;

		delete save->entity;
		delete save;
	}

	this->_list = NULL;
	current = this->_list;
	save = NULL;
	
	t_list *		rhsList = rhs.getList();

	if (rhsList != NULL) {
		current = new (t_list);
		if (rhsList->entity->getType() == 1)
		current->entity = rhsList->entity->clone();
		current->next = NULL;
	}
	rhsList = rhsList->next;
	this->_list = current;
	save = current;

	while (rhsList != NULL) {
		
		current = new (t_list);
		current->entity = rhsList->entity->clone();
		current->next = NULL;
		save->next = current;

		rhsList = rhsList->next;
		save = current;

	}

	for (int i = 0; i < this->_nbLines; ++i) {
		delete [] this->_entities[i];
	}
	delete [] this->_entities;

	this->_entities = new Entity**[this->_nbLines];
	for (int i = 0; i < this->_nbLines; i++) {
		this->_entities[i] = new Entity*[this->_nbCols];
		for (int j = 0; j < this->_nbCols; j++) {
			this->_entities[i][j] = rhs.getEntities()[i][j];
		}
	}


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
		return false;
	}

	while (this->_entities[y][x] != NULL) {
		x++;
	}

	this->_nbEntities++;
	entity->setXPos(x);
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
}

void						BoardGame::deleteEntity( Entity * entity ) {
	t_list*			current = this->_list;
	t_list*			ptrBefore = NULL;
	t_list*			ptrNext = NULL;


	while (current != NULL) {
		std::cout << *(current->entity) << std::endl;
		if (entity == current->entity) {

			ptrNext = current->next;
			this->_entities[current->entity->getYPos()][current->entity->getXPos()] = NULL;
			this->_nbEntities--;
			delete current->entity;
			current->entity = NULL;
			delete current;
			current = NULL;

			if (ptrBefore != NULL)
				ptrBefore->next = ptrNext;
			else
				this->_list = ptrNext;
			return ;
		}
		ptrBefore = current;
		current = current->next;
	}
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
				else if (this->_entities[i][j]->getType() == 2) {
					mvprintw(i, j, "M");
				}
				else if (this->_entities[i][j]->getType() == 3) {
					mvprintw(i, j, "*");
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

	list = this->_list;
	this->_save = list;
	while (list != NULL) {

		this->_save = this->_save->next;

		int			type = list->entity->getType();
		if (type == 1) {

		}
		else if (type == 2) {

			// Si l'ennemi est tout en bas il disparait
			if (list != NULL && list->entity->getYPos() >= this->_nbLines - 1) {
				deleteEntity(list->entity);
			}
			else if (rand() % 5 == 0) {
				this->moveDown(list->entity);
			}
			else if (rand() % 10 == 0) {
				this->moveRight(list->entity);
			}
			else if (rand() % 10 == 0) {
				this->moveLeft(list->entity);
			}
		}
		else if (type == 3) {
			if (list != NULL && list->entity->getYPos() <= 1) {
				deleteEntity(list->entity);
			}
			else {
				this->moveUp(list->entity);
					
			}
		}
		list = this->_save;
	}

	if (this->_nbEntities < this->_nbCols) {
		if (rand() % 10 == 1) {
			Entity * newEnemy = new Enemy("enemy", rand() % this->_nbCols - 1, 1, 1, 1, 5, 1);
			this->addEntity(newEnemy);
		}
	}
	return true;
}

bool						BoardGame::shoot( Entity * entity ) {
	Entity *				shoot = new Shoot(entity->getXPos(), entity->getYPos() - 1);
	this->addEntity(shoot);
	return true;
}

/* ************************************************************************** */
/*                                   MOVE                                     */
/* ************************************************************************** */

bool						BoardGame::solveMove( Entity * entity1, Entity * entity2 ) {

	bool tmp1 = entity1->touch(entity2);
	bool tmp2 = entity2->touch(entity1);

	if (tmp2 == true && entity2->getType() != 1) {
		this->_save = this->_list;
		deleteEntity(entity2);
	}
	if (tmp1 == true && entity1->getType() != 1) {
		this->_save = this->_list;
		deleteEntity(entity1);

		return false;
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

int							BoardGame::getNbPlayers( void ) const {
	return this->_nbPlayers;
}

Entity***					BoardGame::getEntities( void ) const {
	return this->_entities;
}

int							BoardGame::getNbLines( void ) const {
	return this->_nbLines;
}

int							BoardGame::getNbCols( void ) const {
	return this->_nbCols;
}

BoardGame::t_list*			BoardGame::getList( void ) const {
	return this->_list;
}


/* ************************************************************************** */
/*                           NON MEMBERS FUNCTIONS                            */
/* ************************************************************************** */

// std::ostream &			operator<<( std::ostream & o, BoardGame const & rhs ) {
// 	o << rhs.getFoo();
// 	return o;
// }
