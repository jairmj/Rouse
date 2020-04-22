
#include "pch.h"
#include "queso.h"
#include <iostream>
using namespace std;
using namespace System;


queso::queso() {};
queso::~queso() {};


void queso::cambiar_posy(int nuevo) { posy = nuevo; };

int queso::retornar_posx() { return posx; }
int queso::retornar_posy() { return posy; }

void queso::Dibujar() {
	Console::SetCursorPosition(posx, posy);
	cout << " |'-------'|";
	Console::SetCursorPosition(posx, posy + 1);
	cout << " |O   O   o|";
	Console::SetCursorPosition(posx, posy + 2);
	cout << " | o O . o |";
	Console::SetCursorPosition(posx, posy + 3);
	cout << " `---------'";
}

void queso::Borrar() {
	for (int i = 0; i < 4; i++) {
		Console::SetCursorPosition(posx, posy + i);
		cout << "            ";
	}
}