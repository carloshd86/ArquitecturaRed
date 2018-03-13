#include "logicentityturtle.h"
#include "consola.h"
#include "../../Messages/commandmessages.h"


LogicEntityTurtle::LogicEntityTurtle(IGameServer * pGameServer, unsigned int id) :
	LogicEntity(pGameServer, Turtle, id) {}

// **************************************************************************************
//
// **************************************************************************************

LogicEntityTurtle::~LogicEntityTurtle() {
}

// **************************************************************************************
//
// **************************************************************************************

void LogicEntityTurtle::update(float deltaTime) {
	MovePos(1, 1);
}

// **************************************************************************************
//
// **************************************************************************************

void LogicEntityTurtle::manageCommand(const CommandMessage& message) {
	// TODO
}