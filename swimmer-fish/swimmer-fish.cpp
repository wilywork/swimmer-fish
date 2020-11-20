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
    int coralMov = 0;
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

    Peixe peixe = SpawnPeixe(renderizador, "assets/imagens/peixe.bmp", peixeMov);
    Placar placar = SpawnPlacar(renderizador, "assets/imagens/score.bmp");
    Numeros numeros = SpawnNumeros(renderizador, "assets/imagens/numeros2.bmp", score, NUM);

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
        UpdateNumeros(renderizador, numeros);

        if (score >= 10) {
            scoreDezena = score / 10;
            if (scoreDezena <= 4) {
                NUM = 0;

            }
            if (scoreDezena >= 5) {
                NUM = 1;
            }
            UpdateNumeros(renderizador, numeros);
        }

        // Placa de score
        UpdatePlacar(renderizador, placar);

        //HitBox
        HitBoxComida(comida.estrutura, peixe.estrutura, comidaMov, score, comidaRandY, comidaMov);
        HitBoxCoral(coral.estrutura, peixe.estrutura, peixeMov, score, comidaRandY, coralMov, linhaMov, comidaMov, TAMcoral);
        HitBoxLinha(linha.estrutura, peixe.estrutura, peixeMov, score, comidaRandY, coralMov, linhaMov, comidaMov, TAMcoral);
        HitBoxAnzol(anzol.estrutura, peixe.estrutura, peixeMov, score, comidaRandY, coralMov, linhaMov, comidaMov, TAMcoral);



        SDL_RenderPresent(renderizador); // Cola coisas na janela
        SDL_Delay(1000 / 60); // 60 fps

    }

    SDL_DestroyWindow(janela);
    SDL_Quit();
    return 0;
}