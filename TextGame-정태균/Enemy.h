#pragma once

//-----------------------------
// Enemy ����ü
//-----------------------------
typedef struct _Enemy
{
	int hp;
	int xpos;
	int ypos;

	BOOL flag;
	BOOL direction; //�̵� ����
} Enemy;

#define ENEMY_COUNT 8
Enemy enemy[ENEMY_COUNT];


//-----------------------------
// Enemy �ʱ�ȭ
//-----------------------------
void InitEnemy();


//-----------------------------
// Enemy �̵�
//-----------------------------
void MoveEnemy();


//-----------------------------
// Enemy ����
//-----------------------------
void AttackEnemy();


//-----------------------------
// Enemy ����
//-----------------------------
void DeleteEnemy(int xpos, int ypos, int bulletCnt);

