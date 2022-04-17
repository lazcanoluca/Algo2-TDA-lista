#include "pila.h"
#include "lista.h"

typedef struct lista pila_t;

pila_t *pila_crear()
{
	pila_t *pila = calloc(1, sizeof(pila_t));
	if(!pila){
		return NULL;
	}
	return pila;
}

pila_t *pila_apilar(pila_t *pila, void *elemento)
{	
	if(!pila){
		return NULL;
	}
	nodo_t *nuevo_nodo = malloc(sizeof(nodo_t));
	if(!nuevo_nodo){
		return NULL;
	}
	pila->nodo_fin->siguiente = nuevo_nodo;
	nuevo_nodo->elemento = elemento;

	return pila;
}

void *pila_desapilar(pila_t *pila)
{
	if(!pila){
		return NULL;
	}
	nodo_t *nodo_aux = malloc(sizeof(nodo_t));
	if(!nodo_aux){
		return NULL;
	}
	nodo_aux = pila->nodo_fin;
	free(nodo_aux);

	return pila;
}

void *pila_tope(pila_t *pila)
{
	if(!pila || pila->cantidad == 0){
		return NULL;
	}
	return pila->nodo_fin->elemento;
}

size_t pila_tamanio(pila_t *pila)
{
	if(!pila){
		return 0;
	}
	return pila->cantidad;
}

bool pila_vacia(pila_t *pila)
{
	if(!pila || pila->cantidad == 0){
		return true;
	}
	return false;
}

void pila_destruir(pila_t *pila)
{
	if(!pila){
		return;
	}
	while(!pila_vacia(pila)){
		pila_desapilar(pila);
	}
        free(pila);
}
