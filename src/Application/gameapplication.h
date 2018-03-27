#ifndef __GAME_APPLICATION_H__
#define __GAME_APPLICATION_H__


#include "Net\INet.h"


class GameApplication {

public:

	static GameApplication * Instance();

	INet * GetNet();

private:

	GameApplication();

	static GameApplication * m_pInstance;

	INet * m_pNet;
};

#endif
