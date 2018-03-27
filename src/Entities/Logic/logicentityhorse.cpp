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
	if (!mPaused)
		MovePos(3, -3);
}

// **************************************************************************************
//
// **************************************************************************************

void LogicEntityHorse::manageCommand(const CommandMessage& message) {
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