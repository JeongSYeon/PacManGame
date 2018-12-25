#include "stdafx.h"
#include "Game.h"

CGame::CGame()
{
}

CGame::~CGame()
{
	delete pacman;
}

//메인 게임을 시작한다. 
int CGame::Run()
{
	draw.drawIntro();					//게임을 시작하면 인트로 화면을 그려준다. 

	system("cls");						//인트로 화면에서 키를 입력받아 메인 화면으로 오게 되는 경우 화면을 한번 지워준다.
	draw.drawMap(score,life);			//게임 맵을 그려준다.(맵은 점수와 라이프를 입력받아 화면에 띄어준다.)
	draw.GetReady();					//게임 시작전 준비 하라는 메세지를 잠시 띄어준다.

	PlaySound(TEXT("Music//pacman_beginning.wav"), NULL, SND_NOSTOP);		//게임 인트로 효과음
	PlaySound(TEXT("Music//pacman_chomp.wav"), NULL, SND_ASYNC | SND_LOOP); //게임 인트로 효과음이 끝나면 배경음을 스레드효과가 나도록 무한반복 

	thread keythread([&]() {pacman->getKeyboard(); });		//키를 항상 입력받는 스레드 생성 ( 키입력은 팩맨 클래스가 받는다. )
	thread Game([&]() {Gameloop(); });							//메인 게임 루프 스레드 생성 
	keythread.join();											
	Game.join();												//두 스레드를 돌려준다. 

	return 0;
}

//메인 게임 루프
void CGame::Gameloop()
{
	//게임이 종료 될때까지 무한반복 
	while (true) {

		//팩맨의 움직임을 한번 불러준다.
		PacManMovement();

		//팩맨의 공격 모드를 확인하여 공격 모드라면 팩맨을 한번 더 움직여 준다.
		//팩맨이 공격 모드라면 유령의 속도가 절반으로 줄어 들게 된다 
		if (pacman->getisAttackmode()) {
			PacManMovement();
		}

		blinky->go(pacman);
		pinky->go(pacman);
		inkey->go(pacman);
		clyde->go(pacman);

		// 스코어, 점수, 맵을 그려준다. 
		draw.drawMap(pacman->getScore(), life, pacman->getisAttackmode());

		//유령의 게임 종료를 확인한다.
		if (blinky->getisGameEnd() || pinky->getisGameEnd() || inkey->getisGameEnd() || clyde->getisGameEnd() || pacman->getisGameEnd()) {
			RestartGame();
		}
		
		draw.wall();				//유령 공간을 확인한다.
		draw.GameClear();			//게임 클리어를 확인한다.

		Sleep(speed);
	}
}

//팩맨의 움직임 .
void CGame::PacManMovement()
{
	//팩맨이 공격모드는 *를 먹으면 활성화 된다. 팩맨이 한번 움직일때마다 1씩 감소 되고, 0이된다면 공격모드는 풀리게 된다. 
	if (pacman->getAttackCount() > 0)
		pacman->setAttackCount((pacman->getAttackCount()) - 1);
	else if (pacman->getAttackCount() == 0)
		pacman->setisAttackmode(false);

	//팩맨이 입력받은 또는 입력 받아 놓은 방향으로 이동한다.
	pacman->fourDirections();

	draw.drawMap(pacman->getScore(), life, pacman->getisAttackmode());

	if (blinky->getisGameEnd() || pinky->getisGameEnd() || inkey->getisGameEnd() || clyde->getisGameEnd() || pacman->getisGameEnd()) {
		RestartGame();
	}

	Sleep(speed);
}

//팩맨이 죽고 게임을 다시 시작 . 목숨값에 따라 다시 시작할지 게임을 끝낼지 정한다. 
//
void CGame::RestartGame()
{
	//게임 종료시 수비 모드 라면 
	if (!pacman->getisAttackmode()) {
			//목숨이 남아있다면 
			if (life > 0) {
				//isGameEnd 변수(게임이 끝났는지 확인하는 변수) 초기화 
				blinky->setisGameEnd(false);
				pinky->setisGameEnd(false);
				inkey->setisGameEnd(false);
				clyde->setisGameEnd(false);
				pacman->setisGameEnd(false);

				//목숨 하나 줄여준다.
				PlaySound(NULL, 0, 0);
				PlaySound(TEXT("Music//pacman_death.wav"), NULL, SND_NOSTOP);
				life--;

				//팩맨 키보드 입력값 초기화 ( 왼쪽으로 움직이고 있다 )
				pacman->setpacmandirection(0);

				//캐릭터들 맵 제거 
				draw.setMap(blinky->getX(), blinky->getY(), blinky->getItem());
				draw.setMap(pinky->getX(), pinky->getY(), pinky->getItem());
				draw.setMap(inkey->getX(), inkey->getY(), inkey->getItem());
				draw.setMap(clyde->getX(), clyde->getY(), clyde->getItem());

				//캐릭터들 item 초기화 
				blinky->setItem(8);
				pinky->setItem(8);
				inkey->setItem(8);
				clyde->setItem(8);

				//캐릭터들 초기값 설정 
				pacman->setXY(22, 15);
				blinky->setXY(12, 14);
				pinky->setXY(14, 12);
				inkey->setXY(14, 14);
				clyde->setXY(14, 16);

				draw.GetReady();
				Sleep(2000);
				PlaySound(TEXT("Music//pacman_chomp.wav"), NULL, SND_ASYNC | SND_LOOP);
			}
			//목숨이 남아있지 않다면 
			else {
				//모든 게임 종료 
				draw.drawGameEnd();
			}
	}
	// 공격모드라면 
	else {
		//팩맨이 먹은 유령을 변수에 저장 
		int crushEnemynum = pacman->getItem();
		
		//팩맨이 먹은게 아니라 유령이 먹은거라면 
			if (blinky->getisGameEnd()) {
				crushEnemynum = 11;
			}
			else if (pinky->getisGameEnd()) {
				crushEnemynum = 12;
			}
			else if (inkey->getisGameEnd()) {
				crushEnemynum = 13;
			}
			else if (clyde->getisGameEnd()) {
				crushEnemynum = 14;
			}
			blinky->setisGameEnd(false);
			pinky->setisGameEnd(false);
			inkey->setisGameEnd(false);
			clyde->setisGameEnd(false);
			pacman->setisGameEnd(false);

			score += 200;

		CrushEnemy(crushEnemynum);
	}

}

//공격모드에 부딪히는 적을 확인하여 그 적만 초기위치로 변화 
int CGame::CrushEnemy(int Enemynum)
{
	if (Enemynum == 11) {
		draw.setMap(blinky->getX(), blinky->getY(), 8);
		blinky->setItem(8);
		blinky->setXY(12, 14);
	}
	else if (Enemynum == 12) {
		draw.setMap(pinky->getX(), pinky->getY(), 8);
		pinky->setItem(8);
		pinky->setXY(14, 12);
	}
	else if (Enemynum == 13) {
		draw.setMap(inkey->getX(), inkey->getY(), 8);
		inkey->setItem(8);
		inkey->setXY(14, 14);

	}
	else if (Enemynum == 14) {
		draw.setMap(clyde->getX(), clyde->getY(), 8);
		clyde->setItem(8);
		clyde->setXY(14, 16);
	}
	return 0;
}
