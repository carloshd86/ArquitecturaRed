#include "gameserverlocal.h"
#include "../../Application/globals.h"
#include "../../Entities/Logic/logicentityhorse.h"
#include "../../Entities/Logic/logicentityturtle.h"


GameServerLocal::GameServerLocal() {
}

// **************************************************************************************
//
// **************************************************************************************

GameServerLocal::~GameServerLocal() {
	removeAllEntities();
}

// **************************************************************************************
//
// **************************************************************************************

bool GameServerLocal::initGame() {

	bool result = GameServer::initGame();
	GAME_ASSERT(result);

	LogicEntityHorse * horse = GAME_NEW(LogicEntityHorse, (this, getNewIdentityId()));
	addEntity(horse);
	LogicEntityTurtle * turtle = GAME_NEW(LogicEntityTurtle, (this, getNewIdentityId()));
	addEntity(turtle);

	result = true;
	return result;
}
