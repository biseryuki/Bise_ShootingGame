#include "SphereCollider.h"
#include"math.h"
//コンストラクタ
SphereCollider::SphereCollider(T_Location location, float radius) {
	this->location.x = location.x;
	this->location.y = location.y;
	this->radius = radius;
}
//SphereCollider同士の当たり判定
bool SphereCollider::HitSphere(const SphereCollider* collider) const {
	//自分から、相手へのベクトル計算
	//計算で出したベクトルの大きさと、
	//自分と相手の半径の合計より
	//ベクトルの大きさが小さければ、当たっている
	// 
	//自分と相手との間のベクトル計算。
	float vevtorX = fabsf(this->location.x - collider->GetLocation().x);
	float vevtorY = fabsf(this->location.y - collider->GetLocation().y);

	//ベクトルの大きさ計算
	float vectorLength = (vevtorX * vevtorX) + (vevtorY * vevtorY);
	vectorLength = sqrtf(vectorLength);

	float sumRadius = radius + collider->Getradius();

	//当たり判定の結果を格納
	bool ret = (vectorLength < sumRadius);

	return ret;
}
//中心座標の取得
T_Location SphereCollider::GetLocation()const {
	return location;
}
//中心座標の指定
void SphereCollider::SetLocation(T_Location location) {
	this->location.x = location.x;
	this->location.y = location.y;
}
//半径の取得
float SphereCollider::Getradius() const {
	return radius;
}