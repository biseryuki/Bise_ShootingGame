#pragma once
#include "CharBase.h"

class Enemy :
    public CharBase
{
private:
    int hp;
    int point;
    int shotNum;
    
public:
    Enemy(T_Location location);

public:
    virtual void Update() override;
    virtual void Draw() override;
    virtual void Hit(int damage) override;
    bool HpCheck();
    int GetPoint();
};

