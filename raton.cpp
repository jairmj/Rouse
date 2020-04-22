#include "pch.h"
#include "raton.h"
#include <iostream>
using namespace std;
using namespace System;

raton::raton() {};
raton::~raton() {};


void raton::cambiar_posx(int nuevo) { posx = nuevo; };
void raton::cambiar_velocidad(int nuevo) { velocidad = nuevo; };
void raton::cambiar_posy(int nuevo) { posy = nuevo; };

int raton::retornar_posx() { return posx; }
int raton::retornar_posy() { return posy; }
int raton::retornar_Velocidad() { return velocidad; }

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