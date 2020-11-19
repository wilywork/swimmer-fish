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

#endif 
