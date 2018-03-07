#ifndef __GAME_VIEW_LOCAL_H__
#define __GAME_VIEW_LOCAL_H__

#include "../gameview.h"

class GameViewLocal : public GameView {

public:

	virtual void update       (float deltaTime);
	virtual void stateChanged (const StateMessage& message);
};


#endif