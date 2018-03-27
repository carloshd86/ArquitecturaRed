#ifndef __GAME_SERVER_REMOTE_H__
#define __GAME_SERVER_REMOTE_H__


#include "../gameserver.h"


class GameServerRemote : public GameServer {

public:

	GameServerRemote();
	virtual ~GameServerRemote();

	virtual void update              (float deltaTime);
	virtual void managePlayerCommand (const CommandMessage& message);


private:

	static const unsigned int MAX_NET_BUFFER_SIZE = 1024;

	unsigned char  m_bufferOut[MAX_NET_BUFFER_SIZE];
	unsigned char *m_bufferOutPointer;
	unsigned int   m_bufferOutFreeSpace;

	void           sendAndReceiveNetMessages();
};

#endif
