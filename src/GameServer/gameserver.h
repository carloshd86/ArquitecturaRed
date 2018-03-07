#ifndef __GAME_SERVER_H__
#define __GAME_SERVER_H__

#include "igameserver.h"
#include "../GameView/igameview.h"
#include <vector>

class Entity;

class GameServer : public IGameServer {

public:

	GameServer();
	~GameServer();

	virtual bool initGame            ();
	virtual void update              (float deltaTime);
	virtual void managePlayerCommand (const CommandMessage& message);
	virtual void stateChanged        (const StateMessage& message);
	virtual void registerView        (IGameView * view);


private:

	std::vector<Entity *>    mEntities;
	std::vector<IGameView *> mViews;
};


#endif