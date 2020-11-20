#include <SDL.h>
#include <iostream>
#include <string>
#include "Placar.h"
#include "CarregaTextura.h"

using namespace std;

Placar SpawnPlacar(SDL_Renderer* renderizador, const char* textura) {

    SDL_Rect destinoPlacar;
    destinoPlacar.w = 87;
    destinoPlacar.h = 34;
    destinoPlacar.x = 623;
    destinoPlacar.y = 20;

    Placar placar;
    placar.tamanhoW = destinoPlacar.w;
    placar.tamanhoH = destinoPlacar.h;
    placar.posicaoX = destinoPlacar.x;
    placar.posicaoY = destinoPlacar.y;
    placar.texturaCarregada = CarregaTextura(textura, renderizador);

    placar.estrutura = destinoPlacar;

    placar.texturaCarregada = CarregaTextura(textura, renderizador);

    SDL_RenderCopy(renderizador, placar.texturaCarregada, NULL, &destinoPlacar);

    return placar;

};

void UpdatePlacar(SDL_Renderer* renderizador, Placar placar) {
    SDL_RenderCopy(renderizador, placar.texturaCarregada, NULL, &placar.estrutura);
}

Numeros SpawnNumeros(SDL_Renderer* renderizador, const char* textura, int score, int NUM) {

    SDL_Rect origemNumeros;
    origemNumeros.x = 62 * (score % 5);
    origemNumeros.y = 79 * NUM;
    origemNumeros.w = 62;
    origemNumeros.h = 79;
    SDL_Rect estrutura;
    estrutura.w = 33;
    estrutura.h = 33;
    estrutura.x = 750;
    estrutura.y = 20;

    Numeros numeros;
    numeros.tamanhoW = estrutura.w;
    numeros.tamanhoH = estrutura.h;
    numeros.posicaoX = estrutura.x;
    numeros.posicaoY = estrutura.y;
    numeros.texturaCarregada = CarregaTextura(textura, renderizador);



    numeros.estrutura = estrutura;
    numeros.origem = origemNumeros;

    numeros.texturaCarregada = CarregaTextura(textura, renderizador);

    SDL_RenderCopy(renderizador, numeros.texturaCarregada, &numeros.origem, &numeros.estrutura);

    return numeros;

};

void UpdateNumeros(SDL_Renderer* renderizador, Numeros numeros, int score) {

    int NUM = 0;
    int scoreDezena = 0;
    
    if (score % 10 <= 4) {
        NUM = 0;

    }
    if (score % 10 >= 5) {
        NUM = 1;
    }
    numeros.origem.x = 62 * (score % 5);
    numeros.origem.y = 79 * NUM;
    SDL_RenderCopy(renderizador, numeros.texturaCarregada, &numeros.origem, &numeros.estrutura);


}


Numeros2 SpawnNumeros2(SDL_Renderer* renderizador, const char* textura, int score, int NUM) {

    SDL_Rect origemNumeros;
    origemNumeros.x = 62 * (score % 5);
    origemNumeros.y = 79 * NUM;
    origemNumeros.w = 62;
    origemNumeros.h = 79;

    SDL_Rect estrutura;
    estrutura.w = 33;
    estrutura.h = 33;
    estrutura.x = 720;
    estrutura.y = 20;

    Numeros2 numeros2;
    numeros2.tamanhoW = estrutura.w;
    numeros2.tamanhoH = estrutura.h;
    numeros2.posicaoX = estrutura.x;
    numeros2.posicaoY = estrutura.y;

    numeros2.texturaCarregada = CarregaTextura(textura, renderizador);


    numeros2.estrutura = estrutura;
    numeros2.origem = origemNumeros;

    numeros2.texturaCarregada = CarregaTextura(textura, renderizador);

    SDL_RenderCopy(renderizador, numeros2.texturaCarregada, &numeros2.origem, &numeros2.estrutura);

    return numeros2;

};

void UpdateNumeros2(SDL_Renderer* renderizador, Numeros2 numeros2, int score) {
    int NUM = 0;
    int scoreDezena = 0;

    if (score >= 10) {
        scoreDezena = score / 10;
        if (scoreDezena <= 4) {
            NUM = 0;

        }
        if (scoreDezena >= 5) {
            NUM = 1;
        }

        numeros2.origem.x = 62 * scoreDezena;
        numeros2.origem.y = 79 * NUM;


        SDL_RenderCopy(renderizador, numeros2.texturaCarregada, &numeros2.origem, &numeros2.estrutura);
    }
};


