#ifndef __STATE_MESSAGES_H__
#define __STATE_MESSAGES_H__


#include "../Entities/Logic/logicentity.h"
#include "messages.h"



class StateMessage {

public:

	enum Type {
		GameExit,
		GamePause,
		GameResume,
		EntityAdded,
		EntityRemoved,
		EntityChangePos
	};

	virtual ~StateMessage();

	virtual Type GetType() const;

	virtual bool serialize(unsigned char *&pBuffer, unsigned int &iBufferFreeSpace) const
	{
		bool bRet = true;
		bRet &= writeInt32(pBuffer, iBufferFreeSpace, mType);
		//bRet &= writeInt32(pBuffer, iBufferFreeSpace, m_uIdTargetEntity);
		return bRet;
	}

	virtual bool deserialize(unsigned char *&pBuffer, unsigned int &iBufferSize)
	{
		bool bRet = true;
		uint32_t value;
		bRet &= readInt32(pBuffer, iBufferSize, value);
		mType = (Type)value;
		//bRet &= readInt32(pBuffer, iBufferSize, value);
		//m_uIdTargetEntity = value;
		return bRet;
	}


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

class StateMessageGamePause : public StateMessage {

public:

	StateMessageGamePause() : StateMessage(GamePause) {}
};

// *************************************************************************************
//
// *************************************************************************************

class StateMessageGameResume : public StateMessage {

public:

	StateMessageGameResume() : StateMessage(GameResume) {}
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

	StateMessageEntityChangePos(int posX, int posY, unsigned int entityId) : 
		StateMessage(EntityChangePos),
		mPosX       (posX),
		mPosY       (posY),
		mEntityId   (entityId) {}

	int          GetPosX     () const;
	int          GetPosY     () const;
	unsigned int GetEntityId () const;


private:

	int          mPosX;
	int          mPosY;
	unsigned int mEntityId;
};

#endif