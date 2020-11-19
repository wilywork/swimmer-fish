#include <SDL.h>
#include <iostream>
#include <string>
#include "Objetos.h"
#include "CarregaTextura.h"

Comida SpawnComida(SDL_Renderer* renderizador, const char* textura, int comidaMov, int comidaRandY) {

    SDL_Rect destinoComida;
    destinoComida.w = 10;
    destinoComida.h = 10;
    destinoComida.x = 750 - (comidaMov * 8);
    destinoComida.y = comidaRandY;

    Comida comida;
    comida.tamanhoW = destinoComida.w;
    comida.tamanhoH = destinoComida.h;
    comida.posicaoX = destinoComida.x;
    comida.posicaoY = destinoComida.y;

    comida.estrutura = destinoComida;

    comida.texturaCarregada = CarregaTextura(textura, renderizador);

    SDL_RenderCopy(renderizador, comida.texturaCarregada, NULL, &destinoComida);

    return comida;

};

Coral SpawnCoral(SDL_Renderer* renderizador, const char* textura, int TAMcoral, int coralMov) {

    SDL_Rect destinoCoral;
    destinoCoral.w = 40;
    destinoCoral.h = TAMcoral * (404 / 122);
    destinoCoral.x = 750 - (coralMov * 7);
    destinoCoral.y = 600 - destinoCoral.h;

    Coral coral;
    coral.tamanhoW = destinoCoral.w;
    coral.tamanhoH = destinoCoral.h;
    coral.posicaoX = destinoCoral.x;
    coral.posicaoY = destinoCoral.y;

    coral.estrutura = destinoCoral;

    coral.texturaCarregada = CarregaTextura(textura, renderizador);

    SDL_RenderCopy(renderizador, coral.texturaCarregada, NULL, &destinoCoral);

    return coral;

};

Linha SpawnLinha(SDL_Renderer* renderizador, const char* textura,int TAMlinhaH, int linhaMov) {

    SDL_Rect destinoLinha;
    destinoLinha.w = 3;
    destinoLinha.h = 10 + TAMlinhaH;// (TAMlinhaH * 4);
    destinoLinha.x = 850 - linhaMov;// (linhaMov * 3);
    destinoLinha.y = 0;

    Linha linha;
    linha.tamanhoW = destinoLinha.w;
    linha.tamanhoH = destinoLinha.h;
    linha.posicaoX = destinoLinha.x;
    linha.posicaoY = destinoLinha.y;

    linha.estrutura = destinoLinha;

    linha.texturaCarregada = CarregaTextura(textura, renderizador);

    SDL_RenderCopy(renderizador, linha.texturaCarregada, NULL, &destinoLinha);

    return linha;

};

Anzol SpawnAnzol(SDL_Renderer* renderizador, const char* textura, Linha linha) {

    SDL_Rect destinoAnzol;
    destinoAnzol.w = 25;
    destinoAnzol.h = 25;
    destinoAnzol.x = linha.posicaoX - 13;
    destinoAnzol.y = linha.tamanhoH;

    Anzol anzol;
    anzol.tamanhoW = destinoAnzol.w;
    anzol.tamanhoH = destinoAnzol.h;
    anzol.posicaoX = destinoAnzol.x;
    anzol.posicaoY = destinoAnzol.y;

    anzol.estrutura = destinoAnzol;

    anzol.texturaCarregada = CarregaTextura(textura, renderizador);

    SDL_RenderCopy(renderizador, anzol.texturaCarregada, NULL, &destinoAnzol);

    return anzol;

};
