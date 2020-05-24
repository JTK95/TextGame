#include "stdafx.h"

#include "Enemy.h"
#include "Bullet.h"
#include "Render.h"


//-----------------------------
// Enemy 초기화
//-----------------------------
void InitEnemy()
{
	int iCnt;
	FILE* enemyFile;

	fopen_s(&enemyFile, "Stage1.txt", "r");
	if (enemyFile == NULL)
	{
		puts("Stage1.txt를 읽어올 수 없습니다.");
		fclose(enemyFile);
		return;
	}

	for (iCnt = 0; iCnt < ENEMY_COUNT; iCnt++)
	{
		enemy[iCnt].hp = 10;
		enemy[iCnt].flag = TRUE;
		enemy[iCnt].direction = TRUE; // 왼쪽방향

		fscanf_s(enemyFile, "Enemy = (%d, %d)\n", &enemy[iCnt].xpos, &enemy[iCnt].ypos);
	}

	fclose(enemyFile);
}


//-----------------------------
// Enemy 이동
//-----------------------------
void MoveEnemy()
{
	static int iMoveCount = 5;
	int iCnt;

	for (iCnt = 0; iCnt < ENEMY_COUNT; iCnt++)
	{
		if (enemy[iCnt].direction)
		{
			(enemy[iCnt].xpos)--;
		}
		else
		{
			(enemy[iCnt].xpos)++;
		}
	}

	iMoveCount--;

	//방향 전환
	if (iMoveCount == 0)
	{
		iMoveCount = 5;
		for (iCnt = 0; iCnt < ENEMY_COUNT; iCnt++)
		{
			enemy[iCnt].direction = !enemy[iCnt].direction;
		}
	}
}


//-----------------------------
// Enemy 공격
//-----------------------------
void AttackEnemy()
{
	int iRand;
	static int iCnt = 10;

	iCnt--;
	if (iCnt == 0)
	{
		iCnt = 10;
		iRand = rand() % ENEMY_COUNT - 1;

		if (enemy[iRand].flag == FALSE)
		{
			enemyBullet->flag = FALSE;
		}
		else
		{
			// Enemy 랜덤 번째에 총알 생성
			CreateBullet(enemy[iRand].xpos, enemy[iRand].ypos, FALSE);
		}
	}
}


//-----------------------------
// Enemy 죽음
//-----------------------------
void DeleteEnemy (int xpos, int ypos, int bulletCnt)
{
	int iCnt;

	for (iCnt = 0; iCnt < ENEMY_COUNT; iCnt++)
	{
		if (enemy[iCnt].flag == FALSE)
		{
			continue;
		}

		// 충돌 체크
		if ((enemy[iCnt].xpos == xpos) && (enemy[iCnt].ypos == ypos))
		{
			enemy[iCnt].hp -= 10;
			enemy[iCnt].flag = FALSE;
			playerBullet[bulletCnt].flag = FALSE;
			
			break;
		}
	}
}

