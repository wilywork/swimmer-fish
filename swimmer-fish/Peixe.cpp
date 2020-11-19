#include <SDL.h>
#include <iostream>
#include <string>

#include "Peixe.h"
#include "CarregaTextura.h"

SDL_Texture* texturaCarregada;

Peixe SpawnPeixe(SDL_Renderer* renderizador, const char* textura, int tamanho, int altura) {

    Peixe peixe;
    peixe.tamanho = tamanho;
    peixe.textura = textura;
    peixe.altura = altura;

    SDL_Rect destinoPeixe;
    destinoPeixe.w = tamanho;
    destinoPeixe.h = tamanho;
    destinoPeixe.x = 50;
    destinoPeixe.y = altura;

    peixe.estrutura = destinoPeixe;

    if (!texturaCarregada) {
        texturaCarregada = CarregaTextura(textura, renderizador);
    }

    SDL_RenderCopy(renderizador, texturaCarregada, NULL, &peixe.estrutura);

    return peixe;

}
