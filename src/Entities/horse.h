#ifndef __ENTITY_HORSE_H__
#define __ENTITY_HORSE_H__

#include "entity.h"

class EntityHorse : public Entity {

public:

	virtual void update(float deltaTime);
	virtual void render();

};

#endif