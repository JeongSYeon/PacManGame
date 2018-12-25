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


//팩맨을 한칸 이동시키기 전에 다음 칸이 공백이거나, 쿠키가 있다면 갈 수 있다. 
//팩맨의 움직임 에서는 만화를 먹어 점수를 갱신해주기 위한다. 
void CPacMan::moveLEFT()
{
	Item = 8;
	CCharacter::moveLEFT();

	int x = this->getX(), y = this->getY();

	//팩맨이 유령을 먹었을 경우 이다. 
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

	//팩맨이 유령을 먹었을 경우 이다. 
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

	//팩맨이 유령을 먹었을 경우 이다. 
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

	//팩맨이 유령을 먹었을 경우 이다. 
	if (isPacmanMoveDOWN()) {
		draw.setMap(x, y, 8);
		Item = draw.getMap(x+1, y );
		this->down();
		draw.setMap(x + 1, y, charnum);
	}

	PacManEat(Item);
}

// //팩맨의 움직임 (character 와 다른점 : 유령을 먹었을때 ) 
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

//isPress 값을 확인하고 팩맨을 이동시켜준다(스레드)
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

//키입력 값을 항상 받고 있어야 한다. 
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

// 팩맨이 무엇을 먹었는지에 따라 다른 경우의 수 
//팩맨이 큰만화를 먹는다면 유령의 공수모드바 바뀌도록 해야 한다. 
//팬맨이 유령을 먹는다면 공격모드 -> 점수가 오르며 유령은 초기화 칸으로 돌아간다. 
//팬맨이 유령을 먹는다면 수비모드 -> 죽는다 .
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
