#ifndef __GAME_SERVER_LOCAL_H__
#define __GAME_SERVER_LOCAL_H__

#include "../gameserver.h"

class GameServerLocal : public GameServer {

	virtual bool initGame            ();
	virtual void update              (float deltaTime);
	virtual void managePlayerCommand (const CommandMessage& message);
	virtual void stateChanged        (const StateMessage& message);
	virtual void registerView        (IGameView * view);
};


#endif