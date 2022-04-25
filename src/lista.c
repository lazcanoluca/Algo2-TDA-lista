#include "lista.h"
#include <stddef.h>
#include <stdlib.h>

nodo_t *nodo_en_posicion(lista_t *lista, size_t posicion)
{
	if (!lista || lista_vacia(lista)) return NULL;

	lista_iterador_t *iterador = lista_iterador_crear(lista);
	if (iterador == NULL) return NULL;

	if (posicion == 0) return iterador->corriente;

	for (int i = 0; i < posicion; i++) {
		lista_iterador_avanzar(iterador);
	}

	return iterador->corriente;
}

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

	if(lista_vacia(lista)){
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
	if(!lista){
		return NULL;
	}
	if(posicion >= lista_tamanio(lista) || lista_vacia(lista)){ //insertar al final
		return lista_insertar(lista, elemento);
	}

	nodo_t *nuevo_nodo = malloc(sizeof(struct nodo));
	if(!nuevo_nodo){
		return NULL;
	}

	nuevo_nodo->elemento = elemento;

	if(posicion == 0){ //insertar al principio
		nuevo_nodo->siguiente = lista->nodo_inicio;
		lista->nodo_inicio = nuevo_nodo;
		if(lista_vacia(lista)){
			lista->nodo_fin = nuevo_nodo;
		}			
		lista->cantidad++;
		return lista;
	}

	lista_iterador_t *iterador = lista_iterador_crear(lista);
	if(!iterador){
		return NULL;
	}

	int i = 0;
	while(i < posicion-1 /*&& lista_iterador_tiene_siguiente(iterador)*/){ //insertar en el medio
		// if(!lista_iterador_avanzar(iterador)){
		// 	return NULL;
		// }
		lista_iterador_avanzar(iterador);
		i++;
	}
	nuevo_nodo->siguiente = iterador->corriente->siguiente;
	iterador->corriente->siguiente = nuevo_nodo;
	lista->cantidad++;

	// lista_iterador_destruir(iterador);

	return lista;
}

void *lista_quitar(lista_t *lista)
{
	if (!lista || lista_vacia(lista)) return NULL;

	nodo_t *aux = lista->nodo_fin;
	void *elemento = aux->elemento;

	if (lista_tamanio(lista) == 1) {
		lista->nodo_fin = NULL;
		lista->nodo_inicio = NULL;

	} else {
		nodo_t *penultimo_nodo = nodo_en_posicion(lista, lista_tamanio(lista)-2);

		lista->nodo_fin = penultimo_nodo;
		penultimo_nodo->siguiente = NULL;
	}

	lista->cantidad--;
	
	return (elemento != NULL) ? elemento : NULL;
}

// void *lista_quitar(lista_t *lista)
// {
// 	if(!lista || lista_vacia(lista)){
// 		return NULL;
// 	}

// 	void *elemento_a_quitar = lista->nodo_fin->elemento;

// 	if(lista_tamanio(lista) == 1){
// 		free(lista->nodo_fin);
// 		lista->cantidad--;
// 		return elemento_a_quitar;
// 	}

// 	// lista_iterador_t *iterador = lista_iterador_crear(lista);
// 	// if(!iterador){
// 	// 	return NULL;
// 	// }

// 	// while(iterador->corriente->siguiente != lista->nodo_fin && lista_iterador_tiene_siguiente(iterador)){
// 	// 	if(!lista_iterador_avanzar(iterador)){
// 	// 		lista_iterador_destruir(iterador);
// 	// 		return NULL;
// 	// 	}
// 	// }
// 	nodo_t *penultimo = nodo_en_posicion(lista, lista_tamanio(lista)-2);
// 	lista->nodo_fin = penultimo;
// 	penultimo->siguiente = NULL;
// 	// free(lista->nodo_fin);
// 	// lista->nodo_fin = iterador->corriente;
// 	// iterador->corriente->siguiente = NULL;
// 	lista->cantidad--;

// 	// lista_iterador_destruir(iterador);

// 	return elemento_a_quitar;
// }

void *lista_quitar_de_posicion(lista_t *lista, size_t posicion)
{
	if(!lista || lista_vacia(lista)){
		return NULL;
	}
	if(posicion >= lista_tamanio(lista)){
		return lista_quitar(lista);
	}

	if(posicion == 0){
		void *elemento = lista->nodo_inicio->elemento;
		lista->nodo_inicio = lista->nodo_inicio->siguiente;
		if (lista_tamanio(lista) == 1) lista->nodo_fin = NULL;
		// free(lista->nodo_inicio);
		lista->cantidad--;
		return elemento;
	}

	lista_iterador_t *iterador = lista_iterador_crear(lista);
	if(!iterador){
		return NULL;
	}

	int i = 0;
	while(i < posicion-1 && lista_iterador_tiene_siguiente(iterador)){
		if(!lista_iterador_avanzar(iterador)){
			lista_iterador_destruir(iterador);
			return NULL;
		}
		i++;
	}

	if (posicion >= lista->cantidad) {
		lista->nodo_fin = iterador->corriente;
		lista->nodo_fin->siguiente = NULL;
	}
	
	void *elemento = iterador->corriente->siguiente->elemento;
	nodo_t *aux = iterador->corriente->siguiente;
	// ¿por qué no usar aux en lugar de iterador->corriente->siguiente?
	iterador->corriente->siguiente = iterador->corriente->siguiente->siguiente;
	free(aux);

	lista->cantidad--;

	lista_iterador_destruir(iterador);

	return elemento;
}

void *lista_elemento_en_posicion(lista_t *lista, size_t posicion)
{
	if(!lista || lista_vacia(lista) || posicion >= lista_tamanio(lista)){
		return NULL;
	}
	if(posicion == 0){
		return lista->nodo_inicio->elemento;
	}
	else if(posicion == lista_tamanio(lista)-1){
		return lista->nodo_fin->elemento;
	}
	else{
		lista_iterador_t *iterador = lista_iterador_crear(lista);
		if(!iterador){
			return NULL;
		}
		int i = 0;
		while(i < posicion){
			lista_iterador_avanzar(iterador);
			i++;
		}
		return lista_iterador_elemento_actual(iterador);
	}
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
	if(!lista){
		return;
	}

	while(!lista_vacia(lista)){

		lista_quitar(lista);
	}
}

lista_iterador_t *lista_iterador_crear(lista_t *lista)
{
	lista_iterador_t *iterador = malloc(sizeof(struct lista_iterador));
	if(!iterador){
		return NULL;
	}
	iterador->corriente = lista->nodo_inicio;
	iterador->lista = lista;

	return iterador;
}

bool lista_iterador_tiene_siguiente(lista_iterador_t *iterador)
{
	if(iterador->corriente->siguiente != NULL){
		return true;
	}
	return false;
}

bool lista_iterador_avanzar(lista_iterador_t *iterador)
{
	if(!iterador){
		return false;
	}
	if(!lista_iterador_tiene_siguiente(iterador)){
		iterador->corriente = NULL;
		return false;
	}
	iterador->corriente = iterador->corriente->siguiente;
	return true;
}

void *lista_iterador_elemento_actual(lista_iterador_t *iterador)
{
	if(!iterador || !iterador->corriente){
		return NULL;
	}
	return iterador->corriente->elemento;
}

void lista_iterador_destruir(lista_iterador_t *iterador)
{
	if(!iterador){
		return;
	}
	free(iterador);
}

size_t lista_con_cada_elemento(lista_t *lista, bool (*funcion)(void *, void *), void *contexto)
{
	return 0;
}
