#include "stdafx.h"
#include "Pinky.h"

//������ �ʱⰪ 
CPinky::CPinky( CDrawConsole &draw)
	:CEnemy(draw)
{
	srand(time(NULL));
	enemy_direction = rand() % 4;
	setXY(14, 12);
	setcharnum(12);
	EnemyMode = MODE_BASE;
}

CPinky::~CPinky()
{
}

// �Ѹ��� ���� �ȿ� �����ִ��� Ȯ���ϴ� �޼ҵ� 
bool CPinky::inRangePM(int px, int py)
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
void CPinky::go(CPacMan *P)
{
	int x = P->getX();
	int y = P->getY();
	EnemyMode = MODE_BASE;
	inRangePM(x, y);

	int px = x;
	int py = y;
	if (P->getpacmandirection() == LEFT) {
		px -= 5;
	}
	else if (P->getpacmandirection() == RIGHT) {
		px += 5;
	}
	else if (P->getpacmandirection() == UP) {
		py -= 5;
	}
	else if (P->getpacmandirection() == DOWN) {
		py += 5;
	}

	if (P->getisAttackmode()) {
		EnemyMode = MODE_FLEE;
	}

	//�⺻���� ������ 
	if (EnemyMode == MODE_BASE) {
		BaseMovement();
	}
	//�߰� 
	else if (EnemyMode == MODE_TRACE) {
		trace( px, py);
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
