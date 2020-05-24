#include "stdafx.h"

#include "Game.h"
#include "Render.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "main.h"


//-----------------------------
// GAME
//-----------------------------
void Game()
{
	//초기화
	cs_Init();
	InitMSG();
	InitPlayer();
	InitEnemy();
	InitBullet();

	while (!EndGame())
	{
		Buffer_Clear();

		//키보드 입력
		kb_Input();

		//로직부
		MovePlayer();
		MoveBullet();
		MoveEnemy();
		AttackEnemy();

		//출력부
		Player_Draw('A');
		Enemy_Draw('#');
		Bullet_Draw('!');
		Flip();

		Sleep(70);
	}
}

//-----------------------------
// 게임 종료 조건
//-----------------------------
BOOL EndGame()
{
	static int iCnt = 0;
	static int endEnemy = 0;

	if (enemy[iCnt].flag == FALSE)
	{
		endEnemy++;
		iCnt++;
	}

	if (player.flag == FALSE)
	{
		scene = END;
		return TRUE;
	}

	if (endEnemy >= ENEMY_COUNT)
	{
		scene = END;
		return TRUE;
	}

	return FALSE;
}
