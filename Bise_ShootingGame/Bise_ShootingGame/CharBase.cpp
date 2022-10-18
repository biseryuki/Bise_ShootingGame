#include "CharBase.h"

CharBase::CharBase(T_Location location, float radius,T_Location speed)
	: SphereCollider(location, radius),speed(speed),image(nullptr)
{

}