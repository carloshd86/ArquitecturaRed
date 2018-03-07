#include "commandmessages.h"

CommandMessage::CommandMessage(Type type) :
	mType(type) {}

CommandMessage::~CommandMessage() {
}

CommandMessage::Type CommandMessage::GetType() const {
	return mType;
}
