#ifndef __GAME_VIEW_REMOTE_H__
#define __GAME_VIEW_REMOTE_H__


#include "../gameview.h"
#include "../../Messages/statemessages.h"
#include <vector>
#include <map>
#include <functional>


class GameViewRemote : public GameView {

public:

	GameViewRemote(IGameServer * gameServer);
	virtual ~GameViewRemote();

	virtual bool init();

	virtual void update       (float deltaTime);
	virtual void stateChanged (const StateMessage& message);


private:

	static const unsigned int MAX_NET_BUFFER_SIZE = 1024;

	std::vector<CommandMessage *>m_remoteServerMessages;

	void sendAndReceiveNetMessages();
	unsigned char  m_bufferOut[MAX_NET_BUFFER_SIZE];
	unsigned char *m_bufferOutPointer;
	unsigned int   m_bufferOutFreeSpace;
};


#endif // !__GAME_VIEW_REMOTE_H__

