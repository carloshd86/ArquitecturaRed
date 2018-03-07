#include "statemessages.h"

StateMessage::StateMessage(Type type) :
	mType(type) {}

StateMessage::~StateMessage() {
}

StateMessage::Type StateMessage::GetType() const {
	return mType;
}