#ifndef __I_GAME_SERVER_H__
#define __I_GAME_SERVER_H__

#include "../GameView/igameview.h"

class StateMessage;
class CommandMessage;

class IGameServer {

public:

	virtual bool initGame            ()                              = 0;
	virtual void update              (float deltaTime)               = 0;
	virtual void managePlayerCommand (const CommandMessage& message) = 0;
	virtual void stateChanged        (const StateMessage& message)   = 0;
	virtual void registerView        (IGameView * view)              = 0;
};


#endif