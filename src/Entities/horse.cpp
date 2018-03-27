#include "horse.h"
#include "consola.h"
#include <stdio.h>
#include "../Messages/commandmessages.h"


void EntityHorse::update(float deltaTime) {
	mPosX += 3;
	mPosY += 3;
	gotoxy(mPosX, mPosY);
}

// **************************************************************************************
//
// **************************************************************************************

void EntityHorse::render() {
	printf("HHHH");
	hidecursor();
}

// **************************************************************************************
//
// **************************************************************************************

void EntityHorse::manageCommand(const CommandMessage& message) {
	// TODO
}