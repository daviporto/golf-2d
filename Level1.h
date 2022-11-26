#pragma once
#include <iostream>
#include <SDL_image.h>
#include <SDL.h>
#include "Level.h"
class Level1 :
    public Level
{
private:
  
public:
    Level1();
    void Mover_Ball(double Var_x, double Var_) override;
    ~Level1();
    SDL_Texture* Get_texTarget();
};

