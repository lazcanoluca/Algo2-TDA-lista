#include "lista.h"
#include <stddef.h>
#include <stdlib.h>

lista_t *lista_crear()
{
	lista_t *lista = calloc(1, sizeof(lista_t));
	if(!lista){
		return NULL;
	}
	return lista;
}

lista_t *lista_insertar(lista_t *lista, void *elemento)
{
	if(!lista){
		return NULL;
	}
	nodo_t *nuevo_nodo = calloc(1, sizeof(nodo_t));
	if(!nuevo_nodo){
		return NULL;
	}
	nuevo_nodo->elemento = elemento;
	nuevo_nodo->siguiente = NULL;

	if(lista->cantidad == 0){
		lista->nodo_inicio = nuevo_nodo;
	}
	else{
		lista->nodo_fin->siguiente = nuevo_nodo;
	}
	lista->nodo_fin = nuevo_nodo;
	lista->cantidad++;

	return lista;
}

lista_t *lista_insertar_en_posicion(lista_t *lista, void *elemento, size_t posicion)
{
	return NULL;
}

void *lista_quitar(lista_t *lista)
{
	if(!lista || lista_vacia(lista)){
		return NULL;
	}
	if(lista->cantidad == 1){
		free(lista->nodo_fin);
		lista->nodo_inicio = NULL;
        	lista->nodo_fin = NULL;
	}
	nodo_t *nodo_aux = calloc(1, sizeof(nodo_t));
	if(!nodo_aux){
		return NULL;
	}
	nodo_aux = lista->nodo_fin;
	free(nodo_aux);
	lista->cantidad--;

	return lista->nodo_fin->elemento;
}

void *lista_quitar_de_posicion(lista_t *lista, size_t posicion)
{
	return NULL;
}

void *lista_elemento_en_posicion(lista_t *lista, size_t posicion)
{
	return NULL;
}

void *lista_buscar_elemento(lista_t *lista, int (*comparador)(void *, void *), void *contexto)
{
	return NULL;
}

void *lista_primero(lista_t *lista)
{
	if(!lista || lista_vacia(lista)){
		return NULL;
	}

	return lista->nodo_inicio->elemento;
}

void *lista_ultimo(lista_t *lista)
{
	if(!lista || lista_vacia(lista)){
		return NULL;
	}

	return lista->nodo_fin->elemento;
}

bool lista_vacia(lista_t *lista)
{
	if(!lista || lista->cantidad == 0){
		return true;
	}
	return false;
}

size_t lista_tamanio(lista_t *lista)
{
	if(!lista){
		return 0;
	}
	return lista->cantidad;
}

void lista_destruir(lista_t *lista)
{
	if(!lista){
		return;
	}
	free(lista);
}

void lista_destruir_todo(lista_t *lista, void (*funcion)(void *))
{

}

lista_iterador_t *lista_iterador_crear(lista_t *lista)
{
	return NULL;
}

bool lista_iterador_tiene_siguiente(lista_iterador_t *iterador)
{
	return false;
}

bool lista_iterador_avanzar(lista_iterador_t *iterador)
{
	return false;
}

void *lista_iterador_elemento_actual(lista_iterador_t *iterador)
{
	return NULL;
}

void lista_iterador_destruir(lista_iterador_t *iterador)
{

}

size_t lista_con_cada_elemento(lista_t *lista, bool (*funcion)(void *, void *), void *contexto)
{
	return 0;
}
