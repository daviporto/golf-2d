#include <iostream>
#include <string>

#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>
#include "components/Button.hpp"

using namespace std;

bool init();
void kill();
bool loop();
void runLevel1();
void runLevel2();
void actionCredits();
void actionHowToPlay();

// Pointers to our window, renderer, texture, and font
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture *texture, *text;
TTF_Font* font;
string input;
auto buttons = std::vector<std::unique_ptr<Button>>();

int main(int argc, char** args) {

    if ( !init() ) {
        system("pause");
        return 1;
    }

    while ( loop() ) {
        // wait before processing the next frame
        SDL_Delay(10);
    }

    kill();
    return 0;
}

bool loop() {
    SDL_Event e;

    // Clear the window to white
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
    SDL_RenderClear( renderer );
    for(auto const &b : buttons) b->render(renderer);

    // Event loop
    while ( SDL_PollEvent( &e ) != 0 ) {
        switch (e.type) {
            case SDL_QUIT:
                return false;
            case SDL_TEXTINPUT:
                input += e.text.text;
                break;
            case SDL_KEYDOWN:
                if (e.key.keysym.sym == SDLK_BACKSPACE && input.size()) {
                    input.pop_back();
                }
            case SDL_MOUSEBUTTONDOWN:
                if (e.button.button == SDL_BUTTON_LEFT)
                    for (auto const &b: buttons)
                        b->click(e.motion.x, e.motion.y);

                break;
        }
    }

    SDL_Color foreground = { 255, 255, 255 };

    // Update window
    SDL_RenderPresent( renderer );

    return true;
}

bool init() {
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        cout << "Error initializing SDL: " << SDL_GetError() << endl;
        return false;
    }


    // Initialize SDL_ttf
    if ( TTF_Init() < 0 ) {
        cout << "Error intializing SDL_ttf: " << TTF_GetError() << endl;
        return false;
    }

    window = SDL_CreateWindow( "Golf", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 400, SDL_WINDOW_SHOWN );
    if ( !window ) {
        cout << "Error creating window: " << SDL_GetError()  << endl;
        return false;
    }

    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    if ( !renderer ) {
        cout << "Error creating renderer: " << SDL_GetError() << endl;
        return false;
    }

    // Load font
    font = TTF_OpenFont("arial.ttf", 50);
    if ( !font ) {
        cout << "Error loading font: " << TTF_GetError() << endl;
        return false;
    }

    // Start sending SDL_TextInput events
    SDL_StartTextInput();

   buttons.push_back( std::make_unique<Button>("Level 1", 300,60,150,10, font,renderer, runLevel1));
    buttons.push_back( std::make_unique<Button>("Level 2", 300,60,150,80, font,renderer, runLevel2));
    buttons.push_back( std::make_unique<Button>("Credits", 300,60,150,150, font,renderer, actionCredits));
    buttons.push_back( std::make_unique<Button>("How to play", 300,60,150,220, font,renderer, actionHowToPlay));
    buttons.push_back( std::make_unique<Button>("Quit", 300,60,150,290, font,renderer, kill));

    return true;
}
void runLevel1(){
    std::cout << "call run level 1 terminal" << std::endl;
}

void runLevel2(){
    std::cout << "call run level 2 terminal" << std::endl;
}

void actionCredits(){
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Creditos",
                             "Esse jogo é um projeto feito para a materia de pds2 na ufmg, autore: Davi Porto Araujo"
                             "Alice Gustavo e Emanuele", window);
}
void actionHowToPlay(){
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Creditos",
                             "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod\n"
                             " tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, \n"
                             " consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse\n"
                             " cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat\n"
                             " non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.", window);

}

void kill() {
    std::cout <<"here";
    SDL_StopTextInput();

    TTF_CloseFont( font );
    SDL_DestroyTexture( texture );
    texture = NULL;

    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    window = NULL;
    renderer = NULL;

    TTF_Quit();
    SDL_Quit();
}

