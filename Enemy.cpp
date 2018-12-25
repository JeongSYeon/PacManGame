#include "stdafx.h"
#include "Enemy.h"


CEnemy::CEnemy( CDrawConsole &draw)
	:CCharacter(draw)
{
}

CEnemy::~CEnemy()
{
}

//�⺻Ŭ���� character�� �޼ҵ� �������̵� 
//������ ���� Item ������ ���� �� ��ȭ�� ���� �ߴ� �ٽ� �׷��ִ� ���� 
//�Ѹ��� �Ծ��ٸ� ������ ������ ���� 
void CEnemy::moveLEFT()
{
	CCharacter::moveLEFT();
	checkGameEnd(Item);
}
void CEnemy::moveRIGHT()
{
	CCharacter::moveRIGHT();
	checkGameEnd(Item);
}
void CEnemy::moveUP()
{
	CCharacter::moveUP();
	checkGameEnd(Item);
}
void CEnemy::moveDOWN()
{
	CCharacter::moveDOWN();
	checkGameEnd(Item);

}

//���� ���ắ���� �Է� �޴´�. 
void CEnemy::setisGameEnd(const bool flag)
{
	GameEnd = flag;
}
bool CEnemy::getisGameEnd()
{
	return GameEnd;
}
void CEnemy::checkGameEnd(int item)
{
	if (item == 0) {
		Item = 8;
		GameEnd = true;
	}
}

//�⺻������ �̵��� ���������̴�.
void CEnemy::BaseMovement()
{
	if (enemy_direction == LEFT) {
		if (ismoveUP() && ismoveLEFT() && ismoveDown()) {
			randnum = rand() % 3;
			if (randnum == 0) {
				enemy_direction = LEFT;
			}
			else if (randnum == 1) {
				enemy_direction = UP;
			}
			else if (randnum == 2) {
				enemy_direction = DOWN;
			}
		}
		else if (ismoveUP() && ismoveLEFT()) {
			randnum = rand() % 2;
			if (randnum == 0) {
				enemy_direction = LEFT;
			}
			else if (randnum == 1) {
				enemy_direction = UP;
			}

		}
		else if (ismoveLEFT() && ismoveDown()) {
			randnum = rand() % 2;
			if (randnum == 0) {
				enemy_direction = LEFT;
			}
			else if (randnum == 1) {
				enemy_direction = DOWN;
			}
		}
		else if (ismoveUP() && ismoveDown()) {
			randnum = rand() % 2;
			if (randnum == 0) {
				enemy_direction = UP;
			}
			else if (randnum == 1) {
				enemy_direction = DOWN;
			}
		}
		else {
			if (ismoveRIGHT())
				enemy_direction = RIGHT;
			if (ismoveUP())
				enemy_direction = UP;
			if (ismoveLEFT())
				enemy_direction = LEFT;
			if (ismoveDown())
				enemy_direction = DOWN;
		}
	}
	else if (enemy_direction == RIGHT) {
		if (ismoveUP() && ismoveRIGHT() && ismoveDown()) {
			randnum = rand() % 3;
			if (randnum == 0) {
				enemy_direction = RIGHT;
			}
			else if (randnum == 1) {
				enemy_direction = UP;
			}
			else if (randnum == 2) {
				enemy_direction = DOWN;
			}
		}
		else if (ismoveUP() && ismoveRIGHT()) {
			randnum = rand() % 2;
			if (randnum == 0) {
				enemy_direction = RIGHT;
			}
			else if (randnum == 1) {
				enemy_direction = UP;
			}

		}
		else if (ismoveRIGHT() && ismoveDown()) {
			randnum = rand() % 2;
			if (randnum == 0) {
				enemy_direction = RIGHT;
			}
			else if (randnum == 1) {
				enemy_direction = DOWN;
			}
		}
		else if (ismoveUP() && ismoveDown()) {
			randnum = rand() % 2;
			if (randnum == 0) {
				enemy_direction = UP;
			}
			else if (randnum == 1) {
				enemy_direction = DOWN;
			}
		}
		else {
			if (ismoveLEFT())
				enemy_direction = LEFT;
			if (ismoveUP())
				enemy_direction = UP;
			if (ismoveDown())
				enemy_direction = DOWN;
			if (ismoveRIGHT())
				enemy_direction = RIGHT;
		}
	}
	else if (enemy_direction == UP) {
		if (ismoveUP() && ismoveRIGHT() && ismoveLEFT()) {
			randnum = rand() % 3;
			if (randnum == 0) {
				enemy_direction = LEFT;
			}
			else if (randnum == 1) {
				enemy_direction = RIGHT;
			}
			else if (randnum == 2) {
				enemy_direction = UP;
			}
		}
		else if (ismoveUP() && ismoveRIGHT()) {
			randnum = rand() % 2;
			if (randnum == 0) {
				enemy_direction = RIGHT;
			}
			else if (randnum == 1) {
				enemy_direction = UP;
			}

		}
		else if (ismoveRIGHT() && ismoveLEFT()) {
			randnum = rand() % 2;
			if (randnum == 0) {
				enemy_direction = LEFT;
			}
			else if (randnum == 1) {
				enemy_direction = RIGHT;
			}
		}
		else if (ismoveUP() && ismoveLEFT()) {
			randnum = rand() % 2;
			if (randnum == 0) {
				enemy_direction = LEFT;
			}
			else if (randnum == 1) {
				enemy_direction = UP;
			}
		}
		else {
			if (ismoveDown())
				enemy_direction = DOWN;
			if (ismoveUP())
				enemy_direction = UP;
			if (ismoveLEFT())
				enemy_direction = LEFT;
			if (ismoveRIGHT())
				enemy_direction = RIGHT;
		}
	}
	else if (enemy_direction == DOWN) {
		if (ismoveDown() && ismoveRIGHT() && ismoveLEFT()) {
			randnum = rand() % 3;
			if (randnum == 0) {
				enemy_direction = LEFT;
			}
			else if (randnum == 1) {
				enemy_direction = RIGHT;
			}
			else if (randnum == 2) {
				enemy_direction = DOWN;
			}
		}
		else if (ismoveDown() && ismoveRIGHT()) {
			randnum = rand() % 2;
			if (randnum == 0) {
				enemy_direction = RIGHT;
			}
			else if (randnum == 1) {
				enemy_direction = DOWN;
			}

		}
		else if (ismoveRIGHT() && ismoveLEFT()) {
			randnum = rand() % 2;
			if (randnum == 0) {
				enemy_direction = LEFT;
			}
			else if (randnum == 1) {
				enemy_direction = RIGHT;
			}
		}
		else if (ismoveDown() && ismoveLEFT()) {
			randnum = rand() % 2;
			if (randnum == 0) {
				enemy_direction = LEFT;
			}
			else if (randnum == 1) {
				enemy_direction = DOWN;
			}
		}
		else {
			if (ismoveUP())
				enemy_direction = UP;
			if (ismoveLEFT())
				enemy_direction = LEFT;
			if (ismoveDown())
				enemy_direction = DOWN;
			if (ismoveRIGHT())
				enemy_direction = RIGHT;
		}
	}
}

void CEnemy::fine_2way(int way1, int way2, int dx, int dy)
{
	if (way1 == LEFT && way2 == RIGHT) {
		if (dx > 0) {
			enemy_direction = way1;
		}
		else if (dx <0) {
			enemy_direction = way2;
		}
		else {
			randnum = rand() % 2;
			if (randnum == 0) {
				enemy_direction = way1;
			}
			else if (randnum == 1) {
				enemy_direction = way2;
			}
		}
	}
	else if (way1 == UP && way2 == DOWN) {
		if (dy > 0) {
			enemy_direction = way1;
		}
		else if (dy <0) {
			enemy_direction = way2;
		}
		else {
			randnum = rand() % 2;
			if (randnum == 0) {
				enemy_direction = way1;
			}
			else if (randnum == 1) {
				enemy_direction = way2;
			}
		}
	}
	else {
		int sx , sy ;
		if (way1 == LEFT && way2 == UP) {
			sx = +1, sy = +1;
		}
		else if (way1 == RIGHT && way2 == UP) {
			sx = -1, sy = +1;
		}
		else if (way1 == LEFT && way2 == DOWN) {
			sx = +1, sy = -1;
		}
		else if (way1 == RIGHT && way2 == DOWN) {
			sx = -1, sy = -1;
		}

		if (dx * sx > 0 && dy * sy > 0) {
			randnum = rand() % 2;
			if (randnum == 0) {
				enemy_direction = way1;
			}
			else if (randnum == 1) {
				enemy_direction = way2;
			}
		}
		else if (dx * sx > 0) {
			enemy_direction = way1;
		}
		else if (dy * sy > 0) {
			enemy_direction = way2;
		}
		else {
			//enemy_direction ���� ������ �ʴ´�. 
		}
	}
}

void CEnemy::fine_3way(int way1, int way2, int way3, int dx, int dy)
{
	int sx, sy;
	if (enemy_direction == LEFT) {
		sx = +1, sy = +1;
	}
	else if (enemy_direction == UP) {
		sx = -1, sy = +1;
	}
	else if (enemy_direction == DOWN) {
		sx = +1, sy = -1;
	}
	else if (enemy_direction == RIGHT) {
		sx = -1, sy = -1;
	}
	if (enemy_direction == LEFT || enemy_direction == RIGHT) {
		if (dx*sx > 0) {
			if (dy*sy > 0) {
				randnum = rand() % 2;
				if (randnum == 0) {
					enemy_direction = way2;
				}
				else if (randnum == 1) {
					enemy_direction = way3;
				}
			}
			else if (dy*sy < 0) {
				randnum = rand() % 2;
				if (randnum == 0) {
					enemy_direction = way1;
				}
				else if (randnum == 1) {
					enemy_direction = way2;
				}
			}
			else {
				//enemy_direction �� ��ȭ ����
			}
		}
		else if (dx*sx < 0) {
			if (dy*sy > 0) {
				enemy_direction == way3;
			}
			else if (dy*sy < 0) {
				enemy_direction == way1;
			}
			else {
				randnum = rand() % 2;
				if (randnum == 0) {
					enemy_direction = way1;
				}
				else if (randnum == 1) {
					enemy_direction = way3;
				}
			}
		}
		else {
			if (dy *sy > 0) {
				enemy_direction = way3;
			}
			else if (dy*sy < 0) {
				enemy_direction = way1;
			}
		}
	}
	else if (enemy_direction == UP || enemy_direction == DOWN) {
		if (dx*sx > 0) {
			if (dy*sy > 0) {
				randnum = rand() % 2;
				if (randnum == 0) {
					enemy_direction = way2;
				}
				else if (randnum == 1) {
					enemy_direction = way3;
				}
			}
			else if (dy*sy < 0) {
				enemy_direction = way3;
			}
			else {
				enemy_direction = way3;
			}
		}
		else if (dx*sx < 0) {
			if (dy*sy > 0) {
				randnum = rand() % 2;
				if (randnum == 0) {
					enemy_direction = way1;
				}
				else if (randnum == 1) {
					enemy_direction = way2;
				}
			}
			else if (dy*sy < 0) {
				enemy_direction == way1;
			}
			else {
				enemy_direction == way1;
			}
		}
		else {
			if (dy *sy > 0) {
				enemy_direction = way2;
			}
			else if (dy*sy < 0) {
				randnum = rand() % 2;
				if (randnum == 0) {
					enemy_direction = way1;
				}
				else if (randnum == 1) {
					enemy_direction = way3;
				}
			}
		}
	}
}

//blinky �� �Ѹ��� (x,y)��ġ�� �̵��Ѵ�, ���󰣴�. 
int CEnemy::trace( int px, int py)
{
	int ex = this->getX();
	int ey = this->getY();
	int dx = ey - py; 
	int dy = ex - px;

	if (enemy_direction == LEFT) {
		if (ismoveUP() && ismoveLEFT() && ismoveDown()) {
			fine_3way(DOWN, LEFT, UP, dx, dy);
		}
		else if (ismoveUP() && ismoveLEFT()) {
			fine_2way(LEFT, UP, dx, dy);
		}
		else if (ismoveLEFT() && ismoveDown()) {
			fine_2way(LEFT, DOWN, dx, dy);
		}
		else if (ismoveUP() && ismoveDown()) {
			fine_2way(UP, DOWN, dx, dy);
		}
		else {
			if (ismoveRIGHT())
				enemy_direction = RIGHT;
			if (ismoveUP())
				enemy_direction = UP;
			if (ismoveLEFT())
				enemy_direction = LEFT;
			if (ismoveDown())
				enemy_direction = DOWN;
		}
	}
	else if (enemy_direction == RIGHT) {
		if (ismoveUP() && ismoveRIGHT() && ismoveDown()) {
			fine_3way(UP, RIGHT, DOWN, dx, dy);
		}
		else if (ismoveUP() && ismoveRIGHT()) {
			fine_2way(RIGHT, UP, dx, dy);
		}
		else if (ismoveRIGHT() && ismoveDown()) {
			fine_2way(RIGHT, DOWN, dx, dy);
		}
		else if (ismoveUP() && ismoveDown()) {
			fine_2way(UP, DOWN, dx, dy);
		}
		else {
			if (ismoveLEFT())
				enemy_direction = LEFT;
			if (ismoveUP())
				enemy_direction = UP;
			if (ismoveDown())
				enemy_direction = DOWN;
			if (ismoveRIGHT())
				enemy_direction = RIGHT;
		}
	}
	else if (enemy_direction == UP) {
		if (ismoveUP() && ismoveRIGHT() && ismoveLEFT()) {
			fine_3way(LEFT, UP, RIGHT, dx, dy);
		}
		else if (ismoveUP() && ismoveRIGHT()) {
			fine_2way(RIGHT, UP, dx, dy);
		}
		else if (ismoveRIGHT() && ismoveLEFT()) {
			fine_2way(LEFT, RIGHT, dx, dy);
		}
		else if (ismoveUP() && ismoveLEFT()) {
			fine_2way(LEFT, UP, dx, dy);
		}
		else {
			if (ismoveDown())
				enemy_direction = DOWN;
			if (ismoveUP())
				enemy_direction = UP;
			if (ismoveLEFT())
				enemy_direction = LEFT;
			if (ismoveRIGHT())
				enemy_direction = RIGHT;
		}
	}
	else if (enemy_direction == DOWN) {
		if (ismoveDown() && ismoveRIGHT() && ismoveLEFT()) {
			fine_3way(RIGHT, DOWN, LEFT, dx, dy);
		}
		else if (ismoveDown() && ismoveRIGHT()) {
			fine_2way(RIGHT, DOWN, dx, dy);
		}
		else if (ismoveRIGHT() && ismoveLEFT()) {
			fine_2way(LEFT, RIGHT, dx, dy);
		}
		else if (ismoveDown() && ismoveLEFT()) {
			fine_2way(LEFT, DOWN, dx, dy);
		}
		else {
			if (ismoveUP())
				enemy_direction = UP;
			if (ismoveLEFT())
				enemy_direction = LEFT;
			if (ismoveDown())
				enemy_direction = DOWN;
			if (ismoveRIGHT())
				enemy_direction = RIGHT;
		}
	}

	return 0;
}

