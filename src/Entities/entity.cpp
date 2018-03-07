#include "entity.h"
#include "consola.h"


void Entity::checkScreenLimits()
{
	int screenOffsetX ;
	int screenOffsetY;
	const int consoleWidth = getConsoleWidth();
	const int consoleHeight = getConsoleHeight();
	if (mPosX >= 0) {
		screenOffsetX = consoleWidth - mPosX;
		if (screenOffsetX <= 0)
			mPosX = screenOffsetX * -1;
	} else {
		screenOffsetX = mPosX + consoleWidth;
		if (screenOffsetX >= 0)
			mPosX = screenOffsetX;
	}

	if (mPosY >= 0) {
		screenOffsetY = consoleHeight - mPosY;
		if (screenOffsetY <= 0)
			mPosY = screenOffsetY * -1;
	} else {
		screenOffsetY = mPosY + consoleHeight;
		if (screenOffsetY >= 0)
			mPosY = screenOffsetY;
	}
}

int Entity::GetPosX() const {
	return mPosX;
}

void Entity::SetPosX(int posX) {
	mPosX = posX;
}

void Entity::MovePosX(int addX) {
	mPosX += addX;
}

int Entity::GetPosY() const {
	return mPosY;
}

void Entity::SetPosY(int posX) {
	mPosY = posX;
}

void Entity::MovePosY(int addY) {
	mPosY += addY;
}