#include "stdafx.h"

#include "Player.h"
#include "Bullet.h"
#include "Render.h"


//-------------------------------
// Player �ʱ�ȭ
//-------------------------------
void InitPlayer()
{
	FILE* playerFile;

	fopen_s(&playerFile, "PlayerInit.txt", "r");
	if (playerFile == NULL)
	{
		puts("PlayerInit.txt�� �о�� �� �����ϴ�.");
		fclose(playerFile);
		return;
	}

	player.hp = 10;
	player.flag = TRUE;
	fscanf_s(playerFile, "Player = (%d, %d)", &player.xpos, &player.ypos);

	fclose(playerFile);
}


//-------------------------------
// Message ť �ʱ�ȭ
//-------------------------------
void InitMSG()
{
	msgQueue.front = 0;
	msgQueue.rear = 0;
}


//-------------------------------
// MessageEnQueue
//-------------------------------
BOOL MessageEnQueue(int key)
{
	//���� ť Full
	if (((msgQueue.rear + 1) % QUEUE_SIZE) == (msgQueue.front))
	{
		return FALSE;
	}

	msgQueue.rear = (msgQueue.rear + 1) % QUEUE_SIZE;
	msgQueue.queArr[msgQueue.rear] = key;

	return TRUE;
}


//-------------------------------
// MessageDeQueue
//-------------------------------
BOOL MessageDeQueue(int* key)
{
	//���� ť Empty
	if (msgQueue.front == msgQueue.rear)
	{
		return FALSE;
	}

	msgQueue.front = (msgQueue.front + 1) % QUEUE_SIZE;
	*key = msgQueue.queArr[msgQueue.front];

	return TRUE;
}


//-------------------------------
// Ű���� �Է�
//-------------------------------
void kb_Input()
{
	if ((GetAsyncKeyState(VK_UP) & 0x8001) && (player.ypos > 0))
	{
		MessageEnQueue(VK_UP);
	}

	if ((GetAsyncKeyState(VK_DOWN) & 0x8001) && (player.ypos < SCREEN_HEIGHT - 1))
	{
		MessageEnQueue(VK_DOWN);
	}

	if ((GetAsyncKeyState(VK_LEFT) & 0x8001) && (player.xpos > 0))
	{
		MessageEnQueue(VK_LEFT);
	}

	if ((GetAsyncKeyState(VK_RIGHT) & 0x8001) && (player.xpos < SCREEN_WIDTH - 1))
	{
		MessageEnQueue(VK_RIGHT);
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8001)
	{
		CreateBullet(player.xpos, player.ypos, TRUE);
	}
}


//-------------------------------
// Player �̵�
//-------------------------------
void MovePlayer()
{
	int key;

	while (TRUE)
	{
		if (MessageDeQueue(&key))
		{
			if (key == VK_UP)
			{
				(player.ypos)--;
			}

			if (key == VK_DOWN)
			{
				(player.ypos)++;
			}

			if (key == VK_LEFT)
			{
				(player.xpos)--;
			}

			if (key == VK_RIGHT)
			{
				(player.xpos)++;
			}
		}
		else
		{
			return;
		}
	}
}


//-------------------------------
// Player ����
//-------------------------------
void DeletePlayer(int xpos, int ypos, int bulletCnt)
{
	// �浹üũ
	if ((player.xpos == xpos) && (player.ypos == ypos))
	{
		player.hp -= 10;
		player.flag = FALSE;
	}
}


