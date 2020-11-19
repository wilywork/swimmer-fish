#include <SDL.h>

void FuncEventos(bool& gameOver, int& peixeMov, int& pressUpPeixe) {
    SDL_Event evento;
    while (SDL_PollEvent(&evento) != 0) {
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
        case SDL_KEYUP:
            switch (evento.key.keysym.sym) {
            case SDLK_UP:
            case SDLK_w:
                    pressUpPeixe = false;
                break;
            }
            break;
        default:
            break;
        }
    }
};
