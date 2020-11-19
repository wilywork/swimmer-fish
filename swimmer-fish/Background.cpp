#include <SDL.h>
#include <iostream>

#include "Background.h"
#include "CarregaTextura.h"

void SpawnBackground(SDL_Renderer* renderizador, const char* texturas[], int total, int MOVfundo2) {

    for (int i = 0; i < total; i++)
    {
        SDL_Texture* texturaCarregada = CarregaTextura(texturas[i], renderizador);

        SDL_Rect fundo;
        fundo.w = 800;
        fundo.h = 353;
        fundo.x = 0 + MOVfundo2;
        fundo.y = 100;
        
        SDL_RenderCopy(renderizador, texturaCarregada, NULL, &fundo);

        SDL_Rect fundoDuplicado;
        fundoDuplicado.w = 800;
        fundoDuplicado.h = 353;
        fundoDuplicado.x = 0 + MOVfundo2;
        fundoDuplicado.y = 100;
        SDL_RenderCopy(renderizador, texturaCarregada, NULL, &fundoDuplicado);

    }

}
