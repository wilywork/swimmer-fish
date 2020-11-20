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

SDL_Texture* texturaCarregadaFundo[quantidadeDeFundos];

SDL_Rect estruturaFundo1[quantidadeDeFundos];
SDL_Rect estruturaFundo2[quantidadeDeFundos];

void SpawnBackground(SDL_Renderer* renderizador) {
    
    for (int i = 0; i < quantidadeDeFundos; i++)
    {
        if (!texturaCarregadaFundo[i]) {
            texturaCarregadaFundo[i] = CarregaTextura(ImagensBackground[i], renderizador);
        }

      
        estruturaFundo1[i].w = 800;
        estruturaFundo1[i].h = 600;
        estruturaFundo1[i].x = 0;
        estruturaFundo1[i].y = 0;
        SDL_RenderCopy(renderizador, texturaCarregadaFundo[i], NULL, &estruturaFundo1[i]);

        estruturaFundo2[i].w = 800;
        estruturaFundo2[i].h = 600;
        estruturaFundo2[i].x = 800;
        estruturaFundo2[i].y = 0;
        SDL_RenderCopy(renderizador, texturaCarregadaFundo[i], NULL, &estruturaFundo2[i]);
    }
}

void UpdateBackground(SDL_Renderer* renderizador, int movimento) {
    for (int i = 0; i < quantidadeDeFundos; i++)
    {
        movimento = movimento - i;

        if (estruturaFundo1[i].x <= -800) {
            estruturaFundo1[i].x = 0;
        }
        if (estruturaFundo2[i].x <= 0) {
            estruturaFundo2[i].x = 800;
        }
        estruturaFundo1[i].x = estruturaFundo1[i].x + movimento;
        estruturaFundo2[i].x = estruturaFundo2[i].x + movimento;
        SDL_RenderCopy(renderizador, texturaCarregadaFundo[i], NULL, &estruturaFundo1[i]);
        SDL_RenderCopy(renderizador, texturaCarregadaFundo[i], NULL, &estruturaFundo2[i]);
    }
}
