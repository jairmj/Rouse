#include "pch.h"
#include "raton.h"
#include <iostream>

using namespace std;
using namespace System;

raton::raton() {};
raton::~raton() {};


void raton::cambiar_posx(int nuevo) { posx = nuevo; };
void raton::cambiar_color(int nuevo) { color = nuevo; };
void raton::cambiar_posy(int nuevo) { posy = nuevo; };

int raton::retornar_posx() { return posx; }
int raton::retornar_posy() { return posy; }
int raton::retornar_color() { return color; }
int raton::retornar_cantidad() { return cantidad; }

void raton::Dibujar() {
	Console::SetCursorPosition(posx, posy);
	cout << " _, .---.__c--.";
	Console::SetCursorPosition(posx, posy + 1);
	cout << "(__( )_._( )_`_>";
	Console::SetCursorPosition(posx, posy + 2);
	cout << "     `~~'  `~'";
	

}
void raton::Borrar() {
	Console::SetCursorPosition(posx, posy);
	cout << "               ";
	Console::SetCursorPosition(posx, posy + 1);
	cout << "                ";
	Console::SetCursorPosition(posx, posy + 2);
	cout << "              ";

}
void raton::Mover(int dx, bool status) {
	Borrar();
	if ((posx + dx + 60 >= 164 || posx + dx <= 78) && status) {
		dx *= -1;
	}
	posx += dx;
	Dibujar();
}

void raton::agregar_velocidad(int nuevo) {
	int *copiaRangoVelocidades = new int[cantidad + 1];

	//Copio lo que había en el antiguo en el nuevo
	for (int i = 0; i < cantidad; i++) {
		copiaRangoVelocidades[i] = RangoVelocidades[i];
	}
	//Añado el nuevo en la última posición
	copiaRangoVelocidades[cantidad] = nuevo;
	cantidad++;

	//Copio el arreglo en el original
	RangoVelocidades = copiaRangoVelocidades;


}

int raton::retornar_velocidad(int indice) { return RangoVelocidades[indice]; }
int* raton::retornar_arreglo() { return RangoVelocidades; }