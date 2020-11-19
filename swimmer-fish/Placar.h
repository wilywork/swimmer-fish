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

Placar SpawnPlacar(SDL_Renderer* renderizador, const char* textura);

typedef struct {
	int tamanhoW;
	int tamanhoH;
	int posicaoX;
	int posicaoY;
	int OtamanhoW;
	int OtamanhoH;
	int OposicaoX;
	int OposicaoY;
	const char* textura;
	SDL_Rect origem;
	SDL_Rect estrutura;
	SDL_Texture* texturaCarregada;
} Numeros;

Numeros SpawnNumeros(SDL_Renderer* renderizador, const char* textura, int score, int NUM);

#endif 