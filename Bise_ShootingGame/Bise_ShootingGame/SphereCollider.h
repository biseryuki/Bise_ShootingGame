#pragma once
#include"common.h"
class SphereCollider {
private:
	//中心座標
	T_Location location;
	//半径
	float radius;
public:
	SphereCollider(T_Location location, float radius);
public:
	//SphereCollider同士の当たり判定
	bool HitSphere(const SphereCollider* collider) const;
	//中心座標の取得
	T_Location GetLocation()const;
	//中心座標の指定
	void SetLocation(T_Location location);
	//半径の取得
	float Getradius() const;

};