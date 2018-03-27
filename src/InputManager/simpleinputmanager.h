#ifndef __SIMPLE_INPUT_MANAGER_H__
#define __SIMPLE_INPUT_MANAGER_H__


#include "iinputmanager.h"
#include <vector>


class SimpleInputManager : public IInputManager {

public:

	virtual ~SimpleInputManager();

	static IInputManager * Instance();

	virtual void registerToKeyboardEvent (std::function<void(int)> fun);
	virtual void update                  (float deltaTime);
	
private:

	SimpleInputManager();
	static IInputManager * mInstance;

	std::vector<std::function<void(int)>> mRegisteredFunctions;
};

#endif
