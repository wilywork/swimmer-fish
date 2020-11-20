
#ifndef PEIXE_H
#define PEIXE_H

typedef struct {
	int altura;
	const char* textura;
	SDL_Rect estrutura;
	SDL_Texture* texturaCarregada;
} Peixe;

Peixe SpawnPeixe(SDL_Renderer* renderizador, const char* textura, int altura);

void UpdatePeixe(SDL_Renderer* renderizador, Peixe peixe);

#endif // PEIXE_H
