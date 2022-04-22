#include "cola.h"
#include "lista.h"

struct _cola_t{
	nodo_t *fin;
	nodo_t *principio;
	size_t cantidad;
};

cola_t *cola_crear()
{
	cola_t *cola = calloc(1, sizeof(cola_t));
	if(!cola){
		return NULL;
	}
	return cola;
}

cola_t *cola_encolar(cola_t *cola, void *elemento)
{
	return NULL;
}

void *cola_desencolar(cola_t *cola)
{
	return NULL;
}

void *cola_frente(cola_t *cola)
{
	if(!cola || cola_vacia(cola)){
		return NULL;
	}
	return cola->principio->elemento;
}

size_t cola_tamanio(cola_t *cola)
{
	if(!cola){
		return 0;
	}
	return cola->cantidad;
}

bool cola_vacia(cola_t *cola)
{
	if(!cola || cola->cantidad == 0){
		return true;
	}
	return false;
}

void cola_destruir(cola_t *cola)
{
	if(!cola){
		return;
	}
	while(!cola_vacia(cola)){
		cola_desencolar(cola);
	}
	free(cola);
}
