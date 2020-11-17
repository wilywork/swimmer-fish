#include <SDL.h>
#include <iostream>

using namespace std;

SDL_Texture* CarregaTextura(const char* imagem, SDL_Renderer* renderizador)
{
    SDL_Surface* surface = SDL_LoadBMP(imagem); // Pega uma imagem/arquivo para a surface
    if (!surface) {
        cout << "Erro ao carregar: " << imagem << endl;
    }

    SDL_Texture* textura = SDL_CreateTextureFromSurface(renderizador, surface); // Textura recebe a surface

    SDL_FreeSurface(surface); // Limpa a surface

    return textura;
};