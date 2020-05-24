#pragma once

//-------------------------------
// Player 구조체
//-------------------------------
typedef struct _Player
{
	int hp;
	int xpos;
	int ypos;

	BOOL flag;
} Player;


//-------------------------------
// Message 큐 사이즈
//-------------------------------
#define	QUEUE_SIZE 10


//-------------------------------
// Message 큐 구조체
//-------------------------------
typedef struct _queue
{
	int front;
	int rear;
	int queArr[QUEUE_SIZE];
}MsgQueue;

Player player;
MsgQueue msgQueue;

//-------------------------------
// Player 초기화
//-------------------------------
void InitPlayer();


//-------------------------------
// Message 큐 초기화
//-------------------------------
void InitMSG();


//-------------------------------
// Message EnQueue
//-------------------------------
BOOL MessageEnQueue(int key);


//-------------------------------
// Message DeQueue
//-------------------------------
BOOL MessageDeQueue(int* key);


//-------------------------------
// 키보드 입력
//-------------------------------
void kb_Input();


//-------------------------------
// Player 이동
//-------------------------------
void MovePlayer();


//-------------------------------
// Player 죽음
//-------------------------------
void DeletePlayer(int xpos, int ypos, int bulletCnt);
