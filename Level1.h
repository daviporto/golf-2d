#pragma once
#include <iostream>
#include <SDL_image.h>
#include <SDL.h>
#include "Level.h"
class Level1 :
    public Level
{
public:
    Level1();
    void Mover_Ball(double Var_x, double Var_, bool * run) override;
    ~Level1();
};

