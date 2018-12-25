#include "stdafx.h"
#include "DrawConsole.h"


CDrawConsole::CDrawConsole()
{
}


CDrawConsole::~CDrawConsole()
{

}

//map�迭�� x,y ���� ��� 
const int CDrawConsole::getMap(const int x, const int y)
{
	return map[x][y];
}
//map �迭�� x,y ���� n�� ���� 
void CDrawConsole::setMap(const int x, const int y, const int n)
{
	map[x][y] = n;
}


//���� ���� ���� �׷��ݴϴ�
//s : ����  l : ��� ����  �� ���� ���ݴϴ�. 
//isAttack : �Ѹ��� ���ݸ�� ���� �޾ƿɴϴ� ( true���� �־��شٸ� ������ ������ �Ķ������� ���Ѵ�. )
const void CDrawConsole::drawMap(const int &s, const int &l, const bool &isAttack)
{
	SetColor(WHITE);
	//0		�Ѹ�	//1~7	��	//8		����	//9,10  ��Ű
	for (int i = 0; i < sizeof(map) / sizeof(map[0]); i++) {
		for (int j = 0; j < sizeof(map[0]) / sizeof(map[0][0]); j++) {

			gotoXY(20 + (2 * j), i);
			SetColor(DARK_GREEN);
			if (map[i][j] == 0) { SetColor(YELLOW); cout << "��"; }
			else if (map[i][j] == 1) { cout << "��"; }
			else if (map[i][j] == 2) { cout << "��"; }
			else if (map[i][j] == 3) { cout << "��"; }
			else if (map[i][j] == 4) { cout << "��"; }
			else if (map[i][j] == 5) { cout << "��"; }
			else if (map[i][j] == 6) { SetColor(VIOLET); cout << "��"; }
			else if (map[i][j] == 7) { cout << "��"; }
			else if (map[i][j] == 8) { cout << "  "; }
			else if (map[i][j] == 9) { SetColor(WHITE); cout << "��"; }
			else if (map[i][j] == 10) { SetColor(WHITE); cout << "��"; }

			else if (map[i][j] == 11) { SetColor(RED); if (isAttack) SetColor(BLUE); cout << "��"; }
			else if (map[i][j] == 12) { SetColor(VIOLET); if (isAttack) SetColor(BLUE); cout << "��"; }
			else if (map[i][j] == 13) { SetColor(SKY_BLUE); if (isAttack) SetColor(BLUE); cout << "��"; }
			else if (map[i][j] == 14) { SetColor(WHITE); if (isAttack) SetColor(BLUE); cout << "��"; }

		}
	}
	drawScoreLife(s, l);
}
//���ھ�� �������� �׷��ݴϴ�. 
//s : ����  l : ��� ����  �� ���� ���ݴϴ�. 
const void CDrawConsole::drawScoreLife(const int &s, const int &l)
{
	SetColor(WHITE);
	gotoXY(25, 30);
	cout << "SCORE :" << s;
	gotoXY(50, 30);
	cout << "LIFE :" ;
	for (int i = 0; i < l; i++) {
		SetColor(YELLOW);
		gotoXY(60 + (3 * i), 30);
		cout << "��";
	}
}

//���� ������ �Ѹ� �ΰ� �׷��ݴϴ�. 
const void CDrawConsole::drawIntro()
{
	PlaySound(TEXT("Music//pacman_intermission.wav"), NULL, SND_ASYNC | SND_LOOP);
	thread th1([&](){drawFunc(); });
	thread th2([&](){keyListener(); });

	const string strpacman[] = {
		{"�ƢƢƢ�    ��       �ƢƢƢ�  ��        ��     ��     ��    ��"},
		{"��    ��   �� ��    �ƢƢƢƢ� �Ƣ�    �Ƣ�    �Ƣ�    �Ƣ�  ��"},
		{"�ƢƢƢ�  ��   ��  �Ƣ�        �� ��  �� ��   ��  ��   �� �� ��"},
		{"��       �ƢƢ� ��  �ƢƢƢƢ� ��  �Ƣ�  ��  �ƢƢƢ�  ��  �Ƣ�"},
		{"��      ��       ��  �ƢƢƢ�  ��   ��   �� ��      �� ��    ��"}
	};
	const string strc[] = {
		{ "  �ƢƢƢ� " },
		{ " �ƢƢƢƢ�" },
		{ "�Ƣ�       " },
		{ " �ƢƢƢƢ�" },
		{ "  �ƢƢƢ� " }
	};
	const string str1 = { "Press any key to start the game" };

	//ȭ�鿡�� Ŀ���� �Ⱥ��̰� ���ݴϴ�.
	CONSOLE_CURSOR_INFO Curinfo;
	Curinfo.dwSize = 1;
	Curinfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Curinfo);

	system("color 0E");						//������ �������� ���ݴϴ�.
	system("mode con lines=34 cols=94");	//���� ���� ũ�⸦ ���� ���ݴϴ�.
	system("cls");							//ȭ���� �����ݴϴ�.
	
	SetColor(WHITE);

	int y = 3;
	for (auto n : strpacman) {
		gotoXY(15, y++);
		cout << n;
	}
	SetColor(YELLOW);

	gotoXY(31, 25);
	cout << str1;
	y = 3;
	for (auto n : strc) {
		gotoXY(34, y++);
		cout << n;
	}
	th2.join();
	th1.join();

}

//���� ������ ��Ʈ�� ȭ�鿡�� �Ѹ��� �ִϸ��̼��� �׷��ݴϴ�.
const void CDrawConsole::drawFunc()
{
	SetColor(YELLOW);
	const string strfunc[105] = {
		{ "��                        ��" },
		{ "  ��                      ��" },
		{ "��  ��                    ��" },
		{ "�ȥ�  ��                  ��" },
		{ "�ĥȥ�  ��                ��" },
		{ "���ĥȥ�  ��              ��" },
		{ "  ���ĥȥ�  ��            ��" },
		{ "    ���ĥȥ�  ��          ��" },
		{ "      ���ĥȥ�  ��        ��" },
		{ "        ���ĥȥ�  ��      ��" },
		{ "          ���ĥȥ�  ��    ��" },
		{ "            ���ĥȥ�  ��  ��" },
		{ "              ���ĥȥ�  �ܣ�" },
		{ "                ���ĥȥ�  ��" },
		{ "                ���ĥȥء�  " },
		{ "              ���ĥȥء�    " },
		{ "              ���ĥȡ�      " },
		{ "            ���ĥȡ�        " },
		{ "            ���ġ�          " },
		{ "          ���ġ�            " },
		{ "          ����              " },
		{ "          ��                " },
		{ "        ��                  " },
		{ "      ��                    " },
		{ "    ��                      " },
		{ "  ��                        " },
		{ "��                          " },
		{ "                            " },
		{ "                            " },
		{ "��                          " },
		{ "  ��                        " },
		{ "    ��                      " },
		{ "      ��                    " },
		{ "        ��                  " },
		{ "          ��                " },
		{ "            ��              " },
		{ "              ��            " },
		{ "                ��          " },
		{ "                  ��        " },
		{ "                    ��      " },
		{ "           BliNky   ��      " },
		{ "           BliNky   ��      " },
		{ "                    ��      " },
		{ "                      ��    " },
		{ "                        ��  " },
		{ "                          ��" },
		{ "                            " },
		{ "                            " },
		{ "��                          " },
		{ "  ��                        " },
		{ "    ��                      " },
		{ "      ��                    " },
		{ "        ��                  " },
		{ "          ��                " },
		{ "            ��              " },
		{ "              ��            " },
		{ "                ��          " },
		{ "                  ��        " },
		{ "                    ��      " },
		{ "           PiNky    ��      " },
		{ "           PiNky    ��      " },
		{ "                    ��      " },
		{ "                      ��    " },
		{ "                        ��  " },
		{ "                          ��" },
		{ "                            " },
		{ "                            " },
		{ "��                          " },
		{ "  ��                        " },
		{ "    ��                      " },
		{ "      ��                    " },
		{ "        ��                  " },
		{ "          ��                " },
		{ "            ��              " },
		{ "              ��            " },
		{ "                ��          " },
		{ "                  ��        " },
		{ "                    ��      " },
		{ "           inkey    ��      " },
		{ "           inkey    ��      " },
		{ "                    ��      " },
		{ "                      ��    " },
		{ "                        ��  " },
		{ "                          ��" },
		{ "                            " },
		{ "                            " },
		{ "��                          " },
		{ "  ��                        " },
		{ "    ��                      " },
		{ "      ��                    " },
		{ "        ��                  " },
		{ "          ��                " },
		{ "            ��              " },
		{ "              ��            " },
		{ "                ��          " },
		{ "                  ��        " },
		{ "                    ��      " },
		{ "           CLyDE    ��      " },
		{ "           CLyDE    ��      " },
		{ "                    ��      " },
		{ "                      ��    " },
		{ "                        ��  " },
		{ "                          ��" },
		{ "                            " },
		{ "                            " },
	};
	while (ch == 0) {
		for (int i = 0; i < 105; i++) {

			if (i > 85)
				SetColor(WHITE);
			else if (i > 65)
				SetColor(SKY_BLUE);
			else if (i > 45)
				SetColor(VIOLET);
			else if (i > 28)
				SetColor(RED);
			else if (i > 13)
				SetColor(BLUE);
			else
				SetColor(YELLOW);

			gotoXY(30, 15);

			cout << strfunc[i];
			Sleep(200);
			if (ch != 0)
				return;
		}
	}
}


const void CDrawConsole::GetReady()
{
	const string s = "Get Ready ! ";
	SetColor(WHITE);
	gotoXY(45, 16 );
	cout << s;
}

//������ ���� �ȴٸ� 
const void CDrawConsole::drawGameEnd()
{
	PlaySound(NULL, 0, 0);
	PlaySound(TEXT("Music//pacman_death.wav"), NULL, SND_NOSTOP);

	while (true) {
		const string strgameover[] = {
			{ "�ƢƢƢ�    ��     ��        �� �ƢƢƢ� �ƢƢƢ� ��      �� �ƢƢƢ� �ƢƢƢ� " },
			{ "��         �� ��   �Ƣ�    �Ƣ� ��       ��    ��  ��    ��  ��       ��     ��" },
			{ "��  �Ƣ�  ��   ��  �� ��  �� �� �ƢƢƢ� ��    ��   ��  ��   �ƢƢƢ� �ƢƢƢ� " },
			{ "��    �� �ƢƢ� �� ��  �Ƣ�  �� ��       ��    ��    �Ƣ�    ��       ��    �� " },
			{ "�ƢƢƢƢ�       �Ƣ�   ��   �� �ƢƢƢ� �ƢƢƢ�     ��     �ƢƢƢ� ��     ��" }
		};
		SetColor(WHITE);
		int y = 12;
		for (auto n : strgameover)
		{
			gotoXY(7, y++);
			cout << n;
		}
	}
}
const void CDrawConsole::GameClear()
{
	bool flag = true;
	for (int i = 0; i < sizeof(map) / sizeof(map[0]); i++) {
		for (int j = 0; j < sizeof(map[0]) / sizeof(map[0][0]); j++) {
			if (map[i][j] == 9 || map[i][j] == 10) {
				flag = false;
			}
		}
	}
	if (flag) {
		PlaySound(NULL, 0, 0);
		PlaySound(TEXT("Music//pacman_intermission.wav"), NULL, SND_ASYNC | SND_LOOP);

		while (true) {
			const string strgameclear[] = {
				{ "  �ƢƢ� ��       �ƢƢƢ�     ��     �ƢƢƢ�  " },
				{ "��       ��       ��          �Ƣ�    ��     �� " },
				{ "��       ��       �ƢƢƢ�   ��  ��   �ƢƢƢ�  " },
				{ "��       ��       ��        �ƢƢƢ�  ��    ��  " },
				{ "  �ƢƢ� �ƢƢƢ� �ƢƢƢ� ��      �� ��     �� " }
			};

			SetColor(WHITE);
			int y = 12;
			for (auto n : strgameclear)
			{
				gotoXY(26, y++);
				cout << n;
			}
		}
	}
}


//�ܼ� ���� ���� 
void CDrawConsole::SetColor(const int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//�ܼ� Ŀ�� ��ġ ���� 
void CDrawConsole::gotoXY(int x, int y)
{
	COORD XY = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);
}

//Ű�Է��� �޾� ���ΰ������� �̵� �ϱ� ���� 
void CDrawConsole::keyListener()
{
	while (true)
	{
		ch = _getch();
		PlaySound(NULL, 0, 0);
		if (ch != 27)  break;
	}
}

//��� ����ĭ�� ����ִٸ� ���� ������ ������ ���ϵ��� �մϴ�
void CDrawConsole::wall()
{
	bool flag = true;
	for (int i = 0; i < 6; i++) {
		if (map[14][12 + i] != 8) {
			flag = false;
		}
	}
	if (flag)
		map[13][14] = map[13][15] = 6;
	else 
		map[13][14] = map[13][15] = 8;
}
