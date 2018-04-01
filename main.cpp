/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 01:13:39 by quroulon          #+#    #+#             */
/*   Updated: 2018/03/31 01:13:43 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "BoardGame.hpp"
#include "Entity.hpp"
#include "Character.hpp"
#include "Enemy.hpp"

/** ( std::string name, int xPos, int yPos, int xVel, int yVel, int score, int HP ) **/

int					main2( void ) {

	BoardGame *		board = new BoardGame(20, 20);

	Entity *		perso = new Character("Link", 5, 5, 1, 1, 0, 5);
	board->addEntity(perso);
	board->moveLeft(perso);

	Entity *		perso2 = new Character("test", 15, 5, 1, 1, 0, 5);
	board->addEntity(perso2);
	board->moveDown(perso2);

	std::cout << *perso2 << std::endl;

	// Entity *		perso3 = new Character("test", 6, 5, 1, 1, 0, 5);
	// board->addEntity(perso3);
	// board->moveUp(perso3);

	// Entity *		enemy1 = new Enemy("Enemy 1", 9, 9, 1, 1, 5, 1);
	// Entity *		enemy2 = new Enemy("Enemy 2", 8, 8, 1, 1, 5, 1);
	// Entity *		enemy3 = new Enemy("Enemy 3", 6, 5, 1, 1, 5, 1);
	// board->addEntity(enemy1);
	// board->addEntity(enemy2);
	// board->addEntity(enemy3);

	std::cout << *perso << std::endl;
	board->getEntities();

	perso->setName("Zelda");
	perso->setXPos(9);
	std::cout << *perso << std::endl;
	board->getEntities();

	board->moveUp(perso);
	board->moveLeft(perso);
	std::cout << *perso << std::endl;
	board->moveDown(perso);
	board->moveRight(perso);
	std::cout << *perso << std::endl;

	// board->deleteEntity(9, 9);
	// board->deleteEntity(enemy1);
	// board->deleteEntity(9, 9);
	// board->deleteEntity(enemy1);
	// board->deleteEntity(enemy2);
	// board->deleteEntity(enemy3);
	board->deleteEntity(perso);


	delete (board);

	return 0;
}

