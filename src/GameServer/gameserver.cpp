#include "gameserver.h"
#include "../Entities/entity.h"
#include "../Messages/commandmessages.h"
#include "../Messages/statemessages.h"


GameServer::GameServer() {
}

// **************************************************************************************
//
// **************************************************************************************

GameServer::~GameServer() {
}

// **************************************************************************************
//
// **************************************************************************************

bool GameServer::initGame() {
	return true;
}

// **************************************************************************************
//
// **************************************************************************************

void GameServer::update(float deltaTime) {
	for(Entity * entity : mEntities) {
		entity->update(deltaTime);
	}
}

// **************************************************************************************
//
// **************************************************************************************

void GameServer::managePlayerCommand(const CommandMessage& message) {
	for(Entity * entity : mEntities)
		entity->manageCommand(message);
	
	if (message.GetType() == CommandMessage::GameExit)
		stateChanged(StateMessage(StateMessage::GameExit));
}

// **************************************************************************************
//
// **************************************************************************************

void GameServer::stateChanged(const StateMessage& message) {
	for(IGameView * view : mViews)
		view->stateChanged(message);
}

// **************************************************************************************
//
// **************************************************************************************

void GameServer::registerView(IGameView * view) {
	mViews.push_back(view);
}
