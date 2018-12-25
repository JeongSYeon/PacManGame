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
	int pacmandirection = LEFT;		//0,1,2,3�� ���� ���� ( ���� ������ �� �Ʒ� ) �޾� �Ѹ��� ��������� �̵��ؾ� �� ��Ȳ���� �˷��ش�. 
	int &score;						//Game Ŭ������ ���� ����  (�����ڿ��� �� ���� )
	bool isattack = false;
	int attackCount = 0;			//�Ѹ��� ���� ��� ī���� 
public:
	CPacMan(int &sc, CDrawConsole &draw);
	~CPacMan();

	const int getScore() const;

	// ���� ��ġ�� ���� �ִ��� Ȯ���Ͽ� �����ش�. 
	void moveLEFT();
	void moveRIGHT();
	void moveUP();
	void moveDOWN();

	// //�Ѹ��� ������ (character �� �ٸ��� : ������ �Ծ����� ) 
	bool isPacmanMoveLEFT();
	bool isPacmanMoveRIGHT();
	bool isPacmanMoveUP();
	bool isPacmanMoveDOWN();

	// //isPress ���� Ȯ���ϰ� �Ѹ��� �̵������ش�
	void fourDirections();
	void getKeyboard();

	int getpacmandirection();
	void setpacmandirection(const int pd);

	// �Ѹ��� ������ �Ծ������� ���� �ٸ� ����� �� 
	void PacManEat(int item);

	bool getisGameEnd();
	void setisGameEnd(bool ge);
	// //���ݸ�� ���� 
	bool getisAttackmode();
	void setisAttackmode(bool attackmode);

	int getAttackCount();
	void setAttackCount(int ac);
};

