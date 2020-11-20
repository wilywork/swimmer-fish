#ifndef OBJETOS_H
#define OBJETOS_H

typedef struct {
	int tamanhoW;
	int tamanhoH;
	int posicaoX;
	int posicaoY;
	const char* textura;
	SDL_Rect estrutura;
	SDL_Texture* texturaCarregada;
} Comida;

Comida SpawnComida(SDL_Renderer* renderizador, const char* textura, int comidaMov, int comidaRandY);

void UpdateComida(SDL_Renderer* renderizador, Comida comida);

typedef struct {
	int tamanhoW;
	int tamanhoH;
	int posicaoX;
	int posicaoY;
	const char* textura;
	SDL_Rect estrutura;
	SDL_Texture* texturaCarregada;
} Coral;

Coral SpawnCoral(SDL_Renderer* renderizador, const char* textura, int TAMcoral, int coralMov);

void UpdateCoral(SDL_Renderer* renderizador, Coral coral);

typedef struct {
	int tamanhoW;
	int tamanhoH;
	int posicaoX;
	int posicaoY;
	const char* textura;
	SDL_Rect estrutura;
	SDL_Texture* texturaCarregada;
} Linha;

Linha SpawnLinha(SDL_Renderer* renderizador, const char* textura, int TAMlinhaH, int linhaMov);

void UpdateLinha(SDL_Renderer* renderizador, Linha linha);

typedef struct {
	int tamanhoW;
	int tamanhoH;
	int posicaoX;
	int posicaoY;
	const char* textura;
	SDL_Rect estrutura;
	SDL_Texture* texturaCarregada;
} Anzol;

Anzol SpawnAnzol(SDL_Renderer* renderizador, const char* textura, Linha linha);

void UpdateAnzol(SDL_Renderer* renderizador, Anzol anzol);

#endif 
