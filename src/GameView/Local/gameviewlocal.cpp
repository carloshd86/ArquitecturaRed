#include "gameviewlocal.h"
#include "consola.h"
#include "../../Entities/Logic/logicentity.h"
#include "../../Entities/View/viewentity.h"
#include "../../Entities/View/viewentityhorse.h"
#include "../../Entities/View/viewentityturtle.h"
#include "../../Tools/asserts.h"
#include "../../Tools/memoryleaks.h"
#include "../../Messages/commandmessages.h"
#include "../../InputManager/iinputmanager.h"
#include "../src/InputManager/simpleinputmanager.h"


GameViewLocal::GameViewLocal(IGameServer * gameServer) : GameView(gameServer) {

}

// **************************************************************************************
//
// **************************************************************************************


GameViewLocal::~GameViewLocal() {
	for(auto entity : mEntities)
		GAME_DELETE(entity.second);

	mEntities.clear();
}

// **************************************************************************************
//
// **************************************************************************************

bool GameViewLocal::init() {
	bool result = GameView::init();
	GAME_ASSERT(result);
	
	mStateChangedFunctions[StateMessage::Type::EntityAdded]     = std::bind(&GameViewLocal::manageMessageEntityAdded      , this, std::placeholders::_1);
	mStateChangedFunctions[StateMessage::Type::EntityRemoved]   = std::bind(&GameViewLocal::manageMessageEntityRemoved    , this, std::placeholders::_1);
	mStateChangedFunctions[StateMessage::Type::EntityChangePos] = std::bind(&GameViewLocal::manageMessageEntityChangedPos , this, std::placeholders::_1);

	IInputManager * pInputManager = SimpleInputManager::Instance(); 
	GAME_ASSERT(pInputManager);

	pInputManager->registerToKeyboardEvent(std::bind(&GameViewLocal::manageKeyboardEvent, this, std::placeholders::_1));

	result = true;
	return result;
}

// **************************************************************************************
//
// **************************************************************************************

void GameViewLocal::update(float deltaTime) {
	clear();
	for (auto entity : mEntities)
		entity.second->update(deltaTime);
}

// **************************************************************************************
//
// **************************************************************************************

void GameViewLocal::stateChanged(const StateMessage& message) {
	if (mStateChangedFunctions.end() != mStateChangedFunctions.find(message.GetType()))
		mStateChangedFunctions[message.GetType()](message);
}

// **************************************************************************************
//
// **************************************************************************************

void GameViewLocal::manageMessageEntityAdded(const StateMessage& message) {
	const StateMessageEntityAdded& newEntityMessage = static_cast<const StateMessageEntityAdded&>(message);
	
	const LogicEntity& logicEntity = newEntityMessage.GetEntity();
	LogicEntity::EntityType type = logicEntity.GetType();
	ViewEntity * viewEntity = nullptr;
	switch (type) {
		case LogicEntity::EntityType::Horse: {
			ViewEntityHorse * horse = GAME_NEW(ViewEntityHorse, (logicEntity.GetPosX(), logicEntity.GetPosY()));
			viewEntity = horse;
			break;
		}

		case LogicEntity::EntityType::Turtle: {
			ViewEntityTurtle * turtle = GAME_NEW(ViewEntityTurtle, (logicEntity.GetPosX(), logicEntity.GetPosY()));
			viewEntity = turtle;
			break;
		}
	}

	if (viewEntity)
		mEntities[logicEntity.GetId()] = viewEntity;
}

// **************************************************************************************
//
// **************************************************************************************

void GameViewLocal::manageMessageEntityRemoved(const StateMessage& message) {
	const StateMessageEntityRemoved& removeEntityMessage = static_cast<const StateMessageEntityRemoved&>(message);
	
	// TODO
}

// **************************************************************************************
//
// **************************************************************************************

void GameViewLocal::manageMessageEntityChangedPos(const StateMessage& message) {
	const StateMessageEntityChangePos& changedPosMessage = static_cast<const StateMessageEntityChangePos&>(message);
	unsigned int entityId = changedPosMessage.GetEntityId();
	if(mEntities.end() != mEntities.find(entityId))
		mEntities[entityId]->stateChanged(message);
}

// **************************************************************************************
//
// **************************************************************************************

void GameViewLocal::manageKeyboardEvent(int key) {
	switch (key) {
		case 'p': m_pGameServer->managePlayerCommand(CommandMessageGamePause());  break;
		case 'u': m_pGameServer->managePlayerCommand(CommandMessageGameResume()); break;
	}
}