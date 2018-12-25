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
	int life = 2;				//팩맨 목숨 초기값 3개 ( 게임 종료마다 1씩 감소 되며 0이하면 게임을 종료한다. )
	int score = 0;				//점수 0점			   ( 쿠키 10점 , 큰 쿠키 50점 )
	int speed = 20;
	CDrawConsole draw;						//맵정보를 받아온다.

	CPacMan *pacman = new CPacMan(score,draw);	//팩맨의 정보를 생성한다. 점수를 참조형으로 받아 변경 시켜준다. 
	CBlinky *blinky = new CBlinky(draw);		//유령(1)의 정보를 생성한다.
	CPinky *pinky = new CPinky(draw);			//유령(2)의 정보를 생성한다.
	CInkey *inkey = new CInkey(draw);			//유령(3)의 정보를 생성한다.
	CClyde *clyde = new CClyde(draw);			//유령(4)의 정보를 생성한다.

public:
	CGame();
	~CGame();

	int Run();								//메인 게임을 돌린다 (인트로 화면 메인 게임 , 게임 종료 화면 )

	void Gameloop();						//메인 게임 루프
	void PacManMovement();					//팩맨의 움직임 ( 팩맨이 큰 만화를 먹어 유령의 속도가 느려지는 경우 사용한다. )
	void RestartGame();				//게임을 다시 시작 해야 하는지 확인하는 경우 사용한다.
	int CrushEnemy(int crushenemynum);		//팩맨이 어떤 유령과 충돌하였는지 입력받아 그 유령의 값을 변경한다. 
};

