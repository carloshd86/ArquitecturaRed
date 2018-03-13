#ifndef __GAME_SERVER_LOCAL_H__
#define __GAME_SERVER_LOCAL_H__

#include "../gameserver.h"

class GameServerLocal : public GameServer {

public:

	GameServerLocal();
	virtual ~GameServerLocal();

	virtual bool initGame ();
};


#endif