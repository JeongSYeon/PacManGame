#pragma comment(lib, "winmm.lib" )
#pragma once
#include "DrawConsole.h"
#include "PacMan.h"
#include "Enemy.h"
#include "Blinky.h"
#include "Pinky.h"
#include "Inkey.h"
#include "Clyde.h"

class CGame
{
	int life = 2;				//�Ѹ� ��� �ʱⰪ 3�� ( ���� ���Ḷ�� 1�� ���� �Ǹ� 0���ϸ� ������ �����Ѵ�. )
	int score = 0;				//���� 0��			   ( ��Ű 10�� , ū ��Ű 50�� )
	int speed = 20;
	CDrawConsole draw;						//�������� �޾ƿ´�.

	CPacMan *pacman = new CPacMan(score,draw);	//�Ѹ��� ������ �����Ѵ�. ������ ���������� �޾� ���� �����ش�. 
	CBlinky *blinky = new CBlinky(draw);		//����(1)�� ������ �����Ѵ�.
	CPinky *pinky = new CPinky(draw);			//����(2)�� ������ �����Ѵ�.
	CInkey *inkey = new CInkey(draw);			//����(3)�� ������ �����Ѵ�.
	CClyde *clyde = new CClyde(draw);			//����(4)�� ������ �����Ѵ�.

public:
	CGame();
	~CGame();

	int Run();								//���� ������ ������ (��Ʈ�� ȭ�� ���� ���� , ���� ���� ȭ�� )

	void Gameloop();						//���� ���� ����
	void PacManMovement();					//�Ѹ��� ������ ( �Ѹ��� ū ��ȭ�� �Ծ� ������ �ӵ��� �������� ��� ����Ѵ�. )
	void RestartGame();				//������ �ٽ� ���� �ؾ� �ϴ��� Ȯ���ϴ� ��� ����Ѵ�.
	int CrushEnemy(int crushenemynum);		//�Ѹ��� � ���ɰ� �浹�Ͽ����� �Է¹޾� �� ������ ���� �����Ѵ�. 
};

