#pragma once
#include "DrawConsole.h"
#define UP 2
#define DOWN 3
#define LEFT 0
#define RIGHT 1
class CCharacter
{
protected:
	int x, y;			//ĳ����(�Ѹ�+����)���� x,y ��ǥ
	bool GameEnd = false;							//������ �������� Ȯ���Ѵ�. 
	int charnum;		//ĳ����(�Ѹ�+����)���� ���� ��ȣ (0 = �Ѹ�     11,12,13,14  = ������ ����)
	int Item = 8;		//���ɵ��� �ؿ������ ��ȭ���� �����ص� ���� ������ �ڸ��� ����� ��ȭ�� ������ �״�� �־�� �Ѵ�. 
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

	// ĳ����(�Ѹ� + ����)���� �̵� 
	void up();
	void down();
	void left();
	void right();

	// �Ʒ��� �� �޼ҵ� ���� ĳ����(�Ѹ�+����)���� ��� �̵��� �������� Ȯ�����ִ� �޼ҵ� ���̴�. 
	bool ismoveLEFT();
	bool ismoveRIGHT();
	bool ismoveUP();
	bool ismoveDown();

	// �Ʒ��� �� �޼ҵ� ���� ĳ����(�Ѹ�+����)���� �̵��̴�. 
	virtual void moveLEFT() ;
	virtual void moveRIGHT() ;
	virtual void moveUP() ;
	virtual void moveDOWN() ;
};

