#ifndef __GAME_SERVER_H__
#define __GAME_SERVER_H__

#include "igameserver.h"
#include "../GameView/igameview.h"
#include <vector>

class LogicEntity;

class GameServer : public IGameServer {

public:

	GameServer();
	virtual ~GameServer();

	virtual bool initGame            ();
	virtual void update              (float deltaTime);
	virtual void managePlayerCommand (const CommandMessage& message);
	virtual void stateChanged        (const StateMessage& message);
	virtual void registerView        (IGameView * view);
	virtual void addEntity           (LogicEntity * entity);
	virtual void removeAllEntities   ();
	virtual void removeEntity        (LogicEntity * entity);
	
	virtual unsigned int getNewIdentityId();

private:

	std::vector<LogicEntity *> mEntities;
	std::vector<IGameView *>   mViews;

};


#endif