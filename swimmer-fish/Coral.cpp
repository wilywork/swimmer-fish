#include <SDL.h>
#include <iostream>
#include <string>
#include <time.h>
#include "Coral.h"
#include "CarregaTextura.h"
#include "HitBox.h"

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

    coralMov++;
    if (coral.posicaoX <= -100) {
        coralMov = 0;
        TAMcoral = RandTamCoral();
    }

    return coral;

};