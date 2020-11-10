// https://www.youtube.com/watch?v=IDa8hfl_9Vk&t=217s&ab_channel=elieserdejesus
#define SDL_MAIN_HANDLED

#include <iostream>
#include <string.h>
#include <SDL.h>
#include <time.h>

using namespace std;

// ============ FUNCOES ============

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

int RandTamCoral() {
        int TAMcoral = rand() % 100;
        while (TAMcoral < 30) {
            TAMcoral = rand() % 100;
            return TAMcoral;
        }
};

void HitBoxCoral(SDL_Rect destinoCoral, SDL_Rect destinoPeixe, int &peixeMov, int &score, int &TAMpeixe, int& comidaRandX,int &coralMov, int& linhaMOV, int& comidaMov, int &TAMcoral) {
    if (destinoPeixe.y + destinoPeixe.h > destinoCoral.y + 10) {
        if (destinoPeixe.x + destinoPeixe.w > destinoCoral.x + 5) {
            if (destinoPeixe.x < destinoCoral.x + destinoCoral.w) {
                peixeMov = 0;
                score = 0;
                TAMpeixe = 100;
                comidaRandX = rand() % 550;
                coralMov = 0;
                linhaMOV = 0;
                comidaMov = 0;
                TAMcoral = RandTamCoral();
            }
        }
    }
};

void HitBoxComida(SDL_Rect destinoComida, SDL_Rect destinoPeixe, int &TAMpeixe, int &comidaMov, int &score, int &comidaRandY, int &comidaMOV) {
    if (destinoPeixe.y + destinoPeixe.h > destinoComida.y) {
        if (destinoPeixe.y < destinoComida.y + destinoComida.h) {
            if (destinoPeixe.x + destinoPeixe.w > destinoComida.x) {
                if (destinoPeixe.x < destinoComida.x + destinoComida.w) {
                    TAMpeixe += 10;
                    comidaMov = 0;
                    score++;
                    cout << "Score:" << score << endl;
                    comidaRandY =  rand() % 550;
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
                    peixeMov = 0;
                    score = 0;
                    TAMpeixe = 100;
                    comidaRandX = rand() % 550;
                    coralMov = 0;
                    linhaMOV = 0;
                    comidaMov = 0;
                    TAMcoral = RandTamCoral();
                }
            }
        }
    }
};

void HitBoxAnzol(SDL_Rect destinoAnzol, SDL_Rect destinoPeixe, int& peixeMov, int& score, int& TAMpeixe, int& comidaRandY, int& coralMov, int& linhaMOV, int& comidaMov, int& TAMcoral) {
    if (destinoPeixe.y + destinoPeixe.h > destinoAnzol.y) {
        if (destinoPeixe.y < destinoAnzol.y + destinoAnzol.h) {
            if (destinoPeixe.x + destinoPeixe.w > destinoAnzol.x) {
                if (destinoPeixe.x < destinoAnzol.x + destinoAnzol.w) {
                    peixeMov = 0;
                    score = 0;
                    TAMpeixe = 100;
                    comidaRandY = rand() % 550;
                    coralMov = 0;
                    linhaMOV = 0;
                    comidaMov = 0;
                    TAMcoral = RandTamCoral();
                }
            }
        }
    }
};

void FuncEventos(bool &gameOver,int &peixeMov ) {
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
                if (peixeMov >= 0) {
                    peixeMov -= 30;
                }
                break;
            }
            break;
        }
    }
};

// ============ FIM FUNCOES ============
int main()
{
    bool jogoAtivo = true;
    bool menuAtivo = true;

    SDL_Window* janela;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) // Inicia a SDL
        cout << SDL_GetError() << endl;

    // inicia a JANELA
    janela = SDL_CreateWindow("Janela", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

    // Renderiza coisas na janela
    SDL_Renderer* renderizador = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);

    // Imagens renderizadas
    SDL_Texture* fundo = CarregaTextura("imagens/fundoJogo.bmp", renderizador);
    SDL_Texture* peixe = CarregaTextura("imagens/peixe.bmp", renderizador);
    SDL_Texture* coral = CarregaTextura("imagens/coral.bmp", renderizador);
    SDL_Texture* comida = CarregaTextura("imagens/comida.bmp", renderizador);
    SDL_Texture* linha = CarregaTextura("imagens/linha.bmp", renderizador);
    SDL_Texture* anzol = CarregaTextura("imagens/anzol.bmp", renderizador);

    srand(time(NULL));

    // Variavel para manter o jogo aberto
    bool gameOver = false;

    int peixeMov = 0;
    int coralMov = 0;
    int TAMpeixe = 100;
    int comidaMov = 0;
    int score = 0;
    int linhaMov = 0;
    int TAMlinhaH = 0;
    int comidaRandY = 250;
    int TAMcoral = 30;

    SDL_RenderCopy(renderizador, CarregaTextura("imagens/play.bmp", renderizador), NULL, NULL);
    // Cola coisas na janela
    SDL_RenderPresent(renderizador);
    SDL_Delay(1000 / 60); // 60 fps

    while (menuAtivo) {
        SDL_Event evento;

        SDL_PollEvent(&evento);

        if (evento.type == SDL_KEYDOWN) {
            if (evento.key.keysym.sym == SDLK_KP_ENTER || evento.key.keysym.sym == SDLK_RETURN) {
                menuAtivo = false;
            }
        }
    }

    while (!gameOver) {

        FuncEventos(gameOver, peixeMov);

        SDL_RenderClear(renderizador); // Limpa a janela

        SDL_RenderCopy(renderizador, fundo, NULL, NULL);

        //Peixe
        SDL_Rect destinoPeixe;
        destinoPeixe.w = TAMpeixe;
        destinoPeixe.h = TAMpeixe;
        destinoPeixe.x = 50;
        destinoPeixe.y =  peixeMov * 4;
        if (destinoPeixe.y >= 520) {
            destinoPeixe.y = 520;
        }
        else
        {
            peixeMov++;
        }

        SDL_RenderCopy(renderizador, peixe, NULL, &destinoPeixe);

        //coral
        SDL_Rect destinoCoral;
        destinoCoral.w = 40;
        destinoCoral.h = TAMcoral * (404 / 122);
        destinoCoral.x =  750 - (coralMov * 5);
        destinoCoral.y =  600 - destinoCoral.h;
        coralMov++;
        if (destinoCoral.x <= -100) {
            coralMov = 0;
            TAMcoral = RandTamCoral();
        }
        SDL_RenderCopy(renderizador, coral, NULL, &destinoCoral);

        //comida
        SDL_Rect destinoComida;
        destinoComida.w = 10;
        destinoComida.h = 10;
        destinoComida.x = 750 - (comidaMov * 8);
        destinoComida.y = comidaRandY;
        comidaMov++;
        if (destinoComida.x <= -100) {
            comidaMov = 0;
            comidaRandY = rand() % 550;
        }
        SDL_RenderCopy(renderizador, comida, NULL, &destinoComida);

        //linha
        SDL_Rect destinoLinha;
        destinoLinha.w = 3;
        destinoLinha.h = 10 + (TAMlinhaH * 4);
        destinoLinha.x = 850 - (linhaMov * 3);
        destinoLinha.y = 0;
        linhaMov++;
        if (destinoLinha.x <= -100) {
            linhaMov = 0;
        }
        TAMlinhaH++;
        if (destinoLinha.h >= 550 - (destinoCoral.h + destinoPeixe.h + 75) ) {
            TAMlinhaH = 0;
        }
        SDL_RenderCopy(renderizador, linha, NULL, &destinoLinha);

        //Azol
        SDL_Rect destinoAnzol;
        destinoAnzol.w = 25;
        destinoAnzol.h = 25;
        destinoAnzol.x = destinoLinha.x -13;
        destinoAnzol.y = destinoLinha.h;
        SDL_RenderCopy(renderizador, anzol, NULL, &destinoAnzol);


        //HitBox
        HitBoxComida(destinoComida, destinoPeixe, TAMpeixe, comidaMov, score, comidaRandY, comidaMov);
        HitBoxCoral(destinoCoral, destinoPeixe, peixeMov, score, TAMpeixe, comidaRandY, coralMov, linhaMov, comidaMov, TAMcoral);
        HitBoxLinha(destinoLinha, destinoPeixe, peixeMov, score, TAMpeixe, comidaRandY, coralMov, linhaMov, comidaMov, TAMcoral);
        HitBoxAnzol(destinoAnzol, destinoPeixe, peixeMov, score, TAMpeixe, comidaRandY, coralMov, linhaMov, comidaMov, TAMcoral);

        SDL_RenderPresent(renderizador); // Cola coisas na janela
        SDL_Delay(1000 / 60); // 60 fps

    }

    SDL_DestroyWindow(janela);
    SDL_Quit();
    return 0;
}