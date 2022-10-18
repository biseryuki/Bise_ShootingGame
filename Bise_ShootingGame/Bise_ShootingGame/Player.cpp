#include "Player.h"
#include "DxLib.h"

Player::Player(T_Location location) : CharBase(location, 10.f, T_Location{2,2}), score(0), life(10)
{

}

void Player::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.x += 1;
	SetLocation(newLocation);
}
void Player::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, Getradius(), GetColor(255, 0, 0));
}
void Player::Hit()
{

}
bool Player::LifeCheck()
{
	bool ret = (life <= 0);
	return ret;
}
int Player::GetScore()
{
	return score;
}