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
	if (!mPaused)
		MovePos(1, 1);
}

// **************************************************************************************
//
// **************************************************************************************

void LogicEntityTurtle::manageCommand(const CommandMessage& message) {
	CommandMessage::Type type = message.GetType();
	switch (type) {
		case CommandMessage::Type::GamePause:
			mPaused = true;
			break;

		case CommandMessage::Type::GameResume:
			mPaused = false;
			break;
	}
}