#ifndef __VIEW_ENTITY_H__
#define __VIEW_ENTITY_H__


class StateMessage;

class ViewEntity {

public:

	virtual ~ViewEntity();

	virtual void update(float deltaTime) = 0;
	virtual void stateChanged (const StateMessage& message) = 0;

protected:

	int          mPosX;
	int          mPosY;
	unsigned int mId;
};

#endif