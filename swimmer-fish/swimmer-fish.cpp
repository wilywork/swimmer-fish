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

    bool gameOver = false; // Variavel para manter o jogo aberto

    int peixeMov = 0;
    int coralMov = 0;
    while (!gameOver) {

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
                    cout << "CIMA" << endl;
                    peixeMov -= 30;
                    break;
                }
                break;
            }
        }

        SDL_RenderClear(renderizador); // Limpa a janela


        SDL_RenderCopy(renderizador, fundo, NULL, NULL);

        SDL_Rect destinoPeixe;
        destinoPeixe.w = 100;
        destinoPeixe.h = 100;
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

        if (destinoPeixe.y + destinoPeixe.h > destinoCoral.y+10) {
            if (destinoPeixe.x + destinoPeixe.w > destinoCoral.x+5) {
                if (destinoPeixe.x < destinoCoral.x + destinoCoral.w) {
                    cout << "TESTE" << endl;
                    peixeMov = 0;
                }
            }
        }

        SDL_RenderPresent(renderizador); // Cola coisas na janela
        SDL_Delay(1000 / 60); // 60 fps

    }

    SDL_DestroyWindow(janela);
    SDL_Quit();
    return 0;
}
