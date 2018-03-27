#ifndef __COMMAND_MESSAGES_H__
#define __COMMAND_MESSAGES_H__


#include "messages.h"


class CommandMessage {

public:

	enum Type {
		GameExit,
		GamePause,
		GameResume
	};

	virtual ~CommandMessage();

	virtual Type GetType() const;

	virtual bool serialize(unsigned char *&pBuffer, unsigned int &iBufferFreeSpace) const {
		bool bRet = true;
		bRet &= writeInt32(pBuffer, iBufferFreeSpace, mType);
		//bRet &= writeInt32(pBuffer, iBufferFreeSpace, m_uIdTargetEntity);
		return bRet;
	}

	virtual bool deserialize(unsigned char *&pBuffer, unsigned int &iBufferSize) {
		bool bRet = true;
		uint32_t value;
		bRet &= readInt32(pBuffer, iBufferSize, value);
		mType = (Type)value;
		//bRet &= readInt32(pBuffer, iBufferSize, value);
		//m_uIdTargetEntity = value;
		return bRet;
	}

protected:

	CommandMessage(Type type);

private:

	Type mType;
};

// *************************************************************************************
//
// *************************************************************************************

class CommandMessageGameExit : public CommandMessage {

public:

	CommandMessageGameExit() : CommandMessage(GameExit) {}
};

// *************************************************************************************
//
// *************************************************************************************

class CommandMessageGamePause : public CommandMessage {

public:

	CommandMessageGamePause() : CommandMessage(GamePause) {}
};

// *************************************************************************************
//
// *************************************************************************************

class CommandMessageGameResume : public CommandMessage {

public:

	CommandMessageGameResume() : CommandMessage(GameResume) {}
};



#endif