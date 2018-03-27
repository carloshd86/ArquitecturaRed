#include "simpleinputmanager.h"
#include <conio.h>
#include <stdio.h>


IInputManager * SimpleInputManager::mInstance = nullptr;


SimpleInputManager::~SimpleInputManager() {
}

// **************************************************************************************
//
// **************************************************************************************


SimpleInputManager::SimpleInputManager() {
}

// **************************************************************************************
//
// **************************************************************************************

IInputManager * SimpleInputManager::Instance() {
	if (!mInstance)
		mInstance = new SimpleInputManager();

	return mInstance;
}

// **************************************************************************************
//
// **************************************************************************************


void SimpleInputManager::registerToKeyboardEvent (std::function<void(int)> fun) {
	mRegisteredFunctions.push_back(fun);
}

// **************************************************************************************
//
// **************************************************************************************

void SimpleInputManager::update(float deltaTime) {
	int key = 0;

	if (_kbhit()) {
		key = _getch();
		for(auto it = mRegisteredFunctions.begin(); it != mRegisteredFunctions.end(); ++it)
			(*it)(key);
	}
}