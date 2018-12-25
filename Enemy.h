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
	int EnemyMode;		// 적의 모드. (0 = 자유자재로 움직인다. 1 = 범위안에 들어오면 추격한다. 2 = 도망간다. ) (0,1은 팩맨이 수비 모드 2는 공격 모드 ) 
	int enemy_direction;		//현재 어느 뱡향으로 이동중인지 (0,1,2,3)은 각각 ( 왼쪽 오른쪽 위 아래 ) 를 가리킨다. 
	int randnum;		//랜덤값을받아 자유자재로 이동한다
public:
	CEnemy( CDrawConsole &draw);
	~CEnemy();

	bool getisGameEnd();
	void setisGameEnd(const bool flag);
	void checkGameEnd(int item);

	//유령의 사방 움직임 .
	void moveLEFT();
	void moveRIGHT();
	void moveUP();
	void moveDOWN();

	void BaseMovement();
	void fine_2way(int way1, int way2, int dx, int dy);					//추격시 하나하나 .. 방향 지정 ..
	void fine_3way(int way1, int way2, int way3, int dx, int dy);		//추격시 하나하나 .. 방향 지정 ..
	int trace(int x, int y);	//적의 공격모드 : 팩맨을 추격 하는 메소드 각각의 유령들은 움직이는 위치가 다르다.

	virtual void go(CPacMan *P) = 0;		//적의 움직임 . 기본적으로 자유자재 이동 
	virtual bool inRangePM(int x, int y) = 0;	// 팩맨이 범위 안에 들어와있는지 확인하는 메소드 
	
};

