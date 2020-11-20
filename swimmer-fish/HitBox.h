#ifndef HEADER_H
#define HEADER_H

#include <SDL.h>

int RandTamCoral();

void HitBoxCoral(SDL_Rect destinoCoral, SDL_Rect &destinoPeixe, int& peixeMov, int& score, int& comidaRandX, int& coralMov, int& linhaMOV, int& comidaMov, int& TAMcoral);

void HitBoxComida(SDL_Rect destinoComida, SDL_Rect &destinoPeixe, int& comidaMov, int& score, int& comidaRandY, int& comidaMOV);

void HitBoxLinha(SDL_Rect destinoLinha, SDL_Rect &destinoPeixe, int& peixeMov, int& score, int& comidaRandX, int& coralMov, int& linhaMOV, int& comidaMov, int& TAMcoral);

void HitBoxAnzol(SDL_Rect destinoAnzol, SDL_Rect &destinoPeixe, int& peixeMov, int& score, int& comidaRandY, int& coralMov, int& linhaMOV, int& comidaMov, int& TAMcoral);


#endif // JOGO_H