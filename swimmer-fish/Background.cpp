#include <SDL.h>
#include <iostream>

#include "Background.h"
#include "CarregaTextura.h"

const int quantidadeDeFundos = 4;

const char* ImagensBackground[quantidadeDeFundos] = {
    "assets/imagens/parallax/fundo1.bmp",
    "assets/imagens/parallax/fundo2.bmp",
    "assets/imagens/parallax/fundo3.bmp",
    "assets/imagens/parallax/fundo4.1.bmp"
};

SDL_Texture* texturaCarregada[quantidadeDeFundos];

void SpawnBackground(SDL_Renderer* renderizador, int movimento) {

    for (int i = 0; i < quantidadeDeFundos; i++)
    {
        if (!texturaCarregada[i]) {
            texturaCarregada[i] = CarregaTextura(ImagensBackground[i], renderizador);
        }

        SDL_Rect fundo;
        fundo.w = 800;
        fundo.h = 353;
        fundo.x = 0 + movimento + i;
        fundo.y = 100;
        
        SDL_RenderCopy(renderizador, texturaCarregada[i], NULL, &fundo);

        SDL_Rect fundoDuplicado;
        fundoDuplicado.w = 800;
        fundoDuplicado.h = 353;
        fundoDuplicado.x = 0 + movimento + i;
        fundoDuplicado.y = 100;
        SDL_RenderCopy(renderizador, texturaCarregada[i], NULL, &fundoDuplicado);

    }

}
