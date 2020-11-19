#include <SDL.h>
#include <iostream>
#include <string>
#include "Placar.h"
#include "CarregaTextura.h"

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

    placar.estrutura = destinoPlacar;

    placar.texturaCarregada = CarregaTextura(textura, renderizador);

    SDL_RenderCopy(renderizador, placar.texturaCarregada, NULL, &destinoPlacar);

    return placar;

};

Numeros SpawnNumeros(SDL_Renderer* renderizador, const char* textura, int score, int NUM) {

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

    Numeros numeros;
    numeros.tamanhoW = destinoNumeros.w;
    numeros.tamanhoH = destinoNumeros.h;
    numeros.posicaoX = destinoNumeros.x;
    numeros.posicaoY = destinoNumeros.y;
    numeros.OtamanhoW = origemNumeros.w;
    numeros.OtamanhoH = origemNumeros.h;
    numeros.OposicaoX = origemNumeros.x;
    numeros.OposicaoY = origemNumeros.y;


    numeros.estrutura = destinoNumeros;

    numeros.texturaCarregada = CarregaTextura(textura, renderizador);

    SDL_RenderCopy(renderizador, numeros.texturaCarregada, NULL, &destinoNumeros);

    return numeros;

};

