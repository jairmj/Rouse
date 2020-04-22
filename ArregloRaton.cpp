#include "pch.h"
#include "ArregloRaton.h"
#include <ctime>
#include <iostream>
#include <conio.h>

ArregloRaton::ArregloRaton() {}
ArregloRaton::~ArregloRaton() {}

void ArregloRaton::cambiar_estado(bool nuevo) { status = nuevo; };
void ArregloRaton::agregarRaton(raton* nuevo) { Ratones[cantidad + 1] = *nuevo; cantidad++; }
void ArregloRaton::borrarRaton(int indice) { Ratones[indice].~raton(); }


void ArregloRaton::MoverTodos(int quesoX) {
	int velocidad;
	srand(time(NULL));
	for (int i = 0; i < cantidad + 1; i++) {
		if ((Ratones[i].retornar_posx()) < quesoX - 21 && status) {//Si está a la izquierda del queso
			velocidad = rand() % 2 + 1;
			Ratones[i].Mover(velocidad, false); //Hago que se mueva una cantidad aleatoria de espacios
		}
		else if (status) {//Un ratón ha llegado a la meta
			status = false; //Paro la carrera
			for (int m = 0; m < cantidad + 1; m++) {//Borro los ratones que no ganaron
				if (m != i) {
					Ratones[m].Borrar();
				}
			}
			System::Console::SetCursorPosition(78, 38);
			std::cout << "Pulse 'r' para reiniciar";
			for (;;) {//Baile de celebración del ganador
				if (_kbhit()) { nuevo = true; break; }
				int aleatorio = rand() % 3 + 1;
				if (aleatorio == 1) { System::Console::ForegroundColor = System::ConsoleColor::Cyan; }
				else if (aleatorio == 2) { System::Console::ForegroundColor = System::ConsoleColor::Green; }
				else if (aleatorio == 3) { System::Console::ForegroundColor = System::ConsoleColor::DarkMagenta; }
				System::Console::SetCursorPosition(70, Ratones[i].retornar_posy() + 1);
				std::cout << "WINNER!";

				int aleatorio1 = rand() % 3 + 1;
				if (aleatorio1 == 1) { System::Console::ForegroundColor = System::ConsoleColor::Cyan; }
				else if (aleatorio1 == 2) { System::Console::ForegroundColor = System::ConsoleColor::Green; }
				else if (aleatorio1 == 3) { System::Console::ForegroundColor = System::ConsoleColor::DarkMagenta; }

				int aleatorio2 = rand() % 1;
				if (aleatorio == 1) { Ratones[i].Mover(1, true); }
				else if (aleatorio == 2) { Ratones[i].Mover(-1, true); }
				_sleep(100);
			}
		}
	}
}

void ArregloRaton::DibujarTodos() {
	for (int i = 0; i < 5; i++) {
		Ratones[i].Dibujar();
	}
}

void ArregloRaton::BorrarTodos() {
	for (int i = 0; i < 5; i++) {
		Ratones[i].Borrar();
	}
}