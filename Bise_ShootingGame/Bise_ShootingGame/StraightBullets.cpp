#include "StraightBullets.h"
#include "DxLib.h"
#define SCREEN_HEIGHT 720


StraightBullets::StraightBullets(T_Location location, T_Location speed)
	:BulletsBase(location, 5.f, 1, speed)
{

}

void StraightBullets::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.y -= speed.y;
	SetLocation(newLocation);
}

void StraightBullets::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, Getradius(), GetColor(255, 255, 0));
}

bool StraightBullets::isScreenOut()
{
	bool ret = ((GetLocation().y + Getradius()) <= 0);
	if (ret)
	{
		return ret;
	}
	
	ret = (SCREEN_HEIGHT <= (GetLocation().y - Getradius()));
	return ret;
}