#pragma once
#include <iostream>
#include <conio.h>
#include <ctime>

#include "raton.h"
#include "ArregloRaton.h"
#include "queso.h"
#include "ArregloQueso.h"
#include "Mapas.h"

using namespace System;
using namespace std;

int espaciado = 7;
ArregloRaton* InicializarDatos_Ratones() {
    raton* mouse1 = new raton();

    mouse1->cambiar_posx(0);
    mouse1->cambiar_posy(4);

    raton* mouse2 = new raton();

    mouse2->cambiar_posx(0);
    mouse2->cambiar_posy(mouse1->retornar_posy() + espaciado);

    raton* mouse3 = new raton();

    mouse3->cambiar_posx(0);
    mouse3->cambiar_posy(mouse2->retornar_posy() + espaciado);

    raton* mouse4 = new raton();

    mouse4->cambiar_posx(0);
    mouse4->cambiar_posy(mouse3->retornar_posy() + espaciado);

    raton* mouse5 = new raton();

    mouse5->cambiar_posx(0);
    mouse5->cambiar_posy(mouse4->retornar_posy() + espaciado);//4 mas abajo de donde termina el raton

    ArregloRaton* Ratones = new ArregloRaton();
    Ratones->agregarRaton(mouse1);
    Ratones->agregarRaton(mouse2);
    Ratones->agregarRaton(mouse3);
    Ratones->agregarRaton(mouse4);
    Ratones->agregarRaton(mouse5);

    return Ratones;
}

ArregloQueso* InicializarDatos_Quesos() {
    queso* queso1 = new queso();
    queso1->cambiar_posy(3);
    queso* queso2 = new queso();
    queso2->cambiar_posy(queso1->retornar_posy() + espaciado);
    queso* queso3 = new queso();
    queso3->cambiar_posy(queso2->retornar_posy() + espaciado);
    queso* queso4 = new queso();
    queso4->cambiar_posy(queso3->retornar_posy() + espaciado);
    queso* queso5 = new queso();
    queso5->cambiar_posy(queso4->retornar_posy() + espaciado);

    ArregloQueso* Quesos = new ArregloQueso();
    Quesos->agregarQueso(queso1);
    Quesos->agregarQueso(queso2);
    Quesos->agregarQueso(queso3);
    Quesos->agregarQueso(queso4);
    Quesos->agregarQueso(queso5);

    return Quesos;

}

int PantallaInicio() {
    Console::CursorVisible = false;
    Console::SetWindowSize(180, 40);
    for (int fila = 0; fila < 40; fila++) {
        for (int columna = 0; columna <180; columna++) {
            Console::SetCursorPosition(columna, fila);
            if (MapaInicio[fila][columna] == 0) Console::ForegroundColor = ConsoleColor::Blue;
            if (MapaInicio[fila][columna] == 1) Console::ForegroundColor = ConsoleColor::White;
            if (MapaInicio[fila][columna] == 2) Console::ForegroundColor = ConsoleColor::Green;
            if (MapaInicio[fila][columna] == 3) Console::ForegroundColor = ConsoleColor::DarkGray;
            if (MapaInicio[fila][columna] == 4) Console::ForegroundColor = ConsoleColor::Black;
            if (MapaInicio[fila][columna] == 5) Console::ForegroundColor = ConsoleColor::Gray;
            if (MapaInicio[fila][columna] == 6) Console::ForegroundColor = ConsoleColor::DarkCyan;
            if (MapaInicio[fila][columna] == 7) Console::ForegroundColor = ConsoleColor::DarkYellow;
            cout << (char)219;
        }
    }
    Console::SetCursorPosition(77, 36);
    Console::ForegroundColor = ConsoleColor::DarkBlue;
    Console::BackgroundColor = ConsoleColor::Green;
    cout << "Pulse cualquier tecla para continuar";
    return 0;
}

bool Game() {

    int Jugadores = PantallaInicio();
    srand(time(NULL));

    Console::CursorVisible = false;
    Console::SetWindowSize(180, 40);

    //Inicializo el arreglo con los ratones
    ArregloRaton* Ratones = new ArregloRaton();
    Ratones = InicializarDatos_Ratones();


    //Inicializo el arreglo con los quesos
    ArregloQueso* Quesos = new ArregloQueso();
    Quesos = InicializarDatos_Quesos();

    //Dibujo los quesos y ratones
    Quesos->DibujarTodos();
    Ratones->DibujarTodos();


    for (;;) {
        if (_kbhit()) {
            char tecla = _getch();
            if (tecla == 's' || tecla == 'S') {
                Ratones->cambiar_estado(true);
            }
            else if (tecla == 'r' || tecla == 'R' || Ratones->nuevo) {
                system("cls");
                Quesos = InicializarDatos_Quesos();
                Quesos->DibujarTodos();
                Ratones = InicializarDatos_Ratones();
                Ratones->DibujarTodos();
            }
        }
        Ratones->MoverTodos(170);
        _sleep(100);
    }

}