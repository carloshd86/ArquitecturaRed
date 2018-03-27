#ifndef __I_INPUT_MANAGER_H__
#define __I_INPUT_MANAGER_H__


#include <functional>


class IInputManager {

public:

	virtual void registerToKeyboardEvent(std::function<void(int)> fun) = 0;
	virtual void update(float deltaTime)                               = 0;
};

#endif