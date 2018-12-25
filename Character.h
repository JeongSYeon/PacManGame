#pragma once
#include "DrawConsole.h"
#define UP 2
#define DOWN 3
#define LEFT 0
#define RIGHT 1
class CCharacter
{
protected:
	int x, y;			//캐릭터(팩맨+유령)들의 x,y 좌표
	bool GameEnd = false;							//게임이 끝났는지 확인한다. 
	int charnum;		//캐릭터(팩맨+유령)들의 고유 번호 (0 = 팩맨     11,12,13,14  = 각각의 유령)
	int Item = 8;		//유령들의 밑에저장될 만화들을 저장해둘 변수 유령이 자리를 벗어나면 만화나 공백이 그대로 있어야 한다. 
	CDrawConsole &draw;
public:
	CCharacter(CDrawConsole &draw);
	~CCharacter();

	const int getX();
	const int getY();
	void setXY(const int x, const int y);
	void setcharnum(const int n);
	const int getcharnum();
	void setItem(const int item);
	const int getItem() const;

	// 캐릭터(팩맨 + 유령)들의 이동 
	void up();
	void down();
	void left();
	void right();

	// 아래의 네 메소드 들은 캐릭터(팩맨+유령)들의 사방 이동이 가능한지 확인해주는 메소드 들이다. 
	bool ismoveLEFT();
	bool ismoveRIGHT();
	bool ismoveUP();
	bool ismoveDown();

	// 아래의 네 메소드 들은 캐릭터(팩맨+유령)들의 이동이다. 
	virtual void moveLEFT() ;
	virtual void moveRIGHT() ;
	virtual void moveUP() ;
	virtual void moveDOWN() ;
};

