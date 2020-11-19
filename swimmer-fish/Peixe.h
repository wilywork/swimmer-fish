
#ifndef PEIXE_H
#define PEIXE_H

typedef struct {
	int tamanho;
	int altura;
	const char* textura;
	SDL_Rect estrutura;
} Peixe;

Peixe SpawnPeixe(SDL_Renderer* renderizador, const char* textura, int tamanho, int altura);

#endif // PEIXE_H
