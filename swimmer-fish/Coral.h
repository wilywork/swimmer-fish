#ifndef CORAL_H
#define CORAL_H

typedef struct {
	int tamanhoW;
	int tamanhoH;
	int posicaoX;
	int posicaoY;
	const char* textura;
	SDL_Rect estrutura;
	SDL_Texture* texturaCarregada;
} Coral;

Coral SpawnCoral(SDL_Renderer* renderizador, const char* textura, int tamanho, int altura);

#endif 
