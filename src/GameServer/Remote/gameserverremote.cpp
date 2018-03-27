#include "gameserverremote.h"
#include "../../Messages/commandmessages.h"
#include "../../Application/gameapplication.h"


GameServerRemote::GameServerRemote() {
}

// **************************************************************************************
//
// **************************************************************************************

GameServerRemote::~GameServerRemote() {
}

// **************************************************************************************
//
// **************************************************************************************

void GameServerRemote::update(float deltaTime) {

}

// **************************************************************************************
//
// **************************************************************************************

void GameServerRemote::managePlayerCommand(const CommandMessage& message) {
	GameServer::managePlayerCommand(message);
	if (m_bufferOutFreeSpace > 0) {
		if (!message.serialize(m_bufferOutPointer, m_bufferOutFreeSpace))
			m_bufferOutFreeSpace = 0;
	}
}

// **************************************************************************************
//
// **************************************************************************************


void GameServerRemote::sendAndReceiveNetMessages() {
	INet * pNet = GameApplication::Instance()->GetNet();

	unsigned char *pBufferIn = nullptr;
	unsigned int   iLenIn    = 0;
	bool bReceived = pNet->sendAndReceive(m_bufferOut, MAX_NET_BUFFER_SIZE - m_bufferOutFreeSpace, pBufferIn, iLenIn);

	if (bReceived && pBufferIn && iLenIn)
	{
		// Remote messages deserialization
		CommandMessage *pMessage = nullptr;
		while (pMessage = CommandMessage::getMessageFromBuffer(pBufferIn, iLenIn))
			stateChanged(*pMessage);
	}
}