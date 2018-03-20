#include "gameviewremote.h"
#include "../../Application/globals.h"
#include "../../Application/gameapplication.h"


GameViewRemote::GameViewRemote(IGameServer * gameServer) :
	GameView(gameServer) {
}

// **************************************************************************************
//
// **************************************************************************************

GameViewRemote::~GameViewRemote() {
}

// **************************************************************************************
//
// **************************************************************************************


bool GameViewRemote::init() {
}

// **************************************************************************************
//
// **************************************************************************************

void GameViewRemote::update(float deltaTime) {
	GameView::update(deltaTime);
	sendAndReceiveNetMessages();

	m_bufferOutFreeSpace = MAX_NET_BUFFER_SIZE;
	m_bufferOutPointer   = m_bufferOut;

	auto it = m_remoteServerMessages.begin();
	while (it != m_remoteServerMessages.end())
	{
		m_pGameServer->managePlayerCommand(*(*it));
		GAME_DELETE(*it);
		++it;
	}
	m_remoteServerMessages.clear();
}

// **************************************************************************************
//
// **************************************************************************************

void GameViewRemote::stateChanged(const StateMessage& message) {
	if (m_bufferOutFreeSpace > 0)
	{
		if (!message.serialize(m_bufferOutPointer, m_bufferOutFreeSpace))
			m_bufferOutFreeSpace = 0;
	}
}


// **************************************************************************************
//
// **************************************************************************************

void GameViewRemote::sendAndReceiveNetMessages() {
	INet * pNet = GameApplication::Instance()->GetNet();

	unsigned char *pBufferIn = nullptr;
	unsigned int   iLenIn    = 0;
	bool bReceived = pNet->sendAndReceive(m_bufferOut, MAX_NET_BUFFER_SIZE - m_bufferOutFreeSpace, pBufferIn, iLenIn);

	if (bReceived && pBufferIn && iLenIn)
	{
		// Remote messages deserialization
		CommandMessage *pMessage = nullptr;
		while (pMessage = CommandMessage::getMessageFromBuffer(pBufferIn, iLenIn))
			m_remoteServerMessages.push_back(pMessage);
	}
}