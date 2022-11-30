#include "Ball.h"
const int WINDOW_WIDTH = 1000, WINDOW_HEIGHT = 800;
const double FRICTION = 0.02;
Ball::Ball(SDL_Renderer* ren, SDL_Texture* Ball_Tx, double init_x_pos, double init_y_pos, const double ball_radius) {
	this->Set_pbrect();
	this->Set_Render(ren);
	this->Set_Surface(IMG_Load("../images/GolfBG.png"));
	this->Set_Texture(Ball_Tx);
	this->Set_X(init_x_pos);
	this->Set_Y(init_y_pos);
	this->Set_W(ball_radius);
	this->Set_H(ball_radius);
}
void Ball::Mover(Background* BG,Hole* hole, double Var_x, double Var_y, double Velocity) {
	while (Velocity>0.001) {
		//garantir q n saia da tela
		if ((this->Get_X() + Var_x * (75 * Velocity)) + this->Get_W() < 0 || (this->Get_X() + Var_x * (75 * Velocity)) + this->Get_W() > WINDOW_WIDTH)
		{
			Var_x = Var_x * -1;
		}
		if ((this->Get_Y() + Var_y * (75 * Velocity)) + this->Get_H() < 0 || (this->Get_Y() + Var_y * (75 * Velocity)) + this->Get_H() > WINDOW_HEIGHT)
		{
			Var_y = Var_y * -1;
		}
		//altera a posi��o da bola de acordo com a velocidade atual
		this->Set_X((this->Get_X() + round(Var_x * (Velocity * 75))));
		this->Set_Y((this->Get_Y() + round(Var_y * (Velocity * 75))));
		//limpando a ultima impress�o da bola, ou seja, reimprindo o fundo 
		SDL_RenderClear(this->Get_Render());
		SDL_RenderCopy(this->Get_Render(), BG->Get_Tex(), NULL, BG->Get_pRect());
		SDL_RenderCopy(this->Get_Render(), hole->Get_Tex(), NULL, hole->Get_pbrect());
		//Renderiza��o da bola
		SDL_RenderCopy(this->Get_Render(), this->Get_Tex(), NULL, this->Get_pbrect());
		//Print the render
		//Print the render
		SDL_RenderPresent(this->Get_Render());
		//Delay entre frames
		SDL_Delay(75);

		Gerar_Atrito(Velocity);
		std::cout << round(Var_x * (Velocity * 75)) << " " << round(Var_y * (Velocity * 75)) << std::endl;
	}
}
void Ball::Gerar_Atrito(double &Velocity) {
	Velocity = Velocity - FRICTION;
}	
void Ball::Aum_Tam(double Var_r) {
	this->Set_W(this->Get_W() + Var_r);
	this->Set_H(this->Get_H() + Var_r);
}
void Ball::Dim_Tam(double Var_r) {
	this->Set_W(this->Get_W() - Var_r);
	this->Set_H(this->Get_H() - Var_r);
}
