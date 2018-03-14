#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "../src/Tools/memoryleaks.h"
#include "../src/GameServer/igameserver.h"
#include "../src/GameServer/Local/gameserverlocal.h"
#include "../src/GameView/igameview.h"
#include "../src/GameView/Local/gameviewlocal.h"


int main()
{
	int key = 0;

	IGameServer * pGameServer = GAME_NEW(GameServerLocal , ());
	IGameView   * pGameView   = GAME_NEW(GameViewLocal   , (pGameServer));
	pGameView->init();
	pGameServer->initGame();

	while(27 != key)
	{
		key = 0;
		if(_kbhit()) key = _getch();
		pGameServer->update(1.f/60.f);
		pGameView->update(1.f/60.f);

		Sleep(17);
	}

	GAME_DELETE(pGameView);
	GAME_DELETE(pGameServer);

    return 0;
}

