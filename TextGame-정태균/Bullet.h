#pragma once

//-----------------------------
// Bullet ����ü
//-----------------------------
typedef struct _Bullet
{
	int xpos;
	int ypos;

	BOOL flag;
} Bullet;

#define BULLET_COUNT 50

Bullet playerBullet[BULLET_COUNT];
Bullet enemyBullet[BULLET_COUNT];


//-----------------------------
// Bullet �ʱ�ȭ
//-----------------------------
void InitBullet();


//-----------------------------
// Bullet ����
//-----------------------------
void CreateBullet(int xpos, int ypos, BOOL type);


//-----------------------------
// Bullet �̵�
//-----------------------------
void MoveBullet();