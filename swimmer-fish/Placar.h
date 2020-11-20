#ifndef PLACAR_H
#define PLACAR_H

typedef struct {
	int tamanhoW;
	int tamanhoH;
	int posicaoX;
	int posicaoY;
	const char* textura;
	SDL_Rect estrutura;
	SDL_Texture* texturaCarregada;
} Placar;

typedef struct {
	int tamanhoW;
	int tamanhoH;
	int posicaoX;
	int posicaoY;

	const char* textura;
	SDL_Rect origem;
	SDL_Rect estrutura;
	SDL_Texture* texturaCarregada;
} Numeros;

Placar SpawnPlacar(SDL_Renderer* renderizador, const char* textura);

void UpdatePlacar(SDL_Renderer* renderizador, Placar placar);

Numeros SpawnNumeros(SDL_Renderer* renderizador, const char* textura, int score, int NUM);

void UpdateNumeros(SDL_Renderer* renderizador, Numeros numeros, int score);

#endif 