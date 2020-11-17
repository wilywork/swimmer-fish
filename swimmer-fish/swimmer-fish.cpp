// https://www.youtube.com/watch?v=IDa8hfl_9Vk&t=217s&ab_channel=elieserdejesus
#define SDL_MAIN_HANDLED

#include <iostream>
#include <string.h>
#include <SDL.h>
#include <time.h>
#include "HitBox.h"


using namespace std;

// ============ FUNCOES ============

SDL_Texture* CarregaTextura(const char* imagem, SDL_Renderer* renderizador)
{
    SDL_Surface* surface = SDL_LoadBMP(imagem); // Pega uma imagem/arquivo para a surface
    if (!surface) {
        cout << "Erro ao carregar: " << imagem << endl;
    }

    SDL_Texture* textura = SDL_CreateTextureFromSurface(renderizador, surface); // Textura recebe a surface

    SDL_FreeSurface(surface); // Limpa a surface

    return textura;
};


void FuncEventos(bool &gameOver,int &peixeMov ) {
    SDL_Event evento;
    while (SDL_PollEvent(&evento)) {
        switch (evento.type) {
        case SDL_QUIT:
            gameOver = true;
            break;

        case SDL_KEYDOWN:
            switch (evento.key.keysym.sym) {
            case SDLK_UP:
            case SDLK_w:
                if (peixeMov >= 0) {
                    peixeMov -= 30;
                }
                break;
            }
            break;
        }
    }
};

// ============ FIM FUNCOES ============
int main()
{
    bool jogoAtivo = true;
    bool menuAtivo = true;

    SDL_Window* janela;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) // Inicia a SDL
        cout << SDL_GetError() << endl;

    // inicia a JANELA
    janela = SDL_CreateWindow("Janela", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

    // Renderiza coisas na janela
    SDL_Renderer* renderizador = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);

    // Imagens renderizadas

    SDL_Texture* fundo = CarregaTextura("assets/imagens/fundoJogo.bmp", renderizador);
    SDL_Texture* peixe = CarregaTextura("assets/imagens/peixe.bmp", renderizador);
    SDL_Texture* coral = CarregaTextura("assets/imagens/coral.bmp", renderizador);
    SDL_Texture* comida = CarregaTextura("assets/imagens/comida.bmp", renderizador);
    SDL_Texture* linha = CarregaTextura("assets/imagens/linha.bmp", renderizador);
    SDL_Texture* anzol = CarregaTextura("assets/imagens/anzol.bmp", renderizador);
    SDL_Texture* numeros = CarregaTextura("assets/imagens/numeros2.bmp", renderizador);
    SDL_Texture* scoreIMG = CarregaTextura("assets/imagens/score.bmp", renderizador);
    SDL_Texture* fundo1 = CarregaTextura("assets/imagens/parallax/fundo1.bmp", renderizador);
    SDL_Texture* fundo2 = CarregaTextura("assets/imagens/parallax/fundo2.bmp", renderizador);
    SDL_Texture* fundo3 = CarregaTextura("assets/imagens/parallax/fundo3.bmp", renderizador);
    SDL_Texture* fundo4 = CarregaTextura("assets/imagens/parallax/fundo4.bmp", renderizador);

    srand(time(NULL));

    // Variavel para manter o jogo aberto
    bool gameOver = false;

    int peixeMov = 0;
    int coralMov = 0;
    int TAMpeixe = 100;
    int comidaMov = 0;
    int score = 0;
    int linhaMov = 0;
    int TAMlinhaH = 0;
    int comidaRandY = 250;
    int TAMcoral = 30;
    int NUM = 0;
    int scoreDezena = 0;

    SDL_RenderCopy(renderizador, CarregaTextura("assets/imagens/parallax/menu.bmp", renderizador), NULL, NULL);
    // Cola coisas na janela
    SDL_RenderPresent(renderizador);
    SDL_Delay(1000 / 60); // 60 fps

    while (menuAtivo) {
        SDL_Event evento;

        SDL_PollEvent(&evento);

        if (evento.type == SDL_KEYDOWN) {
            if (evento.key.keysym.sym == SDLK_KP_ENTER || evento.key.keysym.sym == SDLK_RETURN) {
                menuAtivo = false;
            }
        }
    }

    int MOVfundo2 = 0;
    int MOVfundo3 = 0;

    while (!gameOver) {

        FuncEventos(gameOver, peixeMov);

        SDL_RenderClear(renderizador); // Limpa a janela

        SDL_RenderCopy(renderizador, fundo1, NULL, NULL);

        //Fundo 2
        if (MOVfundo2 <= -800) {
            MOVfundo2 = 0;
        }
        SDL_Rect destinoFundo2;
        destinoFundo2.w = 800;
        destinoFundo2.h = 353;
        destinoFundo2.x = 0 + MOVfundo2;
        destinoFundo2.y = 100;
        MOVfundo2 -= 2;
        SDL_RenderCopy(renderizador, fundo2, NULL, &destinoFundo2);
        SDL_Rect destinoFundoEspelho;
        destinoFundoEspelho.w = 800;
        destinoFundoEspelho.h = 353;
        destinoFundoEspelho.x = 800 + MOVfundo2;
        destinoFundoEspelho.y = 100;
        SDL_RenderCopy(renderizador, fundo2, NULL, &destinoFundoEspelho);

        //Fundo 3
        if (MOVfundo3 <= -800) {
            MOVfundo3 = 0;
        }
        SDL_Rect destinoFundo3;
        destinoFundo3.w = 800;
        destinoFundo3.h = 353;
        destinoFundo3.x = 0 + MOVfundo3;
        destinoFundo3.y = 150;
        MOVfundo3 -= 3;
        SDL_RenderCopy(renderizador, fundo3, NULL, &destinoFundo3);
        SDL_Rect destinoFundo3Espelho;
        destinoFundo3Espelho.w = 800;
        destinoFundo3Espelho.h = 353;
        destinoFundo3Espelho.x = 800 + MOVfundo3;
        destinoFundo3Espelho.y = 150;
        SDL_RenderCopy(renderizador, fundo3, NULL, &destinoFundo3Espelho);



        SDL_RenderCopy(renderizador, fundo4, NULL, NULL);


        //Peixe
        SDL_Rect destinoPeixe;
        destinoPeixe.w = TAMpeixe;
        destinoPeixe.h = TAMpeixe;
        destinoPeixe.x = 50;
        destinoPeixe.y =  peixeMov * 4;
        if (destinoPeixe.y >= 520) {
            destinoPeixe.y = 520;
        }
        else
        {
            peixeMov++;
        }

        SDL_RenderCopy(renderizador, peixe, NULL, &destinoPeixe);

        //coral
        SDL_Rect destinoCoral;
        destinoCoral.w = 40;
        destinoCoral.h = TAMcoral * (404 / 122);
        destinoCoral.x =  750 - (coralMov * 5);
        destinoCoral.y =  600 - destinoCoral.h;
        coralMov++;
        if (destinoCoral.x <= -100) {
            coralMov = 0;
            TAMcoral = RandTamCoral();
        }
        SDL_RenderCopy(renderizador, coral, NULL, &destinoCoral);

        //comida
        SDL_Rect destinoComida;
        destinoComida.w = 10;
        destinoComida.h = 10;
        destinoComida.x = 750 - (comidaMov * 8);
        destinoComida.y = comidaRandY;
        comidaMov++;
        if (destinoComida.x <= -100) {
            comidaMov = 0;
            comidaRandY = rand() % 550;
        }
        SDL_RenderCopy(renderizador, comida, NULL, &destinoComida);

        //linha
        SDL_Rect destinoLinha;
        destinoLinha.w = 3;
        destinoLinha.h = 10 + (TAMlinhaH * 4);
        destinoLinha.x = 850 - (linhaMov * 3);
        destinoLinha.y = 0;
        linhaMov++;
        if (destinoLinha.x <= -100) {
            linhaMov = 0;
        }
        TAMlinhaH++;
        if (destinoLinha.h >= 550 - (destinoCoral.h + destinoPeixe.h + 75) ) {
            TAMlinhaH = 0;
        }
        SDL_RenderCopy(renderizador, linha, NULL, &destinoLinha);

        //Azol
        SDL_Rect destinoAnzol;
        destinoAnzol.w = 25;
        destinoAnzol.h = 25;
        destinoAnzol.x = destinoLinha.x -13;
        destinoAnzol.y = destinoLinha.h;
        SDL_RenderCopy(renderizador, anzol, NULL, &destinoAnzol);

        //Numeros do score
        if (score % 10 <= 4) {
            NUM = 0;

        }
        if (score % 10 >= 5) {
            NUM = 1;
        }
        SDL_Rect origemNumeros;
        origemNumeros.x = 62 * (score % 5);
        origemNumeros.y = 79 * NUM;
        origemNumeros.w = 62;
        origemNumeros.h = 79;
        SDL_Rect destinoNumeros;
        destinoNumeros.w = 33;
        destinoNumeros.h = 33;
        destinoNumeros.x = 750;
        destinoNumeros.y = 20;
        SDL_RenderCopy(renderizador, numeros, &origemNumeros, &destinoNumeros);

        if (score >= 10) {
            scoreDezena = score / 10;
            if (scoreDezena <= 4) {
                NUM = 0;

            }
            if (scoreDezena >= 5) {
                NUM = 1;
            }
            SDL_Rect origemNumeros;
            origemNumeros.x = 62 * scoreDezena;
            origemNumeros.y = 79 * NUM;
            origemNumeros.w = 62;
            origemNumeros.h = 79;
            SDL_Rect destinoNumeros;
            destinoNumeros.w = 33;
            destinoNumeros.h = 33;
            destinoNumeros.x = 715;
            destinoNumeros.y = 20;
            SDL_RenderCopy(renderizador, numeros, &origemNumeros, &destinoNumeros);
        }

        // Placa de score
        SDL_Rect destinoScore;
        destinoScore.w = 87;
        destinoScore.h = 34;
        destinoScore.x = 623;
        destinoScore.y = 20;
        SDL_RenderCopy(renderizador, scoreIMG, NULL, &destinoScore);


        //HitBox
        HitBoxComida(destinoComida, destinoPeixe, TAMpeixe, comidaMov, score, comidaRandY, comidaMov);
        HitBoxCoral(destinoCoral, destinoPeixe, peixeMov, score, TAMpeixe, comidaRandY, coralMov, linhaMov, comidaMov, TAMcoral);
        HitBoxLinha(destinoLinha, destinoPeixe, peixeMov, score, TAMpeixe, comidaRandY, coralMov, linhaMov, comidaMov, TAMcoral);
        HitBoxAnzol(destinoAnzol, destinoPeixe, peixeMov, score, TAMpeixe, comidaRandY, coralMov, linhaMov, comidaMov, TAMcoral);

        SDL_RenderPresent(renderizador); // Cola coisas na janela
        SDL_Delay(1000 / 60); // 60 fps

    }

    SDL_DestroyWindow(janela);
    SDL_Quit();
    return 0;
}