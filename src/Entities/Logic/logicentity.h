#ifndef __LOGIC_ENTITY_H__
#define __LOGIC_ENTITY_H__

#include "../../GameServer/igameserver.h"


class CommandMessage;

class LogicEntity {

public:

	enum EntityType {
		Horse,
		Turtle
	};

	virtual ~LogicEntity();

	virtual void update(float deltaTime) = 0;
	
	virtual void manageCommand (const CommandMessage& message) = 0;

	virtual void checkScreenLimits();

	virtual int          GetPosX () const;
	virtual int          GetPosY () const;
	virtual void         SetPos  (int posX, int posY);
	virtual void         MovePos (int addX, int addY);
	virtual unsigned int GetId   () const;
	virtual EntityType   GetType () const;

protected:

	LogicEntity(IGameServer * pGameServer, EntityType type, unsigned int id);

	int          mPosX;
	int          mPosY;
	unsigned int mId;
	EntityType   mType;

	IGameServer * m_pGameServer;
};

#endif