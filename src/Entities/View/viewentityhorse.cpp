#include "viewentityhorse.h"
#include "consola.h"
#include <stdio.h>
#include "../../Messages/statemessages.h"


ViewEntityHorse::~ViewEntityHorse() {
}

// **************************************************************************************
//
// **************************************************************************************

void ViewEntityHorse::update(float deltaTime) {
	gotoxy(mPosX, mPosY);
	printf("HHHH");
	hidecursor();
}

// **************************************************************************************
//
// **************************************************************************************

void ViewEntityHorse::stateChanged(const StateMessage& message) {
	switch (message.GetType()) {
	case  StateMessage::Type::EntityChangePos: ChangePosition(static_cast<const StateMessageEntityChangePos&>(message)); break;
	}
}

// **************************************************************************************
//
// **************************************************************************************

void ViewEntityHorse::ChangePosition(const StateMessageEntityChangePos& message) {
	mPosX = message.GetPosX();
	mPosY = message.GetPosY();
}