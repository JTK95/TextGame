#pragma once

//-----------------------------
// Bullet 구조체
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
// Bullet 초기화
//-----------------------------
void InitBullet();


//-----------------------------
// Bullet 생성
//-----------------------------
void CreateBullet(int xpos, int ypos, BOOL type);


//-----------------------------
// Bullet 이동
//-----------------------------
void MoveBullet();