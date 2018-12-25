#pragma once
#include "Enemy.h"
class CBlinky :
	public CEnemy
{
public:
	CBlinky(CDrawConsole &draw);
	~CBlinky();

	void go(CPacMan *P);
	virtual bool inRangePM(int px, int py) ;
};

