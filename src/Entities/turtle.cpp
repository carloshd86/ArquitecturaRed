#include "turtle.h"
#include "consola.h"
#include <stdio.h>
#include "../Messages/commandmessages.h"


void EntityTurtle::update(float deltaTime) {
	mPosX += 1;
	mPosY += 1;
	gotoxy(mPosX, mPosY);
}

// **************************************************************************************
//
// **************************************************************************************

void EntityTurtle::render() {
	printf("o");
	hidecursor();
}

// **************************************************************************************
//
// **************************************************************************************

void EntityTurtle::manageCommand(const CommandMessage& message) {
	// TODO
}