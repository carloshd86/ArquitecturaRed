#ifndef __I_GAME_VIEW_H__
#define __I_GAME_VIEW_H__

class StateMessage;

class IGameView {

public:

	virtual bool init         ()                            = 0;
	virtual void update       (float deltaTime)             = 0;
	virtual void stateChanged (const StateMessage& message) = 0;
};


#endif