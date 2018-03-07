#ifndef __COMMAND_MESSAGES_H__
#define __COMMAND_MESSAGES_H__


class CommandMessage {

public:

	enum Type {
		GameExit
	};

	CommandMessage(Type type);
	virtual ~CommandMessage();

	virtual Type GetType() const;


private:

	Type mType;
};

// *************************************************************************************
//
// *************************************************************************************




#endif