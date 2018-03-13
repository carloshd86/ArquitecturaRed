#ifndef __STATE_MESSAGES_H__
#define __STATE_MESSAGES_H__


#include "../Entities/Logic/logicentity.h"


class StateMessage {

public:

	enum Type {
		GameExit,
		EntityAdded,
		EntityRemoved,
		EntityChangePos
	};

	virtual ~StateMessage();

	virtual Type GetType() const;


protected:

	StateMessage(Type type);


private:

	Type mType;
};

// *************************************************************************************
//
// *************************************************************************************

class StateMessageGameExit : public StateMessage {

public:

	StateMessageGameExit() : StateMessage(GameExit) {}
};

// *************************************************************************************
//
// *************************************************************************************

class StateMessageEntityAdded : public StateMessage {

public:

	StateMessageEntityAdded(const LogicEntity& entity) 
		: StateMessage(EntityAdded),
		mEntity(entity) {}

	const LogicEntity& GetEntity() const;


private:

	const LogicEntity& mEntity;
};

// *************************************************************************************
//
// *************************************************************************************

class StateMessageEntityRemoved : public StateMessage {

public:

	StateMessageEntityRemoved(unsigned int entityId) 
		: StateMessage(EntityRemoved),
		mEntityId(entityId) {}

	unsigned int GetEntityId() const;


private:

	unsigned int mEntityId;

};

// *************************************************************************************
//
// *************************************************************************************

class StateMessageEntityChangePos : public StateMessage {

public:

	StateMessageEntityChangePos(int posX, int posY) : 
		StateMessage(EntityChangePos),
		mPosX       (posX),
		mPosY       (posY) {}

	int GetPosX() const;
	int GetPosY() const;


private:

	int mPosX;
	int mPosY;
};

#endif