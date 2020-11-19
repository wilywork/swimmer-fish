#include <SDL.h>
#include <iostream>
#include <string>

#include "Peixe.h"
#include "CarregaTextura.h"

Peixe SpawnPeixe(SDL_Renderer* renderizador, const char* textura, int tamanho, int altura) {

    Peixe peixe;
    peixe.tamanho = tamanho;
    peixe.textura = textura;
    peixe.altura = altura;

    peixe.estrutura = {
        tamanho,
        tamanho,
        50,
        altura
    };

    SDL_Texture* texturaCarregada = CarregaTextura(textura, renderizador);

    SDL_RenderCopy(renderizador, texturaCarregada, NULL, &peixe.estrutura);

    return peixe;

}
