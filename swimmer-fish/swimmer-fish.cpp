#define SDL_MAIN_HANDLED

#include <iostream>
#include <string.h>
#include <SDL.h>

using namespace std;

const int LARGURA = 900;
const int ALTURA = 600;

int main() {

    SDL_Window* janela = NULL;

    SDL_Init(SDL_INIT_EVERYTHING);

    // inicia a JANELA
    janela = SDL_CreateWindow("Janela", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

    SDL_Delay(5000);
    SDL_DestroyWindow(janela);
    SDL_Quit();

	return 0;
}