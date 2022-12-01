#include <iostream>
#include <SDL_image.h>
#include <SDL.h>
#include "Launcher.h"
#include "Ball.h"
#include "Level.h"
#include "Level1.h"
#include "Level2.h"


int main(int argc, char* argv[])
{
    Level1 level_1;
    int cursor_x_init, cursor_x_final, cursor_y_init, cursor_y_final;
    bool aux_bool = true;
    bool run = true;
    //Criação de Evento 
    SDL_Event event;

    std::cout << level_1.Get_Run() << std::endl;

   /* while (level_1.Get_Run())
    {
        std::cout << level_1.Get_Run() << std::endl;
        //Inicialização Padrão de Evento de Tela
        while (SDL_PollEvent(&event))
        {
                switch (event.type)
                {
                    //Confere caso de fechamento de Janela
                case SDL_QUIT:
                    run = false;
                    break;
                }

                //Essa próxima etapa consiste em verificar quando o jogador aperta a tela arrasta o mouse e solta, esse arrastar é feito a partir da diferença entre as posições do cursor
                //quando o jogador aperta e solta



                    //Verifica se o Evento de Mouse -> ser apertado ocorreu
                if (SDL_MOUSEBUTTONDOWN == event.type)
                {
                    //Verifica se a parte do Mouse apertada foi o botão esquerdo
                    if (SDL_BUTTON_LEFT == event.button.button)
                    {
                        //Função relacionada com os inputs de dispositivos
                        SDL_PumpEvents();
                        //Função que atribui ao valor associado ao endereço, a posição x e a posição y do cursor
                        SDL_GetMouseState(&cursor_x_init, &cursor_y_init);
                    }
                }
                //Verifica se o Evento de Mouse -> ser soltado ocorreu
                if (SDL_MOUSEBUTTONUP == event.type)
                {
                    //Verifica se a parte do Mouse soltada foi o botão esquerdo
                    if (SDL_BUTTON_LEFT == event.button.button)
                    {
                        //Função que atribui ao valor associado ao endereço, a posição x e a posição y do cursor
                        SDL_GetMouseState(&cursor_x_final, &cursor_y_final);
                        //Método da Struct FirstItem, quando a bola foi inicializada foi chamada de "BALL"
                        //Método que pega as duas coordernadas e calcula o vetor q liga elas, ou seja, a linha mais curta entre os dois pontos
                        //Método que gera cada frame de movimento da bola a partir de todos os dados passados através do mouse
                        level_1.Mover_Ball(cursor_x_init - cursor_x_final, cursor_y_init - cursor_y_final, level_1.Get_pRun());
                    }

                }
            
        }
    }*/
    Level2 level_2;
    while (level_2.Get_Run())
    {
        //Inicialização Padrão de Evento de Tela
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                //Confere caso de fechamento de Janela
            case SDL_QUIT:
                run = false;
                break;
            }

            //Essa próxima etapa consiste em verificar quando o jogador aperta a tela arrasta o mouse e solta, esse arrastar é feito a partir da diferença entre as posições do cursor
            //quando o jogador aperta e solta



                //Verifica se o Evento de Mouse -> ser apertado ocorreu
            if (SDL_MOUSEBUTTONDOWN == event.type)
            {
                //Verifica se a parte do Mouse apertada foi o botão esquerdo
                if (SDL_BUTTON_LEFT == event.button.button)
                {
                    //Função relacionada com os inputs de dispositivos
                    SDL_PumpEvents();
                    //Função que atribui ao valor associado ao endereço, a posição x e a posição y do cursor
                    SDL_GetMouseState(&cursor_x_init, &cursor_y_init);
                }
            }
            //Verifica se o Evento de Mouse -> ser soltado ocorreu
            if (SDL_MOUSEBUTTONUP == event.type)
            {
                //Verifica se a parte do Mouse soltada foi o botão esquerdo
                if (SDL_BUTTON_LEFT == event.button.button)
                {
                    //Função que atribui ao valor associado ao endereço, a posição x e a posição y do cursor
                    SDL_GetMouseState(&cursor_x_final, &cursor_y_final);
                    //Método da Struct FirstItem, quando a bola foi inicializada foi chamada de "BALL"
                    //Método que pega as duas coordernadas e calcula o vetor q liga elas, ou seja, a linha mais curta entre os dois pontos
                    //Método que gera cada frame de movimento da bola a partir de todos os dados passados através do mouse
                    level_2.Mover_Ball(cursor_x_init - cursor_x_final, cursor_y_init - cursor_y_final, level_2.Get_pRun());
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

