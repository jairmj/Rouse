#include "pch.h"
#include "ArregloQueso.h"

ArregloQueso::ArregloQueso() {};
ArregloQueso::~ArregloQueso() {};


void ArregloQueso::agregarQueso(queso* nuevo) { Quesos[cantidad + 1] = *nuevo; cantidad++; };
void ArregloQueso::borrarQueso(int indice) { Quesos[indice].~queso(); }

void ArregloQueso::DibujarTodos() {
	for (int i = 0; i < 5; i++) {
		Quesos[i].Dibujar();
	}
}

void ArregloQueso::BorrarTodos() {
	for (int i = 0; i < 5; i++) {
		Quesos[i].Borrar();
	}
}