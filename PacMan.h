#pragma once
#include "Character.h"

#define UPKEY 72
#define DOWNKEY 80
#define LEFTKEY 75
#define RIGHTKEY 77

class CPacMan :
	public CCharacter
{
private:
	int pacmandirection = LEFT;		//0,1,2,3의 값을 각각 ( 왼쪽 오른쪽 위 아래 ) 받아 팩맨이 어느쪽으로 이동해야 할 상황인지 알려준다. 
	int &score;						//Game 클래스의 점수 참조  (생성자에서 값 참조 )
	bool isattack = false;
	int attackCount = 0;			//팩맨의 공격 모드 카운터 
public:
	CPacMan(int &sc, CDrawConsole &draw);
	~CPacMan();

	const int getScore() const;

	// 각각 위치로 갈수 있는지 확인하여 보내준다. 
	void moveLEFT();
	void moveRIGHT();
	void moveUP();
	void moveDOWN();

	// //팩맨의 움직임 (character 와 다른점 : 유령을 먹었을때 ) 
	bool isPacmanMoveLEFT();
	bool isPacmanMoveRIGHT();
	bool isPacmanMoveUP();
	bool isPacmanMoveDOWN();

	// //isPress 값을 확인하고 팩맨을 이동시켜준다
	void fourDirections();
	void getKeyboard();

	int getpacmandirection();
	void setpacmandirection(const int pd);

	// 팩맨이 무엇을 먹었는지에 따라 다른 경우의 수 
	void PacManEat(int item);

	bool getisGameEnd();
	void setisGameEnd(bool ge);
	// //공격모드 인지 
	bool getisAttackmode();
	void setisAttackmode(bool attackmode);

	int getAttackCount();
	void setAttackCount(int ac);
};

