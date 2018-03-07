#ifndef __STATE_MESSAGES_H__
#define __STATE_MESSAGES_H__


class StateMessage {

public:

	enum Type {
		GameExit
	};

	StateMessage(Type type);
	virtual ~StateMessage();

	virtual Type GetType() const;


private:

	Type mType;
};

// *************************************************************************************
//
// *************************************************************************************




#endif