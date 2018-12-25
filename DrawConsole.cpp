#include "stdafx.h"
#include "DrawConsole.h"


CDrawConsole::CDrawConsole()
{
}


CDrawConsole::~CDrawConsole()
{

}

//map배열의 x,y 값을 출력 
const int CDrawConsole::getMap(const int x, const int y)
{
	return map[x][y];
}
//map 배열의 x,y 값에 n을 삽입 
void CDrawConsole::setMap(const int x, const int y, const int n)
{
	map[x][y] = n;
}


//게임 메인 맵을 그려줍니다
//s : 점수  l : 목숨 개수  를 갱신 해줍니다. 
//isAttack : 팩맨의 공격모드 값을 받아옵니다 ( true값을 넣어준다면 유령의 색상이 파란색으로 변한다. )
const void CDrawConsole::drawMap(const int &s, const int &l, const bool &isAttack)
{
	SetColor(WHITE);
	//0		팩맨	//1~7	벽	//8		공백	//9,10  쿠키
	for (int i = 0; i < sizeof(map) / sizeof(map[0]); i++) {
		for (int j = 0; j < sizeof(map[0]) / sizeof(map[0][0]); j++) {

			gotoXY(20 + (2 * j), i);
			SetColor(DARK_GREEN);
			if (map[i][j] == 0) { SetColor(YELLOW); cout << "●"; }
			else if (map[i][j] == 1) { cout << "▒"; }
			else if (map[i][j] == 2) { cout << "▒"; }
			else if (map[i][j] == 3) { cout << "▒"; }
			else if (map[i][j] == 4) { cout << "▒"; }
			else if (map[i][j] == 5) { cout << "▒"; }
			else if (map[i][j] == 6) { SetColor(VIOLET); cout << "▒"; }
			else if (map[i][j] == 7) { cout << "▒"; }
			else if (map[i][j] == 8) { cout << "  "; }
			else if (map[i][j] == 9) { SetColor(WHITE); cout << "ㆍ"; }
			else if (map[i][j] == 10) { SetColor(WHITE); cout << "＊"; }

			else if (map[i][j] == 11) { SetColor(RED); if (isAttack) SetColor(BLUE); cout << "∩"; }
			else if (map[i][j] == 12) { SetColor(VIOLET); if (isAttack) SetColor(BLUE); cout << "Δ"; }
			else if (map[i][j] == 13) { SetColor(SKY_BLUE); if (isAttack) SetColor(BLUE); cout << "Θ"; }
			else if (map[i][j] == 14) { SetColor(WHITE); if (isAttack) SetColor(BLUE); cout << "Ω"; }

		}
	}
	drawScoreLife(s, l);
}
//스코어와 라이프를 그려줍니다. 
//s : 점수  l : 목숨 개수  를 갱신 해줍니다. 
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
		cout << "●";
	}
}

//게임 시작전 팩맨 로고 그려줍니다. 
const void CDrawConsole::drawIntro()
{
	PlaySound(TEXT("Music//pacman_intermission.wav"), NULL, SND_ASYNC | SND_LOOP);
	thread th1([&](){drawFunc(); });
	thread th2([&](){keyListener(); });

	const string strpacman[] = {
		{"▒▒▒▒    ▒       ▒▒▒▒  ▒        ▒     ▒     ▒    ▒"},
		{"▒    ▒   ▒ ▒    ▒▒▒▒▒ ▒▒    ▒▒    ▒▒    ▒▒  ▒"},
		{"▒▒▒▒  ▒   ▒  ▒▒        ▒ ▒  ▒ ▒   ▒  ▒   ▒ ▒ ▒"},
		{"▒       ▒▒▒ ▒  ▒▒▒▒▒ ▒  ▒▒  ▒  ▒▒▒▒  ▒  ▒▒"},
		{"▒      ▒       ▒  ▒▒▒▒  ▒   ▒   ▒ ▒      ▒ ▒    ▒"}
	};
	const string strc[] = {
		{ "  ▒▒▒▒ " },
		{ " ▒▒▒▒▒" },
		{ "▒▒       " },
		{ " ▒▒▒▒▒" },
		{ "  ▒▒▒▒ " }
	};
	const string str1 = { "Press any key to start the game" };

	//화면에서 커서를 안보이게 해줍니다.
	CONSOLE_CURSOR_INFO Curinfo;
	Curinfo.dwSize = 1;
	Curinfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Curinfo);

	system("color 0E");						//배경색을 검정으로 해줍니다.
	system("mode con lines=34 cols=94");	//가로 세로 크기를 지정 해줍니다.
	system("cls");							//화면을 지워줍니다.
	
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

//게임 시작전 인트로 화면에서 팩맨의 애니메이션을 그려줍니다.
const void CDrawConsole::drawFunc()
{
	SetColor(YELLOW);
	const string strfunc[105] = {
		{ "●                        ＊" },
		{ "  ●                      ＊" },
		{ "Ω  ●                    ＊" },
		{ "ΘΩ  ●                  ＊" },
		{ "ΔΘΩ  ●                ＊" },
		{ "∩ΔΘΩ  ●              ＊" },
		{ "  ∩ΔΘΩ  ●            ＊" },
		{ "    ∩ΔΘΩ  ●          ＊" },
		{ "      ∩ΔΘΩ  ●        ＊" },
		{ "        ∩ΔΘΩ  ●      ＊" },
		{ "          ∩ΔΘΩ  ●    ＊" },
		{ "            ∩ΔΘΩ  ●  ＊" },
		{ "              ∩ΔΘΩ  ●＊" },
		{ "                ∩ΔΘΩ  ●" },
		{ "                ∩ΔΘΩ●  " },
		{ "              ∩ΔΘΩ●    " },
		{ "              ∩ΔΘ●      " },
		{ "            ∩ΔΘ●        " },
		{ "            ∩Δ●          " },
		{ "          ∩Δ●            " },
		{ "          ∩●              " },
		{ "          ●                " },
		{ "        ●                  " },
		{ "      ●                    " },
		{ "    ●                      " },
		{ "  ●                        " },
		{ "●                          " },
		{ "                            " },
		{ "                            " },
		{ "∩                          " },
		{ "  ∩                        " },
		{ "    ∩                      " },
		{ "      ∩                    " },
		{ "        ∩                  " },
		{ "          ∩                " },
		{ "            ∩              " },
		{ "              ∩            " },
		{ "                ∩          " },
		{ "                  ∩        " },
		{ "                    ∩      " },
		{ "           BliNky   ∩      " },
		{ "           BliNky   ∩      " },
		{ "                    ∩      " },
		{ "                      ∩    " },
		{ "                        ∩  " },
		{ "                          ∩" },
		{ "                            " },
		{ "                            " },
		{ "Δ                          " },
		{ "  Δ                        " },
		{ "    Δ                      " },
		{ "      Δ                    " },
		{ "        Δ                  " },
		{ "          Δ                " },
		{ "            Δ              " },
		{ "              Δ            " },
		{ "                Δ          " },
		{ "                  Δ        " },
		{ "                    Δ      " },
		{ "           PiNky    Δ      " },
		{ "           PiNky    Δ      " },
		{ "                    Δ      " },
		{ "                      Δ    " },
		{ "                        Δ  " },
		{ "                          Δ" },
		{ "                            " },
		{ "                            " },
		{ "Θ                          " },
		{ "  Θ                        " },
		{ "    Θ                      " },
		{ "      Θ                    " },
		{ "        Θ                  " },
		{ "          Θ                " },
		{ "            Θ              " },
		{ "              Θ            " },
		{ "                Θ          " },
		{ "                  Θ        " },
		{ "                    Θ      " },
		{ "           inkey    Θ      " },
		{ "           inkey    Θ      " },
		{ "                    Θ      " },
		{ "                      Θ    " },
		{ "                        Θ  " },
		{ "                          Θ" },
		{ "                            " },
		{ "                            " },
		{ "Ω                          " },
		{ "  Ω                        " },
		{ "    Ω                      " },
		{ "      Ω                    " },
		{ "        Ω                  " },
		{ "          Ω                " },
		{ "            Ω              " },
		{ "              Ω            " },
		{ "                Ω          " },
		{ "                  Ω        " },
		{ "                    Ω      " },
		{ "           CLyDE    Ω      " },
		{ "           CLyDE    Ω      " },
		{ "                    Ω      " },
		{ "                      Ω    " },
		{ "                        Ω  " },
		{ "                          Ω" },
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

//게임이 종료 된다면 
const void CDrawConsole::drawGameEnd()
{
	PlaySound(NULL, 0, 0);
	PlaySound(TEXT("Music//pacman_death.wav"), NULL, SND_NOSTOP);

	while (true) {
		const string strgameover[] = {
			{ "▒▒▒▒    ▒     ▒        ▒ ▒▒▒▒ ▒▒▒▒ ▒      ▒ ▒▒▒▒ ▒▒▒▒ " },
			{ "▒         ▒ ▒   ▒▒    ▒▒ ▒       ▒    ▒  ▒    ▒  ▒       ▒     ▒" },
			{ "▒  ▒▒  ▒   ▒  ▒ ▒  ▒ ▒ ▒▒▒▒ ▒    ▒   ▒  ▒   ▒▒▒▒ ▒▒▒▒ " },
			{ "▒    ▒ ▒▒▒ ▒ ▒  ▒▒  ▒ ▒       ▒    ▒    ▒▒    ▒       ▒    ▒ " },
			{ "▒▒▒▒▒       ▒▒   ▒   ▒ ▒▒▒▒ ▒▒▒▒     ▒     ▒▒▒▒ ▒     ▒" }
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
				{ "  ▒▒▒ ▒       ▒▒▒▒     ▒     ▒▒▒▒  " },
				{ "▒       ▒       ▒          ▒▒    ▒     ▒ " },
				{ "▒       ▒       ▒▒▒▒   ▒  ▒   ▒▒▒▒  " },
				{ "▒       ▒       ▒        ▒▒▒▒  ▒    ▒  " },
				{ "  ▒▒▒ ▒▒▒▒ ▒▒▒▒ ▒      ▒ ▒     ▒ " }
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


//콘솔 색상 지정 
void CDrawConsole::SetColor(const int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//콘솔 커서 위치 조정 
void CDrawConsole::gotoXY(int x, int y)
{
	COORD XY = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);
}

//키입력을 받아 메인게임으로 이동 하기 위해 
void CDrawConsole::keyListener()
{
	while (true)
	{
		ch = _getch();
		PlaySound(NULL, 0, 0);
		if (ch != 27)  break;
	}
}

//가운데 유령칸이 비어있다면 벽을 생성해 들어오지 못하도록 합니다
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
