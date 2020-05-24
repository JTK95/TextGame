#pragma once

//-----------------------------
// Enemy 구조체
//-----------------------------
typedef struct _Enemy
{
	int hp;
	int xpos;
	int ypos;

	BOOL flag;
	BOOL direction; //이동 방향
} Enemy;

#define ENEMY_COUNT 8
Enemy enemy[ENEMY_COUNT];


//-----------------------------
// Enemy 초기화
//-----------------------------
void InitEnemy();


//-----------------------------
// Enemy 이동
//-----------------------------
void MoveEnemy();


//-----------------------------
// Enemy 공격
//-----------------------------
void AttackEnemy();


//-----------------------------
// Enemy 죽음
//-----------------------------
void DeleteEnemy(int xpos, int ypos, int bulletCnt);

