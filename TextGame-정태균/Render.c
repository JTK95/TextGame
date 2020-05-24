#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"

#include "Render.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "main.h"

#define TITLETEXT "                                            Press Any Key..."
#define LOADINGTEXT "                                              LOADING..."
#define ENDTEXT "                                                GAME OVER..."

HANDLE hConsole;

//-----------------------------
// 커서 초기화
//-----------------------------
void cs_Init()
{
	CONSOLE_CURSOR_INFO conSoleCursor;

	//커서 사이즈 및 존재여부
	conSoleCursor.dwSize = 1;
	conSoleCursor.bVisible = FALSE;

	//표준콘솔 출력 핸들 반환
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hConsole, &conSoleCursor);
}


//-----------------------------
// 마우스 커서 위치 셋팅
//-----------------------------
void cs_MovePosition(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(hConsole, coord);
}


//-----------------------------
// 버퍼 셋팅
//-----------------------------
void Buffer_Clear()
{
	int iCnt;

	memset(szBuffer, ' ', sizeof(szBuffer));
	for (iCnt = 0; iCnt < SCREEN_HEIGHT; iCnt++)
	{
		szBuffer[iCnt][SCREEN_WIDTH - 1] = '\0';
	}
}


//-----------------------------
// Title 화면
//-----------------------------
void Title_Draw()
{
	static DWORD startTime;
	static BOOL bDraw = TRUE;

	startTime = GetTickCount();
	
	if (_kbhit())
	{
		if (scene == TITLE)
		{
			scene = LOADING;
		}
	}

	if (GetTickCount() - startTime > 1000)
	{
		startTime = GetTickCount();
		bDraw = !bDraw;
	}

	if (bDraw)
	{
		if (scene == TITLE)
		{
			strcpy(szBuffer[SCREEN_HEIGHT / 2], TITLETEXT);	
		}

		startTime = GetTickCount();
		bDraw = !bDraw;

		return;
	}
	else
	{
		Buffer_Clear();
		bDraw = !bDraw;
		startTime = GetTickCount();
		
		return;
	}
}


//-----------------------------
// Loading 화면
//-----------------------------
void Loading_Draw()
{
	static int iCnt = 0;
	static DWORD loadingTime;
	static BOOL bDraw = TRUE;
	loadingTime = GetTickCount();

	if (GetTickCount() - loadingTime > 1000)
	{
		loadingTime = GetTickCount();
		bDraw = !bDraw;
	}
	
	if (bDraw)
	{
		if (scene == LOADING)
		{
			iCnt++;
			strcpy(szBuffer[SCREEN_HEIGHT / 2], LOADINGTEXT);
			if (iCnt == 3)
			{
				scene = GAME;
			}
		}

		loadingTime = GetTickCount();
		bDraw = !bDraw;

		return;
	}
	else
	{
		Buffer_Clear();
		bDraw = !bDraw;
		loadingTime = GetTickCount();

		return;
	}

}


//-----------------------------
// End 화면
//-----------------------------
void End_Draw()
{
	static int iCnt = 0;
	static DWORD endTime;
	static BOOL bDraw = TRUE;

	endTime = GetTickCount();

	if (GetTickCount() - endTime > 1000)
	{
		endTime = GetTickCount();
		bDraw = !bDraw;
	}

	if (bDraw)
	{
		if (scene == END)
		{
			iCnt++;
			if (iCnt >= 7)
			{
				return;
			}

			strcpy(szBuffer[SCREEN_HEIGHT / 2], ENDTEXT);
		}

		endTime = GetTickCount();
		bDraw = !bDraw;

		return;
	}
	else
	{
		Buffer_Clear();
		bDraw = !bDraw;
		endTime = GetTickCount();

		return;
	}

}


//-----------------------------
// Player 출력
//-----------------------------
void Player_Draw(const char sprite)
{
	if (player.flag == TRUE)
	{
		szBuffer[player.ypos][player.xpos] = sprite;
	}
}


//-----------------------------
// Enemy 출력
//-----------------------------
void Enemy_Draw(const char sprite)
{
	int iCnt;

	for (iCnt = 0; iCnt < ENEMY_COUNT; iCnt++)
	{
		if (enemy[iCnt].flag == FALSE)
		{
			continue;
		}
		else
		{
			szBuffer[enemy[iCnt].ypos][enemy[iCnt].xpos] = sprite;
		}
	}
}


//-------------------------------
// (Player or Enemy) Bullet 출력
//-------------------------------
void Bullet_Draw(const char sprite)
{
	int iCnt;

	for (iCnt = 0; iCnt < BULLET_COUNT; iCnt++)
	{
		if (playerBullet[iCnt].flag == FALSE || player.flag == FALSE)
		{
			continue;
		}
		else
		{
			szBuffer[playerBullet[iCnt].ypos][playerBullet[iCnt].xpos] = sprite;
		}
	}	

	for (iCnt = 0; iCnt < BULLET_COUNT; iCnt++)
	{
		if (enemyBullet[iCnt].flag == FALSE || player.flag == FALSE)
		{
			continue;
		}
		else
		{
			szBuffer[enemyBullet[iCnt].ypos][enemyBullet[iCnt].xpos] = sprite;
		}
	}
}

//-----------------------------
// Flip
//-----------------------------
void Flip()
{
	int iCnt;

	for (iCnt = 0; iCnt < SCREEN_HEIGHT; iCnt++)
	{
		cs_MovePosition(0, iCnt);
		printf("%s", szBuffer[iCnt]);
	}
}