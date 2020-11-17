#include <SDL.h>

void Menu(bool& menuAtivo) {
    while (menuAtivo) {
        SDL_Event evento;

        SDL_PollEvent(&evento);

        if (evento.type == SDL_KEYDOWN) {
            if (evento.key.keysym.sym == SDLK_KP_ENTER || evento.key.keysym.sym == SDLK_RETURN) {
                menuAtivo = false;
            }
        }
    }
}