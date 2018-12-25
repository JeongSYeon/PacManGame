#pragma once
#include "Enemy.h"
class CClyde :
	public CEnemy
{
public:
	CClyde(CDrawConsole &draw);
	~CClyde();

	void go(CPacMan *P);
	virtual bool inRangePM(int x, int y) ;
};

