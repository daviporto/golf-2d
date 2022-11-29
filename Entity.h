#pragma once
#include <iostream>
#include <SDL_image.h>
#include <SDL.h>
class Entity {
private:
	SDL_Rect* pbrect;
	SDL_Surface* Sur;
	SDL_Renderer* Ren;
	SDL_Texture* Tex;
	SDL_Rect brect;
public:
	void Set_W(double W);
	void Set_H(double H);
	void Set_X(double X);
	void Set_Y(double Y);
	void Set_Surface(SDL_Surface * Sur);
	void Set_Render(SDL_Renderer* Ren);
	void Set_Texture(SDL_Texture* Tex);
	void Set_pbrect();
	double Get_W();
	double Get_H();
	double Get_X();
	double Get_Y();
	SDL_Surface* Get_Surface();
	SDL_Renderer* Get_Render();
	SDL_Texture* Get_Tex();
	SDL_Rect* Get_pbrect();
	SDL_Rect& Get_brect_ref();
	
};