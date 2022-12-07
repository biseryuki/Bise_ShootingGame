#pragma once
#include "CharBase.h"
class Player : public CharBase
{
private:
	int score;
	int life;

public:
	Player(T_Location location);

public:
	void Update() override;
	void Draw() override;
	void Hit(int damage) override;
	void Hit(class ItemBase* item);
	bool LifeCheck();
	int GetScore();
	void AddScore(int score);
};

