#pragma once
#include <iostream>
#include <SDL_image.h>
#include <SDL.h>
#include "Screen.h"
#include "Ball.h"
#include "Launcher.h"
#include "Hole.h"
#include "Background.h"
class Level
{
private:
	double Time;
	int Remaining_Moves;
	double pos_ball_init_x, pos_ball_init_y, pos_hole_init_x, pos_hole_init_y;
	Launcher l;
protected:
	Ball * ball;
	Hole* hole;
	Background* BG;
public:

	void Dim_Moves();
	int Get_Remaining_Moves();
	double Get_Time();
	double Get_pos_ball_init_x();
	double Get_pos_ball_init_y();
	double Get_pos_hole_init_x();
	double Get_pos_hole_init_y();
	Launcher Get_Launcher();
	void Set_Remaining_Moves(int Rem);
	void Set_Time(double Time);
	void Set_pos_ball_init_x(double x);
	void Set_pos_ball_init_y(double y);
	void Set_pos_hole_init_x(double x);
	void Set_pos_hole_init_y(double y);
	SDL_Renderer*Get_Main_Launcher_Render();
	virtual void Mover_Ball(double Var_x, double Var_y)=0;
};

