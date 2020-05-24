#include "stdafx.h"

#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "Render.h"


//-----------------------------
// Bullet �ʱ�ȭ
//-----------------------------
void InitBullet()
{
	int iCnt;

	for (iCnt = 0; iCnt < BULLET_COUNT; iCnt++)
	{
		playerBullet[iCnt].flag = FALSE;
		enemyBullet[iCnt].flag = FALSE;
	}
}


//-----------------------------
// Bullet ����
//-----------------------------
void CreateBullet(int xpos, int ypos, BOOL type)
{
	static int iCnt=0;
	BOOL bulletType = type;

	if (iCnt >= BULLET_COUNT)
	{
		iCnt = 0;
	}

	//Player Bullet
	if (bulletType == TRUE)
	{
		playerBullet[iCnt].flag = TRUE;

		playerBullet[iCnt].xpos = xpos;
		playerBullet[iCnt].ypos = ypos;
	}
	else //Enemy Bullet
	{
		enemyBullet[iCnt].flag = TRUE;

		enemyBullet[iCnt].xpos = xpos;
		enemyBullet[iCnt].ypos = ypos;
	}

	iCnt++;
}


//-----------------------------
// Bullet �̵�
//-----------------------------
void MoveBullet()
{
	int iCnt;

	for (iCnt = 0; iCnt < BULLET_COUNT; iCnt++)
	{
		// Player�� �� Bullet ��ǥ �Ѱ��ֱ�
		DeleteEnemy(playerBullet[iCnt].xpos, playerBullet[iCnt].ypos, iCnt);

		// Player �Ѿ� ����
		if (playerBullet[iCnt].ypos <= 0)
		{
			playerBullet[iCnt].flag = FALSE;
		}
		
		if (playerBullet[iCnt].flag == FALSE || player.flag == FALSE)
		{
			continue;
		}
		else
		{
			(playerBullet[iCnt].ypos)--;
		}
	}

	for (iCnt = 0; iCnt < BULLET_COUNT; iCnt++)
	{
		// Enemy�� �� Bullet ��ǥ �Ѱ��ֱ�
		DeletePlayer(enemyBullet[iCnt].xpos, enemyBullet[iCnt].ypos, iCnt);

		// Enemy �Ѿ� ����
		if (enemyBullet[iCnt].ypos >= SCREEN_HEIGHT)
		{
			enemyBullet[iCnt].flag = FALSE;
		}

		if (enemyBullet[iCnt].flag == FALSE || player.flag == FALSE)
		{
			continue;
		}
		else
		{
			(enemyBullet[iCnt].ypos)++;
		}
	}
}


