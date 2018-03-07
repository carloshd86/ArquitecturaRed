#ifndef __GAME_VIEW_H__
#define __GAME_VIEW_H__

#include "igameview.h"

class GameView : public IGameView {

public:

	virtual void update       (float deltaTime)                    = 0;
	virtual void stateChanged (const StateMessage& message) = 0;
};


#endif