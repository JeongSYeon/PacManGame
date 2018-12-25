#pragma once
#include "Enemy.h"
class CPinky :
	public CEnemy
{

public:
	CPinky(CDrawConsole &draw);
	~CPinky();

	void go(CPacMan *P);
	virtual bool inRangePM(int px, int py) ;
};

