﻿#include "Level4.h"
Level4::Level4()
{
	this->Set_pos_ball_init_x(150);
	this->Set_pos_ball_init_y(365);
	this->Set_pos_hole_init_x(492);
	this->Set_pos_hole_init_y(365);
	this->ball = new Ball(this->Get_Main_Launcher_Render(), SDL_CreateTextureFromSurface(this->Get_Main_Launcher_Render(),
		IMG_Load("Imagens_Golf\\GolfBall.png")), this->Get_pos_ball_init_x(),
		this->Get_pos_ball_init_y(), 15);

	this->hole = new Hole(this->Get_Main_Launcher_Render(), SDL_CreateTextureFromSurface(this->Get_Main_Launcher_Render(),
		IMG_Load("Imagens_Golf\\Hole.png")),
		this->Get_pos_hole_init_x(), this->Get_pos_hole_init_y(), 15);

	this->BG = new Background(0, this->Get_Main_Launcher_Render());


	this->obstacle = new Obstacle(this->Get_Main_Launcher_Render(), SDL_CreateTextureFromSurface(this->Get_Main_Launcher_Render(),
		IMG_Load("Imagens_Golf\\Obs1.png")),
		0, 534, 357, 32, 32);
	this->obstacle_1 = new Obstacle(this->Get_Main_Launcher_Render(), SDL_CreateTextureFromSurface(this->Get_Main_Launcher_Render(),
		IMG_Load("Imagens_Golf\\Obs.png")),
		1, 434, 357, 32, 32);
	this->obstacle_2 = new Obstacle(this->Get_Main_Launcher_Render(), SDL_CreateTextureFromSurface(this->Get_Main_Launcher_Render(),
		IMG_Load("Imagens_Golf\\Obs1.png")),
		1, 484, 413, 32, 32);
	this->obstacle_3 = new Obstacle(this->Get_Main_Launcher_Render(), SDL_CreateTextureFromSurface(this->Get_Main_Launcher_Render(),
		IMG_Load("Imagens_Golf\\Obs.png")),
		0, 484, 307, 32, 32);

	this->Set_Time(60);
	this->Set_Remaining_Moves(3);
	SDL_RenderClear(this->Get_Main_Launcher_Render());
	SDL_RenderCopy(this->Get_Main_Launcher_Render(), BG->Get_Tex(), NULL, BG->Get_pRect());
	SDL_RenderCopy(this->Get_Main_Launcher_Render(), hole->Get_Tex(), NULL, hole->Get_pbrect());
	SDL_RenderCopy(this->Get_Main_Launcher_Render(), obstacle->Get_Tex(), NULL, obstacle->Get_pbrect());
	SDL_RenderCopy(this->Get_Main_Launcher_Render(), obstacle_1->Get_Tex(), NULL, obstacle_1->Get_pbrect());
	SDL_RenderCopy(this->Get_Main_Launcher_Render(), obstacle_2->Get_Tex(), NULL, obstacle_2->Get_pbrect());
	SDL_RenderCopy(this->Get_Main_Launcher_Render(), obstacle_3->Get_Tex(), NULL, obstacle_3->Get_pbrect());

	SDL_RenderCopy(this->Get_Main_Launcher_Render(), SDL_CreateTextureFromSurface(this->Get_Main_Launcher_Render(),
		IMG_Load("Imagens_Golf\\Golfball.png")), NULL, this->ball->Get_pbrect());
	SDL_RenderPresent(this->Get_Main_Launcher_Render());
}
void Level4::Mover_Ball(double Var_x, double Var_y, bool* run) {

	this->Set_Remaining_Moves(this->Get_Remaining_Moves() - 1);


	SDL_RenderPresent(this->Get_Main_Launcher_Render());
	//Maximo da Velocity
	double Velocity;
	if (sqrt(pow((Var_x), 2) + pow((Var_y), 2)) / 100 > 1)
		Velocity = 1;
	else
		Velocity = sqrt(pow((Var_x), 2) + pow((Var_y), 2)) / 100;
	//Normalização das Var's
	double holder_x = Var_x, holder_y = Var_y;
	int aux_x = 1, aux_y = 1;
	if (Var_x < 0) {
		aux_x = -1;
		Var_x = Var_x * -1;
	}
	if (Var_y < 0) {
		aux_y = -1;
		Var_y = Var_y * -1;
	}
	if (Var_x > Var_y) {
		Var_y = Var_y / Var_x;
		Var_x = 1;
	}
	else {
		Var_x = Var_x / Var_y;
		Var_y = 1;
	}
	if ((Var_x > 0 && aux_x < 0) || (Var_x < 0 && aux_x > 0))
		Var_x = Var_x * -1;
	if ((Var_y > 0 && aux_y < 0) || (Var_y < 0 && aux_y > 0))
		Var_y = Var_y * -1;
	this->ball->Mover(this->BG, this->hole, Var_x, Var_y, Velocity, run, this->obstacle, this->obstacle_1, this->obstacle_2, this->obstacle_3);

	if (this->Get_Remaining_Moves() > 0) {
		std::cout << "Movimentos Restantes: " << this->Get_Remaining_Moves() << std::endl;
	}

	if (this->Get_Remaining_Moves() == 0 && this->ball->Get_In() == false) {
		this->Set_Run(false);
		this->Set_Stop(true);
		std::cout << "GAME OVER" << std::endl;
	}
}
Level4::~Level4() {
	delete this->ball;
	delete this->hole;
	delete this->obstacle;
	delete this->obstacle_1;
	delete this->obstacle_2;
	delete this->obstacle_3;
}
