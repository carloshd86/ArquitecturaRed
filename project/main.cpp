#include <conio.h>
#include <stdio.h>

int main()
{
	int key = 0;
	while(27 != key)
	{
		key = 0;
		if(_kbhit()) key = _getch();
	}

    return 0;
}

