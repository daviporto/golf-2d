#include "Ball.h"
const int WINDOW_WIDTH = 1000, WINDOW_HEIGHT = 800;
const double FRICTION = 0.02;
Ball::Ball(SDL_Renderer* ren, SDL_Texture* Ball_Tx, double init_x_pos, double init_y_pos, const double ball_radius) {
	this->Set_pbrect();
	this->Set_Render(ren);
	this->Set_Surface(IMG_Load("C:\\Users\\User\\OneDrive\\Imagens\\GolfBG.png"));
	this->Set_Texture(Ball_Tx);
	this->Set_X(init_x_pos);
	this->Set_Y(init_y_pos);
	this->Set_W(ball_radius);
	this->Set_H(ball_radius);
}
void Ball::Mover(Background* BG,Hole* hole, double Var_x, double Var_y, double Velocity, bool * run) {
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
		//altera a posição da bola de acordo com a velocidade atual
		this->Set_X((this->Get_X() + round(Var_x * (Velocity * 75))));
		this->Set_Y((this->Get_Y() + round(Var_y * (Velocity * 75))));
		//limpando a ultima impressão da bola, ou seja, reimprindo o fundo 
		SDL_RenderClear(this->Get_Render());
		SDL_RenderCopy(this->Get_Render(), BG->Get_Tex(), NULL, BG->Get_pRect());
		SDL_RenderCopy(this->Get_Render(), hole->Get_Tex(), NULL, hole->Get_pbrect());
		//Renderização da bola
		std::cout <<" ball x" << this->Get_X() << "  ball y : " << this->Get_Y() << std::endl;
		SDL_RenderCopy(this->Get_Render(), this->Get_Tex(), NULL, this->Get_pbrect());
		//Print the render
		//Print the render
		SDL_RenderPresent(this->Get_Render());
		//Delay entre frames
		SDL_Delay(75);
		//Bola no buraco
		if (hole->Ball_Presence(this->Get_X(), this->Get_Y())) {
			this->Set_X(hole->Get_X());
			this->Set_Y(hole->Get_Y());
			for (int count = this->Get_W(); count >= 0; count--) {
				this->Dim_Tam(1);
				// compensando a posição que é perdida com o decrescimo
				if (count % 2 == 0) {
					this->Set_X(this->Get_X() + 1);
					this->Set_Y(this->Get_Y() + 1);
				}
				SDL_RenderClear(this->Get_Render());
				SDL_RenderCopy(this->Get_Render(), BG->Get_Tex(), NULL, BG->Get_pRect());
				SDL_RenderCopy(this->Get_Render(), hole->Get_Tex(), NULL, hole->Get_pbrect());
				SDL_RenderCopy(this->Get_Render(), this->Get_Tex(), NULL, this->Get_pbrect());	
				SDL_RenderPresent(this->Get_Render());
				
				SDL_Delay(75);
			}
			*run = false;
			break;
		}

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
void Ball::Mover(Background* BG, Hole* hole, double Var_x, double Var_y, double Velocity, bool* run, Obstacle* obs, Obstacle* obs_1, Obstacle* obs_2, Obstacle* obs_3) {
	while (Velocity > 0.001) {
		//garantir q n saia da tela
		if ((this->Get_X() + Var_x * (75 * Velocity)) < 0 || (this->Get_X() + Var_x * (75 * Velocity)) + this->Get_W() > WINDOW_WIDTH)
		{
			Var_x = Var_x * -1;
		}
		if ((this->Get_Y() + Var_y * (75 * Velocity)) < 0 || (this->Get_Y() + Var_y * (75 * Velocity)) + this->Get_H() > WINDOW_HEIGHT)
		{
			Var_y = Var_y * -1;
		}
		//garantir colisao com obstaculo

		//se a proxima posição da bola( posição atual + projeção + largura para efeito visual) for maior que a posição mais a esquerda do obstaculo ee limite para final do obstaculo em x  
		if (this->Get_X() + round(Var_x * (Velocity * 75)) + this->Get_W() >= obs->Get_X() && this->Get_X() <= obs->Get_W() + obs->Get_X())
		{
			std::cout << "Entrou x" << std::endl;
			std::cout << "Primeira condição " << this->Get_X() + round(Var_x * (Velocity * 75)) + this->Get_W()
				<< " Segunda Condição " << obs->Get_X() << std::endl;

			//dentro do intervalo de y desejado
			// ou seja oy ser maior ou igual ao menor valor de y (o mais alto graficamente) e menor ou igual ao maior valor de y(o mais baixo)*/

			if (this->Get_Y() + this->Get_H() >= obs->Get_Y() && this->Get_Y() <= obs->Get_Y() + obs->Get_H())
			{
				std::cout << "Entrou y" << std::endl;
				std::cout << "Primeira condição " << this->Get_Y()
					<< " Segunda Condição " << obs->Get_Y() << std::endl;
				std::cout << "Terceira condição " << this->Get_Y()
					<< " Quarta Condição " << obs->Get_Y() << std::endl;

				Var_x = Var_x * -1;
			}

		
		}
	
		/*
		//se a posição da bola mais a proxima projeção( sem a largura pois eh pela direita) for menor que o ponto mais a direita do obstaculo
		if (this->Get_X() + round(Var_x * (Velocity * 75)) <= obs->Get_X()+obs->Get_W())
		{
			//dentro do intervalo de y desejado
			// ou seja oy ser maior ou igual ao menor valor de y (o mais alto graficamente) e menor ou igual ao maior valor de y(o mais baixo)
			//if (this->Get_Y() >= obs->Get_Y() && this->Get_Y() <= obs->Get_Y() + obs->Get_H())
				Var_x = Var_x * -1;
		}
		
		//se a proxima posição da bola( posição atual + projeção + largura para efeito visual) for maior que a posição mais a esquerda do obstaculo  
		if (this->Get_X() + round(Var_x * (Velocity * 75)) + this->Get_W() >= obs_1->Get_X())
		{
			//dentro do intervalo de y desejado
			// ou seja oy ser maior ou igual ao menor valor de y (o mais alto graficamente) e menor ou igual ao maior valor de y(o mais baixo)
			if (this->Get_Y() >= obs_1->Get_Y() && this->Get_Y() <= obs_1->Get_Y() + obs_1->Get_H())
				Var_x = Var_x * -1;
		}
		//
		if (this->Get_X() + round(Var_x * (Velocity * 75)) <= obs_1->Get_X() + obs_1->Get_W())
		{
			//dentro do intervalo de y desejado
			// ou seja oy ser maior ou igual ao menor valor de y (o mais alto graficamente) e menor ou igual ao maior valor de y(o mais baixo)
			if (this->Get_Y() >= obs_1->Get_Y() && this->Get_Y() <= obs_1->Get_Y() + obs_1->Get_H())
				Var_x = Var_x * -1;
		}

		//se a proxima posição da bola( posição atual + projeção + largura para efeito visual) for maior que a posição mais a esquerda do obstaculo  
		if (this->Get_X() + round(Var_x * (Velocity * 75)) + this->Get_W() >= obs_2->Get_X())
		{
			//dentro do intervalo de y desejado
			// ou seja oy ser maior ou igual ao menor valor de y (o mais alto graficamente) e menor ou igual ao maior valor de y(o mais baixo)
			if (this->Get_Y() >= obs_2->Get_Y() && this->Get_Y() <= obs_2->Get_Y() + obs_2->Get_H())
				Var_x = Var_x * -1;
		}
		//
		if (this->Get_X() + round(Var_x * (Velocity * 75)) <= obs_2->Get_X() + obs_2->Get_W())
		{
			//dentro do intervalo de y desejado
			// ou seja oy ser maior ou igual ao menor valor de y (o mais alto graficamente) e menor ou igual ao maior valor de y(o mais baixo)
			if (this->Get_Y() >= obs_2->Get_Y() && this->Get_Y() <= obs_2->Get_Y() + obs_2->Get_H())
				Var_x = Var_x * -1;
		}

		//se a proxima posição da bola( posição atual + projeção + largura para efeito visual) for maior que a posição mais a esquerda do obstaculo  
		if (this->Get_X() + round(Var_x * (Velocity * 75)) + this->Get_W() >= obs_3->Get_X())
		{
			//dentro do intervalo de y desejado
			// ou seja oy ser maior ou igual ao menor valor de y (o mais alto graficamente) e menor ou igual ao maior valor de y(o mais baixo)
			if (this->Get_Y() >= obs_3->Get_Y() && this->Get_Y() <= obs_3->Get_Y() + obs_3->Get_H())
				Var_x = Var_x * -1;
		}
		//
		if (this->Get_X() + round(Var_x * (Velocity * 75)) <= obs_3->Get_X() + obs_3->Get_W())
		{
			//dentro do intervalo de y desejado
			// ou seja oy ser maior ou igual ao menor valor de y (o mais alto graficamente) e menor ou igual ao maior valor de y(o mais baixo)
			if (this->Get_Y() >= obs_3->Get_Y() && this->Get_Y() <= obs_3->Get_Y() + obs_3->Get_H())
				Var_x = Var_x * -1;
		}
		/*
		if(this->Get_Y() + round(Var_y * (Velocity * 75)) + this->Get_H() >= obs->Get_Y() || this->Get_Y() + round(Var_y * (Velocity * 75)) <= obs->Get_Y() + obs->Get_H())
		{
			if (this->Get_X() >= obs->Get_X() || this->Get_X() <= obs->Get_X() + obs->Get_W())
				Var_y = Var_y * -1;
		}
		if (this->Get_Y() + round(Var_y * (Velocity * 75)) + this->Get_H() >= obs_1->Get_Y()  || this->Get_Y() + round(Var_y * (Velocity * 75)) <= obs_1->Get_Y() + obs_1->Get_H())
		{
			if (this->Get_X() >= obs_1->Get_X() || this->Get_X() <= obs_1->Get_X() + obs_1->Get_W())
				Var_y = Var_y * -1;
		}
		if (this->Get_Y() + round(Var_y * (Velocity * 75)) + this->Get_H() >= obs_2->Get_Y() + this->Get_H() || this->Get_Y() + round(Var_y * (Velocity * 75)) <= obs_2->Get_Y() + obs_2->Get_H())
		{
			if (this->Get_X() >= obs_2->Get_X() || this->Get_X() <= obs_2->Get_X() + obs_2->Get_W())
				Var_y = Var_y * -1;
		}
		if (this->Get_Y() + round(Var_y * (Velocity * 75)) + this->Get_H() >= obs_3->Get_Y() + this->Get_H() || this->Get_Y() + round(Var_y * (Velocity * 75)) <= obs_3->Get_Y() + obs_3->Get_H())
		{
			if (this->Get_X() >= obs_3->Get_X() || this->Get_X() <= obs_3->Get_X() + obs_3->Get_W())
				Var_y = Var_y * -1;
		}
		*/
		this->Set_X((this->Get_X() + round(Var_x * (Velocity * 75))));
		this->Set_Y((this->Get_Y() + round(Var_y * (Velocity * 75))));
		//limpando a ultima impressão da bola, ou seja, reimprindo o fundo 
		SDL_RenderClear(this->Get_Render());
		SDL_RenderCopy(this->Get_Render(), BG->Get_Tex(), NULL, BG->Get_pRect());
		SDL_RenderCopy(this->Get_Render(), hole->Get_Tex(), NULL, hole->Get_pbrect());
		SDL_RenderCopy(this->Get_Render(), obs->Get_Tex(), NULL, obs->Get_pbrect());
		SDL_RenderCopy(this->Get_Render(), obs_1->Get_Tex(), NULL, obs_1->Get_pbrect());
		SDL_RenderCopy(this->Get_Render(), obs_2->Get_Tex(), NULL, obs_2->Get_pbrect());
		SDL_RenderCopy(this->Get_Render(), obs_3->Get_Tex(), NULL, obs_3->Get_pbrect());
		//Renderização da bola
		SDL_RenderCopy(this->Get_Render(), this->Get_Tex(), NULL, this->Get_pbrect());
		//Print the render
		//Print the render
		SDL_RenderPresent(this->Get_Render());
		//Delay entre frames
		SDL_Delay(75);
		//Bola no buraco
		if (hole->Ball_Presence(this->Get_X(), this->Get_Y())) {
			this->Set_X(hole->Get_X());
			this->Set_Y(hole->Get_Y());
			for (int count = this->Get_W(); count >= 0; count--) {
				this->Dim_Tam(1);
				// compensando a posição que é perdida com o decrescimo
				if (count % 2 == 0) {
					this->Set_X(this->Get_X() + 1);
					this->Set_Y(this->Get_Y() + 1);
				}
				SDL_RenderClear(this->Get_Render());
				SDL_RenderCopy(this->Get_Render(), BG->Get_Tex(), NULL, BG->Get_pRect());
				SDL_RenderCopy(this->Get_Render(), hole->Get_Tex(), NULL, hole->Get_pbrect());
				SDL_RenderCopy(this->Get_Render(), this->Get_Tex(), NULL, this->Get_pbrect());
				SDL_RenderPresent(this->Get_Render());
				SDL_Delay(75);
			}
			*run = false;
			break;
		}

		Gerar_Atrito(Velocity);
		std::cout << round(Var_x * (Velocity * 75)) << " " << round(Var_y * (Velocity * 75)) << std::endl;
	}
	}