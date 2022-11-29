#include "Background.h"
const int WIDTH = 1000, HEIGHT = 800;
Background::Background(int BG_ID, SDL_Renderer* ren) {
	this->p_BG_Rect = &(this->BG_Rect);
	this->BG_Rect.w = WIDTH;
	this->BG_Rect.h = HEIGHT;
	this->BG_Rect.x = 0;
	this->BG_Rect.y = 0;
	switch (BG_ID) {
	case 0:
//		this->BG_Sur = IMG_Load("C:\\Users\\User\\OneDrive\\Imagens\\GolfBG.png");
		break;
	case 1:
//		this->BG_Sur = IMG_Load("C:\\Users\\User\\OneDrive\\Imagens\\GolfBG1.png");
		break;
	case 2:
//		this->BG_Sur = IMG_Load("C:\\Users\\User\\OneDrive\\Imagens\\GolfBG2.png");
		break;
	case 3:
//		this->BG_Sur = IMG_Load("C:\\Users\\User\\OneDrive\\Imagens\\GolfBG3.png");
		break;
	}
	this->BG_Tex = SDL_CreateTextureFromSurface(ren, BG_Sur);
}
SDL_Texture* Background::Get_Tex() {
	return this->BG_Tex;
}
SDL_Rect Background::Get_Rect() {
	return this->BG_Rect;
}
SDL_Rect* Background::Get_pRect() {
	return this->p_BG_Rect;
}
