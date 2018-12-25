#include "stdafx.h"
#include "PacMan.h"

CPacMan::CPacMan(int &sc, CDrawConsole &draw)
	:score(sc), CCharacter(draw)
{
	setXY(22, 15);
	charnum = 0;
}

CPacMan::~CPacMan()
{
}

void CPacMan::setpacmandirection(const int pd)
{
	pacmandirection = pd;
}

int CPacMan::getpacmandirection() {
	return pacmandirection;
}

const int CPacMan::getScore() const
{
	return score;
}


//�Ѹ��� ��ĭ �̵���Ű�� ���� ���� ĭ�� �����̰ų�, ��Ű�� �ִٸ� �� �� �ִ�. 
//�Ѹ��� ������ ������ ��ȭ�� �Ծ� ������ �������ֱ� ���Ѵ�. 
void CPacMan::moveLEFT()
{
	Item = 8;
	CCharacter::moveLEFT();

	int x = this->getX(), y = this->getY();

	//�Ѹ��� ������ �Ծ��� ��� �̴�. 
	if (isPacmanMoveLEFT()) {
		draw.setMap(x, y, 8);
		Item = draw.getMap(x, y - 1);
		this->left();
		draw.setMap(x, y - 1, charnum);
	}

	PacManEat(Item);

}
void CPacMan::moveRIGHT()
{
	Item = 8;
	CCharacter::moveRIGHT();

	int x = this->getX(), y = this->getY();

	//�Ѹ��� ������ �Ծ��� ��� �̴�. 
	if (isPacmanMoveRIGHT()) {
		draw.setMap(x, y, 8);
		Item = draw.getMap(x, y + 1);
		this->right();
		draw.setMap(x, y + 1, charnum);
	}

	PacManEat(Item);
}
void CPacMan::moveUP()
{
	Item = 8;
	CCharacter::moveUP();

	int x = this->getX(), y = this->getY();

	//�Ѹ��� ������ �Ծ��� ��� �̴�. 
	if (isPacmanMoveUP()) {
		draw.setMap(x, y, 8);
		Item = draw.getMap(x - 1, y );
		this->up();
		draw.setMap(x - 1, y , charnum);
	}

	PacManEat(Item);
}
void CPacMan::moveDOWN()
{
	Item = 8;
	CCharacter::moveDOWN();

	int x = this->getX(), y = this->getY();

	//�Ѹ��� ������ �Ծ��� ��� �̴�. 
	if (isPacmanMoveDOWN()) {
		draw.setMap(x, y, 8);
		Item = draw.getMap(x+1, y );
		this->down();
		draw.setMap(x + 1, y, charnum);
	}

	PacManEat(Item);
}

// //�Ѹ��� ������ (character �� �ٸ��� : ������ �Ծ����� ) 
bool CPacMan::isPacmanMoveLEFT()
{
	int x = this->getX(), y = this->getY();

	bool flag = false;
	if (draw.getMap(x, y - 1) == 11 || draw.getMap(x, y - 1) == 12 || draw.getMap(x, y - 1) == 13 || draw.getMap(x, y - 1) == 14)
		flag = true;

	return flag;
}
bool CPacMan::isPacmanMoveRIGHT()
{
	int x = this->getX(), y = this->getY();

	bool flag = false;
	if (draw.getMap(x, y + 1) == 11 || draw.getMap(x, y + 1) == 12 || draw.getMap(x, y + 1) == 13 || draw.getMap(x, y + 1) == 14)
		flag = true;

	return flag;
}
bool CPacMan::isPacmanMoveUP()
{
	int x = this->getX(), y = this->getY();

	bool flag = false;
	if (draw.getMap(x - 1, y) == 11 || draw.getMap(x - 1, y) == 12 || draw.getMap(x - 1, y) == 13 || draw.getMap(x - 1, y ) == 14)
		flag = true;

	return flag;
}
bool CPacMan::isPacmanMoveDOWN()
{
	int x = this->getX(), y = this->getY();

	bool flag = false;
	if (draw.getMap(x + 1, y ) == 11 || draw.getMap(x + 1, y) == 12 || draw.getMap(x + 1, y ) == 13 || draw.getMap(x + 1, y ) == 14)
		flag = true;

	return flag;
}

//isPress ���� Ȯ���ϰ� �Ѹ��� �̵������ش�(������)
void CPacMan::fourDirections()
{
		if (pacmandirection == LEFT) {
			moveLEFT();
		}
		else if (pacmandirection == RIGHT) {
			moveRIGHT();
		}
		else if (pacmandirection == UP) {
			moveUP();
		}
		else if (pacmandirection == DOWN) {
			moveDOWN();
		}
}

//Ű�Է� ���� �׻� �ް� �־�� �Ѵ�. 
void CPacMan::getKeyboard()
{
	int x = this->getX();
	int y = this->getY();
	int ch;
	while (true)
	{
		ch = _getch();
		switch (ch)
		{
		case LEFTKEY:
			if (ismoveLEFT())
				pacmandirection = LEFT;
			break;
		case RIGHTKEY:
			if (ismoveRIGHT())
				pacmandirection = RIGHT;
			break;
		case UPKEY:
			if (ismoveUP())
				pacmandirection = UP;
			break;
		case DOWNKEY:
			if (ismoveDown())
				pacmandirection = DOWN;
			break;
		default: break;
		}
	}
}

// �Ѹ��� ������ �Ծ������� ���� �ٸ� ����� �� 
//�Ѹ��� ū��ȭ�� �Դ´ٸ� ������ �������� �ٲ�� �ؾ� �Ѵ�. 
//�Ҹ��� ������ �Դ´ٸ� ���ݸ�� -> ������ ������ ������ �ʱ�ȭ ĭ���� ���ư���. 
//�Ҹ��� ������ �Դ´ٸ� ������ -> �״´� .
void CPacMan::PacManEat(int item)
{
	if (item == 9) {
		score += 10;
	}
	else if (item == 10) {
		score += 50;
		isattack = true;
		attackCount = 40;
	}
	else if (item == 11 || item == 12 || item == 13 || item == 14) {
		GameEnd = true;
	}
}

bool CPacMan::getisGameEnd()
{
	return GameEnd;
}
void CPacMan::setisGameEnd(bool ge)
{
	GameEnd = ge;
}
bool CPacMan::getisAttackmode()
{
	return isattack;
}
void CPacMan::setisAttackmode(bool attackmode)
{
	isattack = attackmode;
}
int CPacMan::getAttackCount()
{
	return attackCount;
}
void CPacMan::setAttackCount(int ac)
{
	attackCount = ac;
}
