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
// Ŀ�� �ʱ�ȭ
//-----------------------------
void cs_Init()
{
	CONSOLE_CURSOR_INFO conSoleCursor;

	//Ŀ�� ������ �� ���翩��
	conSoleCursor.dwSize = 1;
	conSoleCursor.bVisible = FALSE;

	//ǥ���ܼ� ��� �ڵ� ��ȯ
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hConsole, &conSoleCursor);
}


//-----------------------------
// ���콺 Ŀ�� ��ġ ����
//-----------------------------
void cs_MovePosition(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(hConsole, coord);
}


//-----------------------------
// ���� ����
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
// Title ȭ��
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
// Loading ȭ��
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
// End ȭ��
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
// Player ���
//-----------------------------
void Player_Draw(const char sprite)
{
	if (player.flag == TRUE)
	{
		szBuffer[player.ypos][player.xpos] = sprite;
	}
}


//-----------------------------
// Enemy ���
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
// (Player or Enemy) Bullet ���
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