#include <iostream>
#include <SDL.h>
#include <time.h>

using namespace std;

int RandTamCoral() {
    int TAMcoral = rand() % 100;
    while (TAMcoral < 30) {
        TAMcoral = rand() % 100;
        return TAMcoral;
    }
};

void reset(int& peixeMov, int& score, int& TAMpeixe, int& comidaRandX, int& coralMov, int& linhaMOV, int& comidaMov, int& TAMcoral) {

    peixeMov = 0;
    score = 0;
    TAMpeixe = 100;
    comidaRandX = rand() % 550;
    coralMov = 0;
    linhaMOV = 0;
    comidaMov = 0;
    TAMcoral = RandTamCoral();
};

void HitBoxCoral(SDL_Rect destinoCoral, SDL_Rect destinoPeixe, int& peixeMov, int& score, int& TAMpeixe, int& comidaRandX, int& coralMov, int& linhaMOV, int& comidaMov, int& TAMcoral) {
    if (destinoPeixe.y + destinoPeixe.h > destinoCoral.y + 10) {
        if (destinoPeixe.x + destinoPeixe.w > destinoCoral.x + 5) {
            if (destinoPeixe.x < destinoCoral.x + destinoCoral.w) {
                reset(peixeMov, score, TAMpeixe, comidaRandX, coralMov, linhaMOV, comidaMov, TAMcoral);
            }
        }
    }
};

void HitBoxComida(SDL_Rect destinoComida, SDL_Rect destinoPeixe, int& TAMpeixe, int& comidaMov, int& score, int& comidaRandY, int& comidaMOV) {
    if (destinoPeixe.y + destinoPeixe.h > destinoComida.y) {
        if (destinoPeixe.y < destinoComida.y + destinoComida.h) {
            if (destinoPeixe.x + destinoPeixe.w > destinoComida.x) {
                if (destinoPeixe.x < destinoComida.x + destinoComida.w) {
                    TAMpeixe += 5;
                    comidaMov = 0;
                    score++;
                    cout << "Score:" << score << endl;
                    comidaRandY = rand() % 550;
                    comidaMOV = 0;

                }
            }
        }
    }
};

void HitBoxLinha(SDL_Rect destinoLinha, SDL_Rect destinoPeixe, int& peixeMov, int& score, int& TAMpeixe, int& comidaRandX, int& coralMov, int& linhaMOV, int& comidaMov, int& TAMcoral) {
    if (destinoPeixe.y + destinoPeixe.h > destinoLinha.y) {
        if (destinoPeixe.y < destinoLinha.y + destinoLinha.h) {
            if (destinoPeixe.x + destinoPeixe.w > destinoLinha.x) {
                if (destinoPeixe.x < destinoLinha.x + destinoLinha.w) {
                    reset(peixeMov, score, TAMpeixe, comidaRandX, coralMov, linhaMOV, comidaMov, TAMcoral);
                }
            }
        }
    }
};

void HitBoxAnzol(SDL_Rect destinoAnzol, SDL_Rect destinoPeixe, int& peixeMov, int& score, int& TAMpeixe, int& comidaRandX, int& coralMov, int& linhaMOV, int& comidaMov, int& TAMcoral) {
    if (destinoPeixe.y + destinoPeixe.h > destinoAnzol.y) {
        if (destinoPeixe.y < destinoAnzol.y + destinoAnzol.h) {
            if (destinoPeixe.x + destinoPeixe.w > destinoAnzol.x) {
                if (destinoPeixe.x < destinoAnzol.x + destinoAnzol.w) {
                    reset(peixeMov, score, TAMpeixe, comidaRandX, coralMov, linhaMOV, comidaMov, TAMcoral);
                }
            }
        }
    }
};