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
#include "Placar.h"


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

    SDL_Texture* fundo1 = CarregaTextura("assets/imagens/parallax/fundo1.bmp", renderizador);
    SDL_Texture* fundo2 = CarregaTextura("assets/imagens/parallax/fundo2.bmp", renderizador);
    SDL_Texture* fundo3 = CarregaTextura("assets/imagens/parallax/fundo3.bmp", renderizador);
    SDL_Texture* fundo4 = CarregaTextura("assets/imagens/parallax/fundo4.1.bmp", renderizador);


    srand(time(NULL));

    // Variavel para manter o jogo aberto
    bool gameOver = false;

    int pressUpPeixe = false;
    int peixeMov = 0;
<<<<<<< HEAD
    int coralMov = 0;
    int score = 25;
=======
    int score = 0;
>>>>>>> bac51bc2ad78796c654bc39f1ebccf3fcb437314
    int valorDeCorrecao = 1;
    int linhaMov = 0;
    int TAMlinhaH = 0;
    int TAMcoral = 30;
    int NUM = 0;
    int scoreDezena = 0;
    int MOVfundo[3] = {};

    SDL_RenderCopy(renderizador, CarregaTextura("assets/imagens/parallax/menu.bmp", renderizador), NULL, NULL);

    // Cola coisas na janela
    SDL_RenderPresent(renderizador);
    SDL_Delay(1000 / 60); // 60 fps

    Menu(menuAtivo);

    Peixe peixe = SpawnPeixe(renderizador, "assets/imagens/peixe.bmp", peixeMov);
    Placar placar = SpawnPlacar(renderizador, "assets/imagens/score.bmp");
    Numeros numeros = SpawnNumeros(renderizador, "assets/imagens/numeros2.bmp", score, NUM);
    Linha linha = SpawnLinha(renderizador, "assets/imagens/linha.bmp", TAMlinhaH, linhaMov);
    Anzol anzol = SpawnAnzol(renderizador, "assets/imagens/anzol.bmp", linha);
    Comida comida = SpawnComida(renderizador, "assets/imagens/comida.bmp");
    Coral coral = SpawnCoral(renderizador, "assets/imagens/coral.bmp", TAMcoral);

    Numeros2 numeros2 = SpawnNumeros2(renderizador, "assets/imagens/numeros2.bmp", score, NUM);

    SpawnBackground(renderizador);

    while (!gameOver) {
        // Limpa a janela
        SDL_RenderClear(renderizador);

        FuncEventos(gameOver, peixeMov, pressUpPeixe);

        UpdateBackground(renderizador, -1);
       
        peixe.estrutura.y = peixeMov * 4;
        UpdatePeixe(renderizador, peixe);

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
        if (coral.estrutura.x <= -100) {
            coral.estrutura.h = (rand() % 250) + 50;
            coral.estrutura.x = 800;
            coral.estrutura.y = 600 - coral.estrutura.h;
        }
        coral.estrutura.x = coral.estrutura.x - 5;
        UpdateCoral(renderizador, coral);

        //comida
        comida.estrutura.x = comida.estrutura.x - 3;
        UpdateComida(renderizador, comida);

        //linha
        UpdateLinha(renderizador, linha);
        
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
        UpdateAnzol(renderizador, anzol);

        //if (score % 10 <= 4) {
        //    NUM = 0;

        //}
        //if (score % 10 >= 5) {
        //    NUM = 1;
        //}

        //Numeros do score
        UpdateNumeros(renderizador, numeros, score);
        UpdateNumeros2(renderizador, numeros2, score);

        // Placa de score
        UpdatePlacar(renderizador, placar);

        //HitBox
        HitBoxComida(comida.estrutura, peixe.estrutura, score);
        HitBoxCoral(coral.estrutura, peixe.estrutura, peixeMov, score, linhaMov, TAMcoral);
        HitBoxLinha(linha.estrutura, peixe.estrutura, peixeMov, score, linhaMov, TAMcoral);
        HitBoxAnzol(anzol.estrutura, peixe.estrutura, peixeMov, score, linhaMov, TAMcoral);



        SDL_RenderPresent(renderizador); // Cola coisas na janela
        SDL_Delay(1000 / 60); // 60 fps

    }

    SDL_DestroyWindow(janela);
    SDL_Quit();
    return 0;
}