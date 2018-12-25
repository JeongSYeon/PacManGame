#include "stdafx.h"
#include "Clyde.h"

//������ �ʱⰪ ���� 
CClyde::CClyde(CDrawConsole &draw)
	:CEnemy(draw)
{
	srand(time(NULL));
	enemy_direction = rand() % 4;
	setXY(14, 16);
	setcharnum(14);
	EnemyMode = MODE_BASE;
}

CClyde::~CClyde()
{
}

// �Ѹ��� ���� �ȿ� �����ִ��� Ȯ���ϴ� �޼ҵ� 
bool CClyde::inRangePM(int x, int y)
{
	return false;
}

// ������ �������� �Ѱ��Ѵ�.
void CClyde::go(CPacMan *P)
{
	int x = P->getX();
	int y = P->getY();
	EnemyMode = MODE_BASE;

	if (P->getisAttackmode()) {
		EnemyMode = MODE_FLEE;
	}

	//�⺻���� ������ 
	if (EnemyMode == MODE_BASE) {
		BaseMovement();
	}
	//�߰� 
	else if (EnemyMode == MODE_TRACE) {
		trace(x, y);
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
