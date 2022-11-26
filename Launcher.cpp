#include "Launcher.h"
Launcher::Launcher() {
    SDL_Init(SDL_INIT_EVERYTHING);
    this->screen = SDL_GetWindowSurface(this->Main_Screen.Get_Window());
    this->ren = SDL_CreateRenderer(this->Main_Screen.Get_Window(), -1, SDL_RENDERER_ACCELERATED);
}
SDL_Renderer* Launcher::Get_Render() {
    return this->ren;
}
Screen Launcher::Get_Screen() {
    return this->Main_Screen;
}