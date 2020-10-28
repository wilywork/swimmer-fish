// https://www.youtube.com/watch?v=IDa8hfl_9Vk&t=217s&ab_channel=elieserdejesus
#include <iostream>
#include <string.h>
#define SDL_MAIN_HANDLED
#include <SDL.h>
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

void HitBoxCoral(SDL_Rect destinoComida, SDL_Rect destinoPeixe, int &peixeMov, int &score, int &TAMpeixe) {
    if (destinoPeixe.y + destinoPeixe.h > destinoComida.y) {
        if (destinoPeixe.x + destinoPeixe.w > destinoComida.x) {
            if (destinoPeixe.x < destinoComida.x + destinoComida.w) {
                peixeMov = 0;
                score = 0;
                TAMpeixe = 100;
            }
        }
    }
};

void HitBoxComida(SDL_Rect destinoComida, SDL_Rect destinoPeixe, int &TAMpeixe, int &comidaMov, int &score) {
    if (destinoPeixe.y + destinoPeixe.h > destinoComida.y + 10) {
        if (destinoPeixe.x + destinoPeixe.w > destinoComida.x + 5) {
            if (destinoPeixe.x < destinoComida.x + destinoComida.w) {
                TAMpeixe += 10;
                comidaMov = 0;
                score++;
                cout << "Score:" << score << endl;

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
                peixeMov -= 30;
                break;
            }
            break;
        }
    }
};

int main()
{

    SDL_Window* janela;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) // Inicia a SDL
        cout << SDL_GetError() << endl;

    janela = SDL_CreateWindow("Janela", // inicia a JANELA
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        0);

    SDL_Renderer* renderizador = SDL_CreateRenderer(janela, // Renderiza coisas na janela
        -1,
        SDL_RENDERER_ACCELERATED);

    // Imagens renderizadas
    SDL_Texture* fundo = CarregaTextura("imagens/fundoJogo.bmp", renderizador);
    SDL_Texture* peixe = CarregaTextura("imagens/peixe.bmp", renderizador);
    SDL_Texture* coral = CarregaTextura("imagens/coral.bmp", renderizador);
    SDL_Texture* comida = CarregaTextura("imagens/comida.bmp", renderizador);

    bool gameOver = false; // Variavel para manter o jogo aberto

    int peixeMov = 0;
    int coralMov = 0;
    int TAMpeixe = 100;
    int comidaMov = 0;
    int score = 0;
    while (!gameOver) {

        FuncEventos(gameOver, peixeMov);

        SDL_RenderClear(renderizador); // Limpa a janela


        SDL_RenderCopy(renderizador, fundo, NULL, NULL);

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
        if (destinoPeixe.y < 0)
        {
            peixeMov = 0;
        }
        SDL_RenderCopy(renderizador, peixe, NULL, &destinoPeixe);

        SDL_Rect destinoCoral;
        destinoCoral.w = 40;
        destinoCoral.h = 60 * (404 / 122);
        destinoCoral.x =  750 - (coralMov * 5);
        destinoCoral.y =  600 - destinoCoral.h;
        SDL_RenderCopy(renderizador, coral, NULL, &destinoCoral);
        coralMov++;
        if (destinoCoral.x <= -100) {
            coralMov = 0;
        }

        SDL_Rect destinoComida;
        destinoComida.w = 10;
        destinoComida.h = 10;
        destinoComida.x = 750 - (comidaMov * 8);
        destinoComida.y = 400;
        comidaMov++;
        if (destinoComida.x <= -100) {
            comidaMov = 0;
        }
        SDL_RenderCopy(renderizador, comida, NULL, &destinoComida);

        HitBoxComida(destinoComida, destinoPeixe, TAMpeixe, comidaMov, score);
        HitBoxCoral(destinoCoral, destinoPeixe, peixeMov, score, TAMpeixe);

        SDL_RenderPresent(renderizador); // Cola coisas na janela
        SDL_Delay(1000 / 60); // 60 fps

    }

    SDL_DestroyWindow(janela);
    SDL_Quit();
    return 0;
}