#include "gameserverlocal.h"
#include "../../Tools/memoryleaks.h"
#include "../../Entities/horse.h"
#include "../../Entities/turtle.h"


bool GameServer::initGame() {

	EntityHorse * horse = GAME_NEW(EntityHorse);
	mEntities.push_back(horse);
	EntityTurtle * turtle = GAME_NEW(EntityTurtle);
	mEntities.push_back(turtle);

	return true;
}