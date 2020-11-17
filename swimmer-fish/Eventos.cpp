#include <SDL.h>

void FuncEventos(bool& gameOver, int& peixeMov, int& pressUpPeixe) {
    SDL_Event evento;
    while (SDL_PollEvent(&evento)) {
        switch (evento.type) {
        case SDL_QUIT:
            gameOver = true;
            break;

        case SDL_KEYDOWN:
            switch (evento.key.keysym.sym) {
            case SDLK_UP:
            case SDLK_w:
                if (peixeMov >= -10) {
                    pressUpPeixe = true;
                    peixeMov -= 1;
                }
                break;
            }
            break;
        default:
            pressUpPeixe = false;
            break;
        }
    }
};