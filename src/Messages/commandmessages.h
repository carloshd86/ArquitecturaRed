#ifndef __COMMAND_MESSAGES_H__
#define __COMMAND_MESSAGES_H__


class CommandMessage {

public:

	enum Type {
		GameExit,
		GamePause,
		GameResume
	};

	virtual ~CommandMessage();

	virtual Type GetType() const;


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