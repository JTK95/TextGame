#include "stdafx.h"

#include "main.h"
#include "Title.h"
#include "Loading.h"
#include "Game.h"
#include "End.h"
#include "Render.h"

int main() 
{
	cs_Init();
	Buffer_Clear();
	scene = TITLE;
	while (TRUE)
	{
		switch (scene)
		{
		case TITLE:
			Title();
			break;
		case LOADING:
			Loading();
			break;
		case GAME:
			Game();
			break;
		case END:
			End();
			break;
		}

		Sleep(100);
	}

	return 0;
}