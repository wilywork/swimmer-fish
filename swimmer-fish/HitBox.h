#ifndef HEADER_H
#define HEADER_H

#include <SDL.h>

int RandTamCoral();

void HitBoxCoral(SDL_Rect &destinoCoral, SDL_Rect &destinoPeixe, int& peixeMov, int& score, int& linhaMOV, int& TAMcoral, SDL_Rect& destinoLinha);

void HitBoxComida(SDL_Rect &destinoComida, SDL_Rect &destinoPeixe, int& score);

void HitBoxLinha(SDL_Rect &destinoLinha, SDL_Rect &destinoPeixe, int& peixeMov, int& score, int& linhaMOV, int& TAMcoral, SDL_Rect& destinoCoral);

//void HitBoxAnzol(SDL_Rect &destinoAnzol, SDL_Rect &destinoPeixe, int& peixeMov, int& score, int& linhaMOV, int& TAMcoral);


#endif // JOGO_H