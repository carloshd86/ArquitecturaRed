#include "horse.h"
#include "consola.h"
#include <stdio.h>

void EntityHorse::update() {
	mPosX += 3;
	mPosY += 3;
	gotoxy(mPosX, mPosY);
}

void EntityHorse::render() {
	printf("HHHH");
	hidecursor();
}