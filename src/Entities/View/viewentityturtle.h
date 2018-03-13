#ifndef __VIEW_ENTITY_TURTLE_H__
#define __VIEW_ENTITY_TURTLE_H__

#include "viewentity.h"
#include "../../Messages/statemessages.h"


class ViewEntityTurtle : public ViewEntity {

public:

	virtual ~ViewEntityTurtle();

	virtual void update(float deltaTime);
	virtual void stateChanged (const StateMessage& message);

protected:

	int          mPosX;
	int          mPosY;
	unsigned int mId;

	void ChangePosition(const StateMessageEntityChangePos& message);
};

#endif