#include "pch.h"
#include "ArregloRaton.h"
#include <ctime>
#include <iostream>
#include <conio.h>

using namespace System;
using namespace std;


ArregloRaton::ArregloRaton() {}
ArregloRaton::~ArregloRaton() {}

void ArregloRaton::cambiar_estado(bool nuevo) { status = nuevo; };
void ArregloRaton::agregarRaton(raton* nuevo) { Ratones[cantidad + 1] = *nuevo; cantidad++; }
void ArregloRaton::borrarRaton(int indice) { Ratones[indice].~raton(); }


int ArregloRaton::MoverTodos(int quesoX) {//Retorna el ganador
	int velocidad;
	srand(time(NULL));
	for (int i = 0; i < cantidad + 1; i++) {
		if ((Ratones[i].retornar_posx()) < quesoX - 21 && status) {//Si est� a la izquierda del queso
			velocidad = rand() % 2 + 1;
			Ratones[i].Mover(velocidad, false); //Hago que se mueva una cantidad aleatoria de espacios
		}
		else if (status) {//Un rat�n ha llegado a la meta
			//Paro la carrera
			status = false;

			//Indico que hay un ganador
			nuevo = true;

			//Borro los ratones que no ganaron
			for (int m = 0; m < cantidad + 1; m++) {
				if (m != i) {
					Ratones[m].Borrar();
				}

			}
			System::Console::SetCursorPosition(78, 38);
			std::cout << "Pulse 'r' para reiniciar";

			//Retorno la rata que ha ganado
			return i;			
		}
	}
}

void ArregloRaton::DibujarTodos() {
	for (int i = 0; i < 5; i++) {
		if (Ratones[i].retornar_color() == 0) { Console::ForegroundColor = ConsoleColor::Yellow; }
		if (Ratones[i].retornar_color() == 1) { Console::ForegroundColor = ConsoleColor::DarkRed; }
		if (Ratones[i].retornar_color() == 2) { Console::ForegroundColor = ConsoleColor::Cyan; }
		if (Ratones[i].retornar_color() == 3) { Console::ForegroundColor = ConsoleColor::Blue; }
		if (Ratones[i].retornar_color() == 4) { Console::ForegroundColor = ConsoleColor::Green; }

		Ratones[i].Dibujar();
	}
}


void ArregloRaton::BorrarTodos() {
	for (int i = 0; i < 5; i++) {
		Ratones[i].Borrar();
	}
}

raton* ArregloRaton::RetornarArreglo() {
	return Ratones;
}