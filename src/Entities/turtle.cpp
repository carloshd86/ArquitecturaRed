#include "turtle.h"
#include "consola.h"
#include <stdio.h>

void EntityTurtle::update() {
	mPosX += 1;
	mPosY += 1;
	gotoxy(mPosX, mPosY);
}

void EntityTurtle::render() {
	printf("o");
	hidecursor();
}