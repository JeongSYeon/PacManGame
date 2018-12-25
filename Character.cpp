#include "stdafx.h"
#include "Character.h"


CCharacter::CCharacter( CDrawConsole &draw)
	:draw(draw)
{
}

CCharacter::~CCharacter()
{
}

const int CCharacter::getX()
{
	return x;
}
const int CCharacter::getY()
{
	return y;
}
const int CCharacter::getcharnum()
{
	return charnum;
}
void CCharacter::setXY(const int x, const int y)
{
	this->x = x;
	this->y = y;
}
void CCharacter::setcharnum(const int n)
{
	charnum = n;
}
const int CCharacter::getItem() const
{
	return Item;
}
void CCharacter::setItem(const int item)
{
	Item = item;
}
void CCharacter::up()
{
	x--;
}
void CCharacter::down()
{
	x++;
}
void CCharacter::left()
{
	y--;
}
void CCharacter::right()
{
	y++;
}
// 공백 , 쿠키 , 팩맨이라면 갈수있다는 판단을 내린다 .
bool CCharacter::ismoveLEFT()
{
	bool flag = false;
	if (draw.getMap(x, y - 1) == 8 || draw.getMap(x, y - 1) == 9 || draw.getMap(x, y - 1) == 10 || draw.getMap(x, y - 1) == 0)
		flag = true;
	return flag;
}
bool CCharacter::ismoveRIGHT()
{
	bool flag = false;
	if (draw.getMap(x, y + 1) == 8 || draw.getMap(x, y + 1) == 9 || draw.getMap(x, y + 1) == 10 || draw.getMap(x, y + 1) == 0)
		flag = true;
	return flag;
}
bool CCharacter::ismoveUP()
{
	bool flag = false;
	if (draw.getMap(x - 1, y) == 8 || draw.getMap(x - 1, y) == 9 || draw.getMap(x - 1, y ) == 10 || draw.getMap(x-1, y) == 0)
		flag = true;
	return flag;
}
bool CCharacter::ismoveDown()
{
	bool flag = false;
	if (draw.getMap(x + 1, y) == 8 || draw.getMap(x + 1, y) == 9 || draw.getMap(x + 1 , y ) == 10 || draw.getMap(x+1, y) == 0)
		flag = true;
	return flag;
}

//갈수 있다는 판단을 내렸다면 item 을 저장한후 움직여준다.
void CCharacter::moveLEFT()
{
	int x = this->getX(), y = this->getY();
	if (x == 14 && y == 1) {
		draw.setMap(x, y, Item);
		Item = draw.getMap(x, y - 1);
		this->setXY(14, 28);
		draw.setMap(14, 28, charnum);
	}
	else if (ismoveLEFT()) {
		draw.setMap(x, y, Item);
		Item = draw.getMap(x, y - 1);
		this->left();
		draw.setMap(x, y - 1, charnum);
	}
}
void CCharacter::moveRIGHT()
{
	int x = this->getX(), y = this->getY();

	if (x == 14 && y == 28) {
		draw.setMap(x, y, Item);
		Item = draw.getMap(x, y + 1);

		this->setXY(14, 1);
		draw.setMap(14, 1, charnum);
	}
	else if (ismoveRIGHT()) {
		draw.setMap(x, y, Item);
		Item = draw.getMap(x, y + 1);

		this->right();
		draw.setMap(x, y + 1, charnum);
	}
}
void CCharacter::moveUP()
{
	int x = this->getX(), y = this->getY();
	if (ismoveUP()) {
		draw.setMap(x, y, Item);
		Item = draw.getMap(x - 1, y);

		this->up();
		draw.setMap(x - 1, y, charnum);
	}
}
void CCharacter::moveDOWN()
{
	int x = this->getX(), y = this->getY();
	if (ismoveDown()) {
		draw.setMap(x, y, Item);
		Item = draw.getMap(x + 1, y);

		this->down();
		draw.setMap(x + 1, y, charnum);
	}

}
