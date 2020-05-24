#pragma once

//-------------------------------
// Player ����ü
//-------------------------------
typedef struct _Player
{
	int hp;
	int xpos;
	int ypos;

	BOOL flag;
} Player;


//-------------------------------
// Message ť ������
//-------------------------------
#define	QUEUE_SIZE 10


//-------------------------------
// Message ť ����ü
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
// Player �ʱ�ȭ
//-------------------------------
void InitPlayer();


//-------------------------------
// Message ť �ʱ�ȭ
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
// Ű���� �Է�
//-------------------------------
void kb_Input();


//-------------------------------
// Player �̵�
//-------------------------------
void MovePlayer();


//-------------------------------
// Player ����
//-------------------------------
void DeletePlayer(int xpos, int ypos, int bulletCnt);
