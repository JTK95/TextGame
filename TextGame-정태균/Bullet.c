#include "stdafx.h"

#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "Render.h"


//-----------------------------
// Bullet √ ±‚»≠
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
// Bullet ª˝º∫
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
// Bullet ¿Ãµø
//-----------------------------
void MoveBullet()
{
	int iCnt;

	for (iCnt = 0; iCnt < BULLET_COUNT; iCnt++)
	{
		// Player∞° Ω Bullet ¡¬«• ≥—∞‹¡÷±‚
		DeleteEnemy(playerBullet[iCnt].xpos, playerBullet[iCnt].ypos, iCnt);

		// Player √—æÀ π¸¿ß
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
		// Enemy∞° Ω Bullet ¡¬«• ≥—∞‹¡÷±‚
		DeletePlayer(enemyBullet[iCnt].xpos, enemyBullet[iCnt].ypos, iCnt);

		// Enemy √—æÀ π¸¿ß
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


