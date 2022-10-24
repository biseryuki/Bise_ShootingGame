#pragma once
#include "CharBase.h"

class Enemy :
    public CharBase
{
private:
    int hp;
    int point;
    
public:
    virtual void Update() override;
    virtual void Draw() override;
    virtual void Hit() override;
    bool HpCheck();
    int GetPoint();

};

