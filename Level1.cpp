#include "Level1.h"
Level1::Level1() {
	this->Set_pos_ball_init_x(100);
	this->Set_pos_ball_init_y(700);
	this->Set_pos_hole_init_x(875);
	this->Set_pos_hole_init_y(120);
	this->ball = new Ball(this->Get_Main_Launcher_Render(), SDL_CreateTextureFromSurface(this->Get_Main_Launcher_Render(),
		IMG_Load("Imagens_Golf\\GolfBall.png")), this->Get_pos_ball_init_x(),
		this->Get_pos_ball_init_y(), 15);
	this->hole = new Hole(this->Get_Main_Launcher_Render(), SDL_CreateTextureFromSurface(this->Get_Main_Launcher_Render(),
		IMG_Load("Imagens_Golf\\Hole.png")),
		this->Get_pos_hole_init_x(), this->Get_pos_hole_init_y(), 15);
	this->BG = new Background(0, this->Get_Main_Launcher_Render());
	this->Set_Remaining_Moves(5);
	SDL_RenderCopy(this->Get_Main_Launcher_Render(), SDL_CreateTextureFromSurface(this->Get_Main_Launcher_Render(),
		IMG_Load("Imagens_Golf\\GolfBG.png")), NULL, NULL);
	SDL_RenderCopy(this->Get_Main_Launcher_Render(), SDL_CreateTextureFromSurface(this->Get_Main_Launcher_Render(),
		IMG_Load("Imagens_Golf\\Hole.png")), NULL, this->hole->Get_pbrect());
	SDL_RenderCopy(this->Get_Main_Launcher_Render(), SDL_CreateTextureFromSurface(this->Get_Main_Launcher_Render(),
		IMG_Load("Imagens_Golf\\Golfball.png")), NULL, this->ball->Get_pbrect());
	SDL_RenderPresent(this->Get_Main_Launcher_Render());

	//Tentar entender pq o launcher n pode ficar estatico e tentar fazer a bola mexer sem apagar tudo o 
	//construtor de level ta gerando a primeria imagem, o mover de lvel tem q enviar um bg q inclua o buraco tbm e a bola pra mexer nesse cenario conjunto
}
void Level1::Mover_Ball(double Var_x, double Var_y, bool* run) {

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

		

		this->ball->Mover(this->BG, this->hole, Var_x, Var_y, Velocity, run);
		if (this->Get_Remaining_Moves() > 0) {
			std::cout << "Movimentos Restantes: " << this->Get_Remaining_Moves() << std::endl;
		}

		if (this->Get_Remaining_Moves() == 0 && this->ball->Get_In() == false) {
			this->Set_Run(false);
			this->Set_Stop(true);
			std::cout << "GAME OVER" << std::endl;
		}
		

}
Level1::~Level1() {
	delete this->ball;
	delete this->hole;
}