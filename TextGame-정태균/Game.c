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
	//�ʱ�ȭ
	cs_Init();
	InitMSG();
	InitPlayer();
	InitEnemy();
	InitBullet();

	while (!EndGame())
	{
		Buffer_Clear();

		//Ű���� �Է�
		kb_Input();

		//������
		MovePlayer();
		MoveBullet();
		MoveEnemy();
		AttackEnemy();

		//��º�
		Player_Draw('A');
		Enemy_Draw('#');
		Bullet_Draw('!');
		Flip();

		Sleep(70);
	}
}

//-----------------------------
// ���� ���� ����
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
