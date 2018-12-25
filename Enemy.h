#pragma once
#include "Character.h"
#include "PacMan.h"

#define MODE_BASE 0
#define MODE_TRACE 1
#define MODE_FLEE 2
class CEnemy:
	public CCharacter
{
protected:
	int EnemyMode;		// ���� ���. (0 = ��������� �����δ�. 1 = �����ȿ� ������ �߰��Ѵ�. 2 = ��������. ) (0,1�� �Ѹ��� ���� ��� 2�� ���� ��� ) 
	int enemy_direction;		//���� ��� �������� �̵������� (0,1,2,3)�� ���� ( ���� ������ �� �Ʒ� ) �� ����Ų��. 
	int randnum;		//���������޾� ��������� �̵��Ѵ�
public:
	CEnemy( CDrawConsole &draw);
	~CEnemy();

	bool getisGameEnd();
	void setisGameEnd(const bool flag);
	void checkGameEnd(int item);

	//������ ��� ������ .
	void moveLEFT();
	void moveRIGHT();
	void moveUP();
	void moveDOWN();

	void BaseMovement();
	void fine_2way(int way1, int way2, int dx, int dy);					//�߰ݽ� �ϳ��ϳ� .. ���� ���� ..
	void fine_3way(int way1, int way2, int way3, int dx, int dy);		//�߰ݽ� �ϳ��ϳ� .. ���� ���� ..
	int trace(int x, int y);	//���� ���ݸ�� : �Ѹ��� �߰� �ϴ� �޼ҵ� ������ ���ɵ��� �����̴� ��ġ�� �ٸ���.

	virtual void go(CPacMan *P) = 0;		//���� ������ . �⺻������ �������� �̵� 
	virtual bool inRangePM(int x, int y) = 0;	// �Ѹ��� ���� �ȿ� �����ִ��� Ȯ���ϴ� �޼ҵ� 
	
};

