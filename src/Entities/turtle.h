#ifndef __ENTITY_TURTLE_H__
#define __ENTITY_TURTLE_H__

#include "entity.h"

class CommandMessage;

class EntityTurtle : public Entity {

public:

	virtual void update(float deltaTime);
	virtual void render();

	virtual void manageCommand (const CommandMessage& message);
};

#endif