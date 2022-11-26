#pragma once
#include "Entity.h"
#include "Background.h"
#include "Hole.h"
class Ball :
    public Entity
{
public:
    Ball(SDL_Renderer* ren, SDL_Texture* Ball_Tx,double init_x_pos,double init_y_pos,const double ball_radius);
    void Mover(Background* BG, Hole* hole, double Var_x, double Var_y,double Velocity);
    void Gerar_Atrito(double &Velocity);
    void Dim_Tam(double Var_r);
    void Aum_Tam(double Var_r);
};

