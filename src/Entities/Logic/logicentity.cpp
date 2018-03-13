#include "logicentity.h"
#include "consola.h"
#include "../../Messages/statemessages.h"


LogicEntity::LogicEntity(IGameServer * pGameServer, EntityType type, unsigned int id) :
	m_pGameServer (pGameServer),
	mType         (type),
	mId           (id) {}

// **************************************************************************************
//
// **************************************************************************************

LogicEntity::~LogicEntity() {
}

// **************************************************************************************
//
// **************************************************************************************

void LogicEntity::checkScreenLimits()
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

// **************************************************************************************
//
// **************************************************************************************

int LogicEntity::GetPosX() const {
	return mPosX;
}

// **************************************************************************************
//
// **************************************************************************************

void LogicEntity::SetPos(int posX, int posY) {
	mPosX = posX;
	mPosY = posY;
	m_pGameServer->stateChanged(StateMessageEntityChangePos(posX, posY));
}

// **************************************************************************************
//
// **************************************************************************************

void LogicEntity::MovePos(int addX, int addY) {
	SetPos(mPosX + addX, mPosY + addY);
}

// **************************************************************************************
//
// **************************************************************************************

int LogicEntity::GetPosY() const {
	return mPosY;
}

// **************************************************************************************
//
// **************************************************************************************

unsigned int LogicEntity::GetId () const {
	return mId;
}

// **************************************************************************************
//
// **************************************************************************************

LogicEntity::EntityType LogicEntity::GetType() const {
	return mType;
}