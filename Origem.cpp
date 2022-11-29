#include <iostream>
#include <SDL_image.h>
#include <SDL.h>
#include "Launcher.h"
#include "Ball.h"
#include "Level.h"
#include "Level1.h"


int main(int argc, char* argv[])
{
    Level1 level_1;
    int cursor_x_init, cursor_x_final, cursor_y_init, cursor_y_final;
    
    bool run = true;
    //Cria��o de Evento 
    SDL_Event event;

    while (run)
    {
        //Inicializa��o Padr�o de Evento de Tela
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                //Confere caso de fechamento de Janela
            case SDL_QUIT:
                run = false;
                break;
            }
            
            //Essa pr�xima etapa consiste em verificar quando o jogador aperta a tela arrasta o mouse e solta, esse arrastar � feito a partir da diferen�a entre as posi��es do cursor
            //quando o jogador aperta e solta

            //Verifica se o Evento de Mouse -> ser apertado ocorreu
            if (SDL_MOUSEBUTTONDOWN == event.type)
            {
                //Verifica se a parte do Mouse apertada foi o bot�o esquerdo
                if (SDL_BUTTON_LEFT == event.button.button)
                {
                    //Fun��o relacionada com os inputs de dispositivos
                    SDL_PumpEvents();
                    //Fun��o que atribui ao valor associado ao endere�o, a posi��o x e a posi��o y do cursor
                    SDL_GetMouseState(&cursor_x_init, &cursor_y_init);
                }
            }
            //Verifica se o Evento de Mouse -> ser soltado ocorreu
            if (SDL_MOUSEBUTTONUP == event.type)
            {
                //Verifica se a parte do Mouse soltada foi o bot�o esquerdo
                if (SDL_BUTTON_LEFT == event.button.button)
                {
                    //Fun��o que atribui ao valor associado ao endere�o, a posi��o x e a posi��o y do cursor
                    SDL_GetMouseState(&cursor_x_final, &cursor_y_final);
                    //M�todo da Struct FirstItem, quando a bola foi inicializada foi chamada de "BALL"
                    //M�todo que pega as duas coordernadas e calcula o vetor q liga elas, ou seja, a linha mais curta entre os dois pontos
                    //M�todo que gera cada frame de movimento da bola a partir de todos os dados passados atrav�s do mouse
                    level_1.Mover_Ball(cursor_x_init-cursor_x_final, cursor_y_init - cursor_y_final  );
                }

            }

        }
    }
        /*SDL_DestroyTexture(level_1.Get_Launcher()
        SDL_DestroyTexture(Ball_Tx);*/
        SDL_DestroyWindow(level_1.Get_Launcher().Get_Screen().Get_Window());
        IMG_Quit();
        SDL_Quit();
        return EXIT_SUCCESS;



}

