#ifndef __VIEW_ENTITY_HORSE_H__
#define __VIEW_ENTITY_HORSE_H__


#include "viewentity.h"
#include "../../Messages/statemessages.h"


class ViewEntityHorse : public ViewEntity {

public:

	ViewEntityHorse(int posX, int posY);
	virtual ~ViewEntityHorse();

	virtual void update(float deltaTime);
	virtual void stateChanged (const StateMessage& message);

protected:

	int          mPosX;
	int          mPosY;
	unsigned int mId;

	void ChangePosition(const StateMessageEntityChangePos& message);
};

#endif