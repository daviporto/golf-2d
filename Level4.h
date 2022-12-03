#pragma once
#include "Level.h"
#include "Timer.h"
class Level4 :
    public Level
{
private:
    Obstacle* obstacle;
    Obstacle* obstacle_1;
    Obstacle* obstacle_2;
    Obstacle* obstacle_3;
public:
    Level4();
    void Mover_Ball(double Var_x, double Var_y, bool* run) override;
    ~Level4();
};