#ifndef FIRSTITEM_H
#define FIRSTITEM_H
#include "Coordenada.h"
#include <SDL_image.h>
#include <SDL.h>
#include <cmath>
struct FirstItem
{
	void CreateImage(SDL_Rect * pballrect, SDL_Renderer* ren, SDL_Texture* Ball_Tx, SDL_Texture* BG_Tx, double Xvariancy, double Yvariancy,double velocity);
	double velocity=0;
	void Velocity(Coordenada c_cursorInit, Coordenada c_cursorFinal);
};



#endif
