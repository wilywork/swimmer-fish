// https://www.youtube.com/watch?v=IDa8hfl_9Vk&t=217s&ab_channel=elieserdejesus
#define SDL_MAIN_HANDLED

#include <iostream>
#include <string.h>
#include <SDL.h>
#include <time.h>
#include "HitBox.h"
#include "Eventos.h"
#include "Menu.h"
#include "CarregaTextura.h"
#include "Peixe.h"
#include "Objetos.h"
#include "Background.h"


using namespace std;


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

    SDL_Texture* numeros = CarregaTextura("assets/imagens/numeros2.bmp", renderizador);
    SDL_Texture* scoreIMG = CarregaTextura("assets/imagens/score.bmp", renderizador);
    SDL_Texture* fundo1 = CarregaTextura("assets/imagens/parallax/fundo1.bmp", renderizador);
    SDL_Texture* fundo2 = CarregaTextura("assets/imagens/parallax/fundo2.bmp", renderizador);
    SDL_Texture* fundo3 = CarregaTextura("assets/imagens/parallax/fundo3.bmp", renderizador);
    SDL_Texture* fundo4 = CarregaTextura("assets/imagens/parallax/fundo4.1.bmp", renderizador);


    srand(time(NULL));

    // Variavel para manter o jogo aberto
    bool gameOver = false;

    int pressUpPeixe = false;
    int peixeMov = 0;
    int coralMov = 0;
    int TAMpeixe = 100;
    int comidaMov = 0;
    int score = 0;
    int valorDeCorrecao = 1;
    int linhaMov = 0;
    int TAMlinhaH = 0;
    int comidaRandY = 250;
    int TAMcoral = 30;
    int NUM = 0;
    int scoreDezena = 0;
    int MOVfundo[3] = {};

    SDL_RenderCopy(renderizador, CarregaTextura("assets/imagens/parallax/menu.bmp", renderizador), NULL, NULL);

    // Cola coisas na janela
    SDL_RenderPresent(renderizador);
    SDL_Delay(1000 / 60); // 60 fps

    Menu(menuAtivo);

    while (!gameOver) {

        FuncEventos(gameOver, peixeMov, pressUpPeixe);

        SDL_RenderClear(renderizador); // Limpa a janela

        SDL_RenderCopy(renderizador, fundo1, NULL, NULL);

        //Fundo 2
        if (MOVfundo[0] <= -800) {
            MOVfundo[0] = 0;
        }

       // SpawnBackground(renderizador, [""]);

        SDL_Rect destinoFundo2;
        destinoFundo2.w = 800;
        destinoFundo2.h = 353;
        destinoFundo2.x = 0 + MOVfundo[0];
        destinoFundo2.y = 100;
        MOVfundo[0] -= 2;

        SDL_RenderCopy(renderizador, fundo2, NULL, &destinoFundo2);
        SDL_Rect destinoFundoEspelho;
        destinoFundoEspelho.w = 800;
        destinoFundoEspelho.h = 353;
        destinoFundoEspelho.x = 800 + MOVfundo[0];
        destinoFundoEspelho.y = 100;
        SDL_RenderCopy(renderizador, fundo2, NULL, &destinoFundoEspelho);
        
        //Fundo 3
        if (MOVfundo[1] <= -800) {
            MOVfundo[1] = 0;
        }
        SDL_Rect destinoFundo3;
        destinoFundo3.w = 800;
        destinoFundo3.h = 353;
        destinoFundo3.x = 0 + MOVfundo[1];
        destinoFundo3.y = 150;
        MOVfundo[1] -= 3;
        SDL_RenderCopy(renderizador, fundo3, NULL, &destinoFundo3);
        SDL_Rect destinoFundo3Espelho;
        destinoFundo3Espelho.w = 800;
        destinoFundo3Espelho.h = 353;
        destinoFundo3Espelho.x = 800 + MOVfundo[1];
        destinoFundo3Espelho.y = 150;
        SDL_RenderCopy(renderizador, fundo3, NULL, &destinoFundo3Espelho);


        //Fundo 4
        if (MOVfundo[2] <= -800) {
            MOVfundo[2] = 0;
        }
        SDL_Rect destinoFundo4;
        destinoFundo4.w = 800;
        destinoFundo4.h = 400;
        destinoFundo4.x = 0 + MOVfundo[2];
        destinoFundo4.y = 200;
        MOVfundo[2] -= 5;
        SDL_RenderCopy(renderizador, fundo4, NULL, &destinoFundo4);
        SDL_Rect destinoFundo4Espelho;
        destinoFundo4Espelho.w = 800;
        destinoFundo4Espelho.h = 400;
        destinoFundo4Espelho.x = 800 + MOVfundo[2];
        destinoFundo4Espelho.y = 200;
        SDL_RenderCopy(renderizador, fundo4, NULL, &destinoFundo4Espelho);

        Peixe peixe = SpawnPeixe(renderizador, "assets/imagens/peixe.bmp", TAMpeixe, peixeMov * 4);

        if (peixe.estrutura.y >= 520) {
            peixe.estrutura.y = 520;
        } else {
            if (!pressUpPeixe) {
                peixeMov++;
            } else {
                peixeMov--;
            }
        }

        if (peixeMov <= -20) {
            pressUpPeixe = false;
        }


        //coral
        Coral coral = SpawnCoral(renderizador, "assets/imagens/coral.bmp", TAMcoral,coralMov);

        coralMov++;
        if (coral.posicaoX <= -100) {
            coralMov = 0;
            TAMcoral = RandTamCoral();
        }

        //comida
        Comida comida = SpawnComida(renderizador, "assets/imagens/comida.bmp", comidaMov, comidaRandY);

        comidaMov++;
        if (comida.posicaoX <= -100) {
            comidaMov = 0;
            comidaRandY = rand() % 550;
        }


        //linha
        Linha linha = SpawnLinha(renderizador, "assets/imagens/linha.bmp", TAMlinhaH, linhaMov);
        
        linhaMov++;
        if (linha.posicaoX <= -100) {
            linhaMov = 0;
        }

        if (TAMlinhaH == 200 || TAMlinhaH >= (coral.tamanhoH + peixe.estrutura.h - 100)) {
            valorDeCorrecao = -1;
        } else if (TAMlinhaH == 10) {
            valorDeCorrecao = 1;
        }

        TAMlinhaH += valorDeCorrecao;


        //Azol
        Anzol anzol = SpawnAnzol(renderizador, "assets/imagens/anzol.bmp", linha);

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
        HitBoxComida(comida.estrutura, peixe.estrutura, TAMpeixe, comidaMov, score, comidaRandY, comidaMov);
        HitBoxCoral(coral.estrutura, peixe.estrutura, peixeMov, score, TAMpeixe, comidaRandY, coralMov, linhaMov, comidaMov, TAMcoral);
        HitBoxLinha(linha.estrutura, peixe.estrutura, peixeMov, score, TAMpeixe, comidaRandY, coralMov, linhaMov, comidaMov, TAMcoral);
        HitBoxAnzol(anzol.estrutura, peixe.estrutura, peixeMov, score, TAMpeixe, comidaRandY, coralMov, linhaMov, comidaMov, TAMcoral);

        SDL_RenderPresent(renderizador); // Cola coisas na janela
        SDL_Delay(1000 / 60); // 60 fps

    }

    SDL_DestroyWindow(janela);
    SDL_Quit();
    return 0;
}