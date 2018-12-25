#include "stdafx.h"
#include "Clyde.h"

//유령의 초기값 설정 
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

// 팩맨이 범위 안에 들어와있는지 확인하는 메소드 
bool CClyde::inRangePM(int x, int y)
{
	return false;
}

// 유령의 움직임을 총괄한다.
void CClyde::go(CPacMan *P)
{
	int x = P->getX();
	int y = P->getY();
	EnemyMode = MODE_BASE;

	if (P->getisAttackmode()) {
		EnemyMode = MODE_FLEE;
	}

	//기본적인 움직임 
	if (EnemyMode == MODE_BASE) {
		BaseMovement();
	}
	//추격 
	else if (EnemyMode == MODE_TRACE) {
		trace(x, y);
	}
	//도망
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
