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

void reset(SDL_Rect &destinoPeixe, int& peixeMov, int& score, int& comidaRandX, int& coralMov, int& linhaMOV, int& TAMcoral) {
    peixeMov = 0;
    score = 0;
    destinoPeixe.w = 100;
    destinoPeixe.h = 100;
    comidaRandX = rand() % 550;
    coralMov = 0;
    linhaMOV = 0;
    TAMcoral = RandTamCoral();
};

void HitBoxCoral(SDL_Rect destinoCoral, SDL_Rect &destinoPeixe, int& peixeMov, int& score, int& comidaRandX,int & coralMov, int& linhaMOV, int& TAMcoral) {
    if (destinoPeixe.y + destinoPeixe.h > destinoCoral.y + 10) {
        if (destinoPeixe.x + destinoPeixe.w > destinoCoral.x + 5) {
            if (destinoPeixe.x < destinoCoral.x + destinoCoral.w) {
                reset(destinoPeixe, peixeMov, score, comidaRandX, coralMov, linhaMOV, TAMcoral);
            }
        }
    }
};

void HitBoxComida(SDL_Rect destinoComida, SDL_Rect &destinoPeixe, int& score, int& comidaRandY) {
    if (destinoPeixe.y + destinoPeixe.h > destinoComida.y) {
        if (destinoPeixe.y < destinoComida.y + destinoComida.h) {
            if (destinoPeixe.x + destinoPeixe.w > destinoComida.x) {
                if (destinoPeixe.x < destinoComida.x + destinoComida.w) {

                    //aumentar tamanho do peixe
                    destinoPeixe.w += 5;
                    destinoPeixe.h += 5;

                    //por comida novamente
                    if (destinoComida.x <= -100) {
                        destinoComida.x = rand() % 550;
                    }
                    destinoComida.x = 800;

                    score++;
                    cout << "Score:" << score << endl;
                    comidaRandY = rand() % 550;
                }
            }
        }
    }
};

void HitBoxLinha(SDL_Rect destinoLinha, SDL_Rect &destinoPeixe, int& peixeMov, int& score, int& comidaRandX, int& coralMov, int& linhaMOV, int& TAMcoral) {
    if (destinoPeixe.y + destinoPeixe.h > destinoLinha.y) {
        if (destinoPeixe.y < destinoLinha.y + destinoLinha.h) {
            if (destinoPeixe.x + destinoPeixe.w > destinoLinha.x) {
                if (destinoPeixe.x < destinoLinha.x + destinoLinha.w) {
                    reset(destinoPeixe, peixeMov, score, comidaRandX, coralMov, linhaMOV, TAMcoral);
                }
            }
        }
    }
};

void HitBoxAnzol(SDL_Rect destinoAnzol, SDL_Rect &destinoPeixe, int& peixeMov, int& score, int& comidaRandX, int& coralMov, int& linhaMOV, int& TAMcoral) {
    if (destinoPeixe.y + destinoPeixe.h > destinoAnzol.y) {
        if (destinoPeixe.y < destinoAnzol.y + destinoAnzol.h) {
            if (destinoPeixe.x + destinoPeixe.w > destinoAnzol.x) {
                if (destinoPeixe.x < destinoAnzol.x + destinoAnzol.w) {
                    reset(destinoPeixe, peixeMov, score, comidaRandX, coralMov, linhaMOV, TAMcoral);
                }
            }
        }
    }
};