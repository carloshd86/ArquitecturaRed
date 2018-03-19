#include "gameserverremote.h"
#include "../src/Messages/commandmessages.h"
#include "Net\INet.h"


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
	INet *pNet = g_pApp->getNet();

	unsigned char *pBufferIn = nullptr;
	unsigned int   iLenIn    = 0;
	bool bReceived = g_pApp->getNet()->sendAndReceive(m_bufferOut, MAX_NET_BUFFER_SIZE - m_bufferOutFreeSpace, pBufferIn, iLenIn);

	if (bReceived && pBufferIn && iLenIn)
	{
		// Remote messages deserialization
		CMessage *pMessage = nullptr;
		while (pMessage = CMessage::getMessageFromBuffer(pBufferIn, iLenIn))
			stateChanged(*pMessage);
	}
}