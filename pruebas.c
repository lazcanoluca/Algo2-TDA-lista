#include "src/lista.h"
#include "src/pila.h"
#include "src/cola.h"
#include <stdio.h>
#include <stdlib.h>
#include "pa2m.h"

void creo_una_pila_y_devuelve_una_pila_vacia_con_tope_nulo()
{
	pila_t *pila = pila_crear();

	pa2m_afirmar(pila != NULL, "La pila creada es válida");
	pa2m_afirmar(pila_tamanio(pila) == 0 && pila_vacia(pila), "La pila creada está vacía");
	pa2m_afirmar(pila_tope(pila) == NULL, "La pila creada tiene tope nulo");

	pila_destruir(pila);
}

void apilo_un_elemento_y_se_incrementa_el_tamanio_de_la_pila()
{
	pila_t *pila = pila_crear();
	int elemento1 = 5;
	int elemento2 = 7;

	pa2m_afirmar(pila_apilar(pila, &elemento1) == pila, "Puedo apilar un elemento y se devuelve la pila");
	pa2m_afirmar(pila_tamanio(pila) == 1 && !pila_vacia(pila), "Al apilar un elemento el tamaño de la pila es 1");
	pa2m_afirmar(pila_tope(pila) == &elemento1, "El tope de la pila es el correcto");

	pa2m_afirmar(pila_apilar(pila, &elemento2) == pila, "Puedo apilar un segundo elemento y se devuelve la pila");
	pa2m_afirmar(pila_tamanio(pila) == 2 && !pila_vacia(pila), "Al apilar otro elemento el tamaño de la pila es 2");
	pa2m_afirmar(pila_tope(pila) == &elemento2, "El tope de la pila es el correcto");

	pila_destruir(pila);
}

void puedo_apilar_un_elemento_NULL()
{
	pila_t *pila = pila_crear();

	pa2m_afirmar(pila_apilar(pila, NULL) == pila, "Puedo apilar un elemento NULL");
	pa2m_afirmar(pila_tamanio(pila) == 1 && !pila_vacia(pila), "Al apilar un elemento NULL el tamaño de la pila es 1");
	pa2m_afirmar(pila_tope(pila) == NULL, "El tope de la pila es NULL");

	pila_destruir(pila);
}

void no_se_puede_apilar_en_una_pila_nula()
{
	int elemento = 8;
	pa2m_afirmar(pila_apilar(NULL, &elemento) == NULL, "No puedo apilar en una pila nula");
}

void no_se_puede_desapilar_en_una_pila_nula()
{
	pa2m_afirmar(pila_desapilar(NULL) == NULL, "No puedo desapilar en una pila nula");
}

void desapilo_un_elemento_y_disminuye_el_tamanio_de_la_pila()
{
	pila_t *pila = pila_crear();
	int elemento1 = 5;
	int elemento2 = 7;
	int elemento3 = 10;

	pila_apilar(pila, &elemento1);
	pila_apilar(pila, &elemento2);
	pila_apilar(pila, &elemento3);

	pa2m_afirmar(pila_desapilar(pila) == &elemento3, "Puedo desapilar un elemento y devuelve el elemento desapilado");
	pa2m_afirmar(pila_tamanio(pila) == 2 && !pila_vacia(pila), "Al desapilar un elemento en una pila con 3 elementos, el tamaño de la pila es 2");
	pa2m_afirmar(pila_tope(pila) == &elemento2, "El tope de la pila es el correcto");

	pa2m_afirmar(pila_desapilar(pila) == &elemento2, "Puedo desapilar un segundo elemento y devuelve el elemento desapilado");
	pa2m_afirmar(pila_tamanio(pila) == 1 && !pila_vacia(pila), "Al desapilar un elemento en una pila con 2 elementos, el tamaño de la pila es 1");
	pa2m_afirmar(pila_tope(pila) == &elemento1, "El tope de la pila es el correcto");

	pa2m_afirmar(pila_desapilar(pila) == &elemento1, "Puedo desapilar un tercer elemento y devuelve el elemento desapilado");
	pa2m_afirmar(pila_tamanio(pila) == 0 && pila_vacia(pila), "Al desapilar un tercer elemento en una pila con 1 elemento, el tamaño de la pila es 0");
	pa2m_afirmar(pila_tope(pila) == NULL, "El tope de la pila es el correcto");

	pila_destruir(pila);
}

void creo_una_cola_y_devuelve_una_cola_vacia_con_frente_nulo()
{
	cola_t *cola = cola_crear();

	pa2m_afirmar(cola != NULL, "La cola creada es válida");
	pa2m_afirmar(cola_tamanio(cola) == 0 && cola_vacia(cola), "La cola creada es de tamaño 0");
	pa2m_afirmar(cola_frente(cola) == NULL, "El elemento en el frente de la cola es nulo");

	cola_destruir(cola);
}

int main() {
	pa2m_nuevo_grupo("Pruebas de creación de pila");
  	creo_una_pila_y_devuelve_una_pila_vacia_con_tope_nulo();

  	pa2m_nuevo_grupo("Pruebas de apilar");
	apilo_un_elemento_y_se_incrementa_el_tamanio_de_la_pila();
	puedo_apilar_un_elemento_NULL();
	no_se_puede_apilar_en_una_pila_nula();

	pa2m_nuevo_grupo("Pruebas de desapilar");
	desapilo_un_elemento_y_disminuye_el_tamanio_de_la_pila();
	no_se_puede_desapilar_en_una_pila_nula();

	pa2m_nuevo_grupo("Pruebas de creación de cola");
  	creo_una_cola_y_devuelve_una_cola_vacia_con_frente_nulo();

  	return pa2m_mostrar_reporte();
}
