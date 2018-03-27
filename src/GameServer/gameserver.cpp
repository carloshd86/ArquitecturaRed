#include "gameserver.h"
#include "../Entities/Logic/logicentity.h"
#include "../Messages/commandmessages.h"
#include "../Messages/statemessages.h"
#include "../Application/globals.h"


const unsigned int FIRST_IDENTITY_ID = 1;

// **************************************************************************************
//
// **************************************************************************************


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
	for(LogicEntity * entity : mEntities) {
		entity->update(deltaTime);
	}
}

// **************************************************************************************
//
// **************************************************************************************

void GameServer::managePlayerCommand(const CommandMessage& message) {
	for(LogicEntity * entity : mEntities)
		entity->manageCommand(message);
	
	CommandMessage::Type messageType = message.GetType();

	switch (messageType) {
		case CommandMessage::GameExit:
			stateChanged(StateMessageGameExit());
		break;

		case CommandMessage::GamePause:
			stateChanged(StateMessageGamePause());
			break;

		case CommandMessage::GameResume:
			stateChanged(StateMessageGameResume());
			break;
	}
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

// **************************************************************************************
//
// **************************************************************************************

void GameServer::addEntity(LogicEntity * entity) {
	mEntities.push_back(entity);

	stateChanged(StateMessageEntityAdded(*entity));
}

// **************************************************************************************
//
// **************************************************************************************

void GameServer::removeAllEntities() {
	for(auto entity : mEntities)
		removeEntity(entity);

	mEntities.clear();
}

// **************************************************************************************
//
// **************************************************************************************

void GameServer::removeEntity(LogicEntity * entity) {
	stateChanged(StateMessageEntityRemoved(entity->GetId()));
	GAME_DELETE(entity);
}

// **************************************************************************************
//
// **************************************************************************************

unsigned int GameServer::getNewIdentityId() {
	static unsigned int identityIdGenerator = FIRST_IDENTITY_ID;
	unsigned int newIdentityId = identityIdGenerator;
	identityIdGenerator++;

	return identityIdGenerator;
}