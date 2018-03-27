#ifndef __GAME_VIEW_H__
#define __GAME_VIEW_H__

#include "igameview.h"
#include "../GameServer/igameserver.h"


class GameView : public IGameView {

public:

	GameView(IGameServer * gameServer);
	virtual ~GameView();

	virtual bool init();

	virtual void update       (float deltaTime);
	virtual void stateChanged (const StateMessage& message);

protected:

	IGameServer *m_pGameServer;
};


#endif