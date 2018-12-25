#include "stdafx.h"
#include "Game.h"

CGame::CGame()
{
}

CGame::~CGame()
{
	delete pacman;
}

//���� ������ �����Ѵ�. 
int CGame::Run()
{
	draw.drawIntro();					//������ �����ϸ� ��Ʈ�� ȭ���� �׷��ش�. 

	system("cls");						//��Ʈ�� ȭ�鿡�� Ű�� �Է¹޾� ���� ȭ������ ���� �Ǵ� ��� ȭ���� �ѹ� �����ش�.
	draw.drawMap(score,life);			//���� ���� �׷��ش�.(���� ������ �������� �Է¹޾� ȭ�鿡 ����ش�.)
	draw.GetReady();					//���� ������ �غ� �϶�� �޼����� ��� ����ش�.

	PlaySound(TEXT("Music//pacman_beginning.wav"), NULL, SND_NOSTOP);		//���� ��Ʈ�� ȿ����
	PlaySound(TEXT("Music//pacman_chomp.wav"), NULL, SND_ASYNC | SND_LOOP); //���� ��Ʈ�� ȿ������ ������ ������� ������ȿ���� ������ ���ѹݺ� 

	thread keythread([&]() {pacman->getKeyboard(); });		//Ű�� �׻� �Է¹޴� ������ ���� ( Ű�Է��� �Ѹ� Ŭ������ �޴´�. )
	thread Game([&]() {Gameloop(); });							//���� ���� ���� ������ ���� 
	keythread.join();											
	Game.join();												//�� �����带 �����ش�. 

	return 0;
}

//���� ���� ����
void CGame::Gameloop()
{
	//������ ���� �ɶ����� ���ѹݺ� 
	while (true) {

		//�Ѹ��� �������� �ѹ� �ҷ��ش�.
		PacManMovement();

		//�Ѹ��� ���� ��带 Ȯ���Ͽ� ���� ����� �Ѹ��� �ѹ� �� ������ �ش�.
		//�Ѹ��� ���� ����� ������ �ӵ��� �������� �پ� ��� �ȴ� 
		if (pacman->getisAttackmode()) {
			PacManMovement();
		}

		blinky->go(pacman);
		pinky->go(pacman);
		inkey->go(pacman);
		clyde->go(pacman);

		// ���ھ�, ����, ���� �׷��ش�. 
		draw.drawMap(pacman->getScore(), life, pacman->getisAttackmode());

		//������ ���� ���Ḧ Ȯ���Ѵ�.
		if (blinky->getisGameEnd() || pinky->getisGameEnd() || inkey->getisGameEnd() || clyde->getisGameEnd() || pacman->getisGameEnd()) {
			RestartGame();
		}
		
		draw.wall();				//���� ������ Ȯ���Ѵ�.
		draw.GameClear();			//���� Ŭ��� Ȯ���Ѵ�.

		Sleep(speed);
	}
}

//�Ѹ��� ������ .
void CGame::PacManMovement()
{
	//�Ѹ��� ���ݸ��� *�� ������ Ȱ��ȭ �ȴ�. �Ѹ��� �ѹ� �����϶����� 1�� ���� �ǰ�, 0�̵ȴٸ� ���ݸ��� Ǯ���� �ȴ�. 
	if (pacman->getAttackCount() > 0)
		pacman->setAttackCount((pacman->getAttackCount()) - 1);
	else if (pacman->getAttackCount() == 0)
		pacman->setisAttackmode(false);

	//�Ѹ��� �Է¹��� �Ǵ� �Է� �޾� ���� �������� �̵��Ѵ�.
	pacman->fourDirections();

	draw.drawMap(pacman->getScore(), life, pacman->getisAttackmode());

	if (blinky->getisGameEnd() || pinky->getisGameEnd() || inkey->getisGameEnd() || clyde->getisGameEnd() || pacman->getisGameEnd()) {
		RestartGame();
	}

	Sleep(speed);
}

//�Ѹ��� �װ� ������ �ٽ� ���� . ������� ���� �ٽ� �������� ������ ������ ���Ѵ�. 
//
void CGame::RestartGame()
{
	//���� ����� ���� ��� ��� 
	if (!pacman->getisAttackmode()) {
			//����� �����ִٸ� 
			if (life > 0) {
				//isGameEnd ����(������ �������� Ȯ���ϴ� ����) �ʱ�ȭ 
				blinky->setisGameEnd(false);
				pinky->setisGameEnd(false);
				inkey->setisGameEnd(false);
				clyde->setisGameEnd(false);
				pacman->setisGameEnd(false);

				//��� �ϳ� �ٿ��ش�.
				PlaySound(NULL, 0, 0);
				PlaySound(TEXT("Music//pacman_death.wav"), NULL, SND_NOSTOP);
				life--;

				//�Ѹ� Ű���� �Է°� �ʱ�ȭ ( �������� �����̰� �ִ� )
				pacman->setpacmandirection(0);

				//ĳ���͵� �� ���� 
				draw.setMap(blinky->getX(), blinky->getY(), blinky->getItem());
				draw.setMap(pinky->getX(), pinky->getY(), pinky->getItem());
				draw.setMap(inkey->getX(), inkey->getY(), inkey->getItem());
				draw.setMap(clyde->getX(), clyde->getY(), clyde->getItem());

				//ĳ���͵� item �ʱ�ȭ 
				blinky->setItem(8);
				pinky->setItem(8);
				inkey->setItem(8);
				clyde->setItem(8);

				//ĳ���͵� �ʱⰪ ���� 
				pacman->setXY(22, 15);
				blinky->setXY(12, 14);
				pinky->setXY(14, 12);
				inkey->setXY(14, 14);
				clyde->setXY(14, 16);

				draw.GetReady();
				Sleep(2000);
				PlaySound(TEXT("Music//pacman_chomp.wav"), NULL, SND_ASYNC | SND_LOOP);
			}
			//����� �������� �ʴٸ� 
			else {
				//��� ���� ���� 
				draw.drawGameEnd();
			}
	}
	// ���ݸ���� 
	else {
		//�Ѹ��� ���� ������ ������ ���� 
		int crushEnemynum = pacman->getItem();
		
		//�Ѹ��� ������ �ƴ϶� ������ �����Ŷ�� 
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

//���ݸ�忡 �ε����� ���� Ȯ���Ͽ� �� ���� �ʱ���ġ�� ��ȭ 
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
