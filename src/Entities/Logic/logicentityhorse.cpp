#include "logicentityhorse.h"
#include "consola.h"
#include "../../Messages/commandmessages.h"


LogicEntityHorse::LogicEntityHorse(IGameServer * pGameServer, unsigned int id) :
	LogicEntity(pGameServer, Horse, id) {}

// **************************************************************************************
//
// **************************************************************************************

LogicEntityHorse::~LogicEntityHorse() {
}

// **************************************************************************************
//
// **************************************************************************************

void LogicEntityHorse::update(float deltaTime) {
	MovePos(3, -3);
}

// **************************************************************************************
//
// **************************************************************************************

void LogicEntityHorse::manageCommand(const CommandMessage& message) {
	// TODO
}