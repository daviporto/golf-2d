#pragma once
#include <iostream>
#include "Entity.h"
#include "Background.h"
#include "Hole.h"
#include "Obstacle.h"
class Ball :
    public Entity
{
public:
    Ball(SDL_Renderer* ren, SDL_Texture* Ball_Tx,double init_x_pos,double init_y_pos,const double ball_radius);
    void Mover(Background* BG, Hole* hole, double Var_x, double Var_y,double Velocity, bool * run);
    void Mover(Background* BG, Hole* hole, double Var_x, double Var_y, double Velocity, bool* run, Obstacle * obs, Obstacle* obs_1, Obstacle* obs_2, Obstacle* obs_3);
    void Gerar_Atrito(double &Velocity);
    void Dim_Tam(int Var_r);
    void Aum_Tam(int Var_r);
};

