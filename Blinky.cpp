#include "stdafx.h"
#include "Blinky.h"

//������ �ʱⰪ ���� 
CBlinky::CBlinky( CDrawConsole &draw)
	:CEnemy(draw)
{
	EnemyMode = MODE_BASE;
	srand((unsigned)time(NULL));
	enemy_direction = rand() % 4;		//������ ����
	setXY(12, 14);				//��ǥ ��ġ
	setcharnum(11);				//���� ��ȣ
}

CBlinky::~CBlinky()
{

}

// �Ѹ��� ���� �ȿ� �����ִ��� Ȯ���ϴ� �޼ҵ� 
bool CBlinky::inRangePM(int px, int py)
{
	int ex = this->getX();
	int ey = this->getY();

	int d = (ex - px)*(ex - px) + (ey - py)*(ey - py);

	if (sqrt(d) <= 15) {
		EnemyMode = MODE_TRACE;
	}
	return false;
}

// ������ �������� �Ѱ��Ѵ�.
void CBlinky::go(CPacMan *P)
{
	int x = P->getX();
	int y = P->getY();
	EnemyMode = MODE_BASE;
	inRangePM(x, y);

	if (P->getisAttackmode()) {
		EnemyMode = MODE_FLEE;
	}

	//�⺻���� ������ 
	if (EnemyMode == MODE_BASE) {
		BaseMovement();
	}
	//�߰� 
	else if (EnemyMode == MODE_TRACE) {
		trace( x, y);
	}
	//����
	else if (EnemyMode == MODE_FLEE) {
		int px = 30 - x;
		int py = 30 - y;
		trace( px, py);
	}

	if (!ismoveUP() && !ismoveLEFT() && !ismoveDown() && !ismoveRIGHT()) {
		//nothing
	}
	else {
		if (enemy_direction == LEFT) {
			moveLEFT();
		}
		else if (enemy_direction == RIGHT) {
			moveRIGHT();
		}
		else if (enemy_direction == UP) {
			moveUP();
		}
		else if (enemy_direction == DOWN) {
			moveDOWN();
		}
	}

}
