#ifndef __LOGIC_ENTITY_TURTLE_H__
#define __LOGIC_ENTITY_TURTLE_H__

#include "logicentity.h"


class LogicEntityTurtle : public LogicEntity {

public:

	LogicEntityTurtle(IGameServer * pGameServer, unsigned int id);
	virtual ~LogicEntityTurtle();

	virtual void update(float deltaTime);

	virtual void manageCommand (const CommandMessage& message);
};

#endif