#include "viewentityturtle.h"
#include "consola.h"
#include <stdio.h>


ViewEntityTurtle::~ViewEntityTurtle() {
}

// **************************************************************************************
//
// **************************************************************************************

void ViewEntityTurtle::update(float deltaTime) {
	gotoxy(mPosX, mPosY);
	printf("o");
	hidecursor();
}

// **************************************************************************************
//
// **************************************************************************************

void ViewEntityTurtle::stateChanged(const StateMessage& message) {
	switch (message.GetType()) {
		case  StateMessage::Type::EntityChangePos: ChangePosition(static_cast<const StateMessageEntityChangePos&>(message)); break;
	}
}

// **************************************************************************************
//
// **************************************************************************************

void ViewEntityTurtle::ChangePosition(const StateMessageEntityChangePos& message) {
	mPosX = message.GetPosX();
	mPosY = message.GetPosY();
}