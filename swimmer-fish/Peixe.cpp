#include <SDL.h>
#include <iostream>
#include <string>

#include "Peixe.h"
#include "CarregaTextura.h"

Peixe SpawnPeixe(SDL_Renderer* renderizador, const char* textura, int altura) {

    Peixe peixe;
    peixe.textura = textura;
    peixe.altura = altura;
    peixe.texturaCarregada = CarregaTextura(textura, renderizador);

    SDL_Rect destinoPeixe;
    destinoPeixe.w = 100;
    destinoPeixe.h = 100;
    destinoPeixe.x = 50;
    destinoPeixe.y = altura;

    peixe.estrutura = destinoPeixe;

    SDL_RenderCopy(renderizador, peixe.texturaCarregada, NULL, &peixe.estrutura);

    return peixe;

}

void UpdatePeixe(SDL_Renderer* renderizador, Peixe peixe) {
    SDL_RenderCopy(renderizador, peixe.texturaCarregada, NULL, &peixe.estrutura);
}