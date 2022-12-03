#include <iostream>
#include <SDL_image.h>
#include <SDL.h>
#include "Launcher.h"
#include "Ball.h"
#include "Level.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"
#include "Timer.h"


int main(int argc, char* argv[])
{
    Level1 level_1;
    int cursor_x_init, cursor_x_final, cursor_y_init, cursor_y_final;
    bool aux_bool = true;
    bool run = true;
    //Criação de Evento 
    SDL_Event event;
    std::cout << "---------------- LEVEL 1 ----------------" << std::endl;
    std::cout << "Tentativas Permitidas: " << level_1.Get_Remaining_Moves() << std::endl;

    while (level_1.Get_Run())
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

            //Essa pr�xima etapa consiste em verificar quando o jogador aperta a tela arrasta o mouse e solta, esse arrastar é feito a partir da diferen�a entre as posições do cursor
            //quando o jogador aperta e solta



                //Verifica se o Evento de Mouse -> ser apertado ocorreu
            if (SDL_MOUSEBUTTONDOWN == event.type)
            {
                //Verifica se a parte do Mouse apertada foi o bot�o esquerdo
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
                //Verifica se a parte do Mouse soltada foi o bot�o esquerdo
                if (SDL_BUTTON_LEFT == event.button.button)
                {
                    //Função que atribui ao valor associado ao endere�o, a posi��o x e a posição y do cursor
                    SDL_GetMouseState(&cursor_x_final, &cursor_y_final);
                    //Método da Struct FirstItem, quando a bola foi inicializada foi chamada de "BALL"
                    //Método que pega as duas coordernadas e calcula o vetor q liga elas, ou seja, a linha mais curta entre os dois pontos
                    //Método que gera cada frame de movimento da bola a partir de todos os dados passados através do mouse
                    level_1.Mover_Ball(cursor_x_init - cursor_x_final, cursor_y_init - cursor_y_final, level_1.Get_pRun());
                }

            }

        }

        if (level_1.Get_Run()==false) {
            SDL_DestroyWindow(level_1.Get_Launcher().Get_Screen().Get_Window());          
        }
      if (level_1.Get_Stop() == true) {
            SDL_DestroyWindow(level_1.Get_Launcher().Get_Screen().Get_Window());
            IMG_Quit();
            SDL_Quit();
            return EXIT_SUCCESS;
        }
    }

    Level2 level_2;
    std::cout << "---------------- LEVEL 2 ----------------" << std::endl;
    std::cout << "Tentativas Permitidas: " << level_2.Get_Remaining_Moves() << std::endl;
    while (level_2.Get_Run())
    {
        //Inicializa��o Padrão de Evento de Tela
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
                    //Função que atribui ao valor associado ao endereço, a posi��o x e a posição y do cursor
                    SDL_GetMouseState(&cursor_x_init, &cursor_y_init);
                }
            }
            //Verifica se o Evento de Mouse -> ser soltado ocorreu
            if (SDL_MOUSEBUTTONUP == event.type)
            {
                //Verifica se a parte do Mouse soltada foi o botão esquerdo
                if (SDL_BUTTON_LEFT == event.button.button)
                {
                    //Fun��o que atribui ao valor associado ao endereço, a posi��o x e a posi��o y do cursor
                    SDL_GetMouseState(&cursor_x_final, &cursor_y_final);
                    //M�todo da Struct FirstItem, quando a bola foi inicializada foi chamada de "BALL"
                    //M�todo que pega as duas coordernadas e calcula o vetor q liga elas, ou seja, a linha mais curta entre os dois pontos
                    //M�todo que gera cada frame de movimento da bola a partir de todos os dados passados atrav�s do mouse
                    level_2.Mover_Ball(cursor_x_init - cursor_x_final, cursor_y_init - cursor_y_final, level_2.Get_pRun());
                }

            }

        }
        if (level_2.Get_Run() == false) {
            SDL_DestroyWindow(level_2.Get_Launcher().Get_Screen().Get_Window());
        }
        if (level_2.Get_Stop() == true) {
            SDL_DestroyWindow(level_1.Get_Launcher().Get_Screen().Get_Window());
            IMG_Quit();
            SDL_Quit();
            return EXIT_SUCCESS;
        }
    }

    Level3 level_3;
    std::cout << "---------------- LEVEL 3 ----------------" << std::endl;
    std::cout << "Tentativas Permitidas: " << level_3.Get_Remaining_Moves() << std::endl;
    while (level_3.Get_Run())
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
                //Verifica se a parte do Mouse apertada foi o bot�o esquerdo
                if (SDL_BUTTON_LEFT == event.button.button)
                {
                    //Fun��o relacionada com os inputs de dispositivos
                    SDL_PumpEvents();
                    //Função que atribui ao valor associado ao endere�o, a posição x e a posi��o y do cursor
                    SDL_GetMouseState(&cursor_x_init, &cursor_y_init);
                }
            }
            //Verifica se o Evento de Mouse -> ser soltado ocorreu
            if (SDL_MOUSEBUTTONUP == event.type)
            {
                //Verifica se a parte do Mouse soltada foi o bot�o esquerdo
                if (SDL_BUTTON_LEFT == event.button.button)
                {
                    //Função que atribui ao valor associado ao endere�o, a posição x e a posi��o y do cursor
                    SDL_GetMouseState(&cursor_x_final, &cursor_y_final);
                    //M�todo da Struct FirstItem, quando a bola foi inicializada foi chamada de "BALL"
                    //M�todo que pega as duas coordernadas e calcula o vetor q liga elas, ou seja, a linha mais curta entre os dois pontos
                    //M�todo que gera cada frame de movimento da bola a partir de todos os dados passados atrav�s do mouse
                    level_3.Mover_Ball(cursor_x_init - cursor_x_final, cursor_y_init - cursor_y_final, level_3.Get_pRun());
                }

            }

        }
        if (level_3.Get_Run() == false) { 
            SDL_DestroyWindow(level_3.Get_Launcher().Get_Screen().Get_Window());
        }
        if (level_3.Get_Stop() == true) {
            SDL_DestroyWindow(level_1.Get_Launcher().Get_Screen().Get_Window());
            IMG_Quit();
            SDL_Quit();
            return EXIT_SUCCESS;
        }
    }

    EngineUtils::Timer* timer = EngineUtils::Timer::Instance();
    float itime = 0.0f;
    int frames = 0;
    int current = 0;


    Level4 level_4;
    std::cout << "---------------- LEVEL 4 ----------------" << std::endl;
    std::cout << "Tentativas Permitidas: " << level_4.Get_Remaining_Moves() << std::endl;
    while (level_4.Get_Run())
    {
        timer->Tick();
        timer->Reset();
        itime += timer->DeltaTime();
        

        
            if (itime >= 1.0f) {
                timer->Reset();
                current = itime + frames;
                std::cout << "Tempo Restante: " << 30-current << std::endl;
                itime = 0.0f;
                frames++;
            }
        
            if (current == 30) { 
                level_4.Set_Run(false);           
            }

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
                //Verifica se a parte do Mouse soltada foi o bot�o esquerdo
                if (SDL_BUTTON_LEFT == event.button.button)
                {
                    //Fun��o que atribui ao valor associado ao endere�o, a posição x e a posição y do cursor
                    SDL_GetMouseState(&cursor_x_final, &cursor_y_final);
                    //M�todo da Struct FirstItem, quando a bola foi inicializada foi chamada de "BALL"
                    //M�todo que pega as duas coordernadas e calcula o vetor q liga elas, ou seja, a linha mais curta entre os dois pontos
                    //M�todo que gera cada frame de movimento da bola a partir de todos os dados passados atrav�s do mouse
                    level_4.Mover_Ball(cursor_x_init - cursor_x_final, cursor_y_init - cursor_y_final, level_4.Get_pRun());
                }

            }

        
        }
        if (level_4.Get_Run() == false) {
            SDL_DestroyWindow(level_4.Get_Launcher().Get_Screen().Get_Window());
        }
       if (level_4.Get_Stop() == true) {
            SDL_DestroyWindow(level_1.Get_Launcher().Get_Screen().Get_Window());
            IMG_Quit();
            SDL_Quit();
            return EXIT_SUCCESS;
        }
    }
    /*SDL_DestroyTexture(level_1.Get_Launcher()
    SDL_DestroyTexture(Ball_Tx);*/
    SDL_DestroyWindow(level_1.Get_Launcher().Get_Screen().Get_Window());
    IMG_Quit();
    SDL_Quit();
    return EXIT_SUCCESS;



}
