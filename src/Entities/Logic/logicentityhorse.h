#ifndef __LOGIC_ENTITY_HORSE_H__
#define __LOGIC_ENTITY_HORSE_H__

#include "logicentity.h"


class LogicEntityHorse : public LogicEntity {

public:

	LogicEntityHorse(IGameServer * pGameServer, unsigned int id);
	virtual ~LogicEntityHorse();

	virtual void update(float deltaTime);

	virtual void manageCommand (const CommandMessage& message);
};

#endif