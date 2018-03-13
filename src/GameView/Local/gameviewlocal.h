#ifndef __GAME_VIEW_LOCAL_H__
#define __GAME_VIEW_LOCAL_H__

#include "../gameview.h"
#include "../../Messages/statemessages.h"
#include <vector>
#include <map>
#include <functional>


class ViewEntity;

class GameViewLocal : public GameView {

public:

	GameViewLocal(IGameServer * gameServer);
	virtual ~GameViewLocal();

	virtual bool init();

	virtual void update       (float deltaTime);
	virtual void stateChanged (const StateMessage& message);

	virtual void manageKeyboardEvent(int key);

private:

	std::vector<ViewEntity *>                                                      mEntities;
	std::map<StateMessage::Type, std::function<void(const StateMessage& message)>> mStateChangedFunctions;

	virtual void manageMessageEntityAdded   (const StateMessage& message);
	virtual void manageMessageEntityRemoved (const StateMessage& message);

};


#endif