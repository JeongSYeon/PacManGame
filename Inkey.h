#pragma once
#include "Enemy.h"
class CInkey :
	public CEnemy
{
public:
	CInkey(CDrawConsole &draw);
	~CInkey();

	void go(CPacMan *P);
	virtual bool inRangePM(int px, int py) ;
};

