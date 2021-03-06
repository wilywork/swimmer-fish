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

Comida SpawnComida(SDL_Renderer* renderizador, const char* textura);

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

Coral SpawnCoral(SDL_Renderer* renderizador, const char* textura, int TAMcoral);

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

Linha SpawnLinha(SDL_Renderer* renderizador, const char* textura);

void UpdateLinha(SDL_Renderer* renderizador, Linha linha);


#endif 
