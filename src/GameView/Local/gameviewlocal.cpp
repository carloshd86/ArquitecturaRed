#include "gameviewlocal.h"
#include "../../Entities/Logic/logicentity.h"
#include "../../Entities/View/viewentity.h"
#include "../../Entities/View/viewentityhorse.h"
#include "../../Entities/View/viewentityturtle.h"
#include "../../Tools/asserts.h"
#include "../../Tools/memoryleaks.h"
#include "../../Messages/commandmessages.h"


GameViewLocal::GameViewLocal(IGameServer * gameServer) : GameView(gameServer) {

}

// **************************************************************************************
//
// **************************************************************************************


GameViewLocal::~GameViewLocal() {
	for(auto entity : mEntities)
		GAME_DELETE(entity);

	mEntities.clear();
}

// **************************************************************************************
//
// **************************************************************************************

bool GameViewLocal::init() {
	bool result = GameView::init();
	GAME_ASSERT(result);
	
	mStateChangedFunctions[StateMessage::Type::EntityAdded]   = std::bind(&GameViewLocal::manageMessageEntityAdded, this, std::placeholders::_1);
	mStateChangedFunctions[StateMessage::Type::EntityRemoved] = std::bind(&GameViewLocal::manageMessageEntityAdded, this, std::placeholders::_1);

	result = true;
	return result;
}

// **************************************************************************************
//
// **************************************************************************************

void GameViewLocal::update(float deltaTime) {
	for (auto entity : mEntities)
		entity->update(deltaTime);
}

// **************************************************************************************
//
// **************************************************************************************

void GameViewLocal::stateChanged(const StateMessage& message) {
	mStateChangedFunctions[message.GetType()](message);
}

// **************************************************************************************
//
// **************************************************************************************

void GameViewLocal::manageMessageEntityAdded(const StateMessage& message) {
	const StateMessageEntityAdded& newEntityMessage = static_cast<const StateMessageEntityAdded&>(message);
	
	LogicEntity::EntityType type = newEntityMessage.GetEntity().GetType();
	ViewEntity * viewEntity = nullptr;
	switch (type) {
		case LogicEntity::EntityType::Horse: 
			ViewEntityHorse * horse = GAME_NEW(ViewEntityHorse, ());
			// TODO
			viewEntity = horse;
			break;
		case LogicEntity::EntityType::Turtle: 
			ViewEntityTurtle * turtle = GAME_NEW(ViewEntityTurtle, ());
			// TODO
			viewEntity = turtle;
			break;
	}

	if (viewEntity)
		mEntities.push_back(viewEntity);
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

void GameViewLocal::manageKeyboardEvent(int key) {
	switch (key) {
		case 'p': m_pGameServer->managePlayerCommand(CommandMessageGamePause());  break;
		case 'u': m_pGameServer->managePlayerCommand(CommandMessageGameResume()); break;
	}
}