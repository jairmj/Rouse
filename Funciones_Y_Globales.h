#pragma once
#include <iostream>
#include <conio.h>
#include <ctime>
#include <string.h>

#include "raton.h"
#include "ArregloRaton.h"
#include "queso.h"
#include "ArregloQueso.h"
#include "Mapas.h"

using namespace System;
using namespace std;

int espaciado = 7;


int PantallaInicio() {
    for (int fila = 0; fila < 40; fila++) {
        for (int columna = 0; columna < 180; columna++) {
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
    for (;;) {
        if (_kbhit()) {
            int jugadores = PantallaSeleccion();
            return jugadores;
        }

    }
}

int PantallaSeleccion() {
    //Borra el nombre del juego y el mensaje
    Console::SetCursorPosition(0, 0);
    Console::WindowHeight = 40;
    Console::WindowWidth = 180;
    for (int fila = 22; fila < 34; fila++) {//Solo modifico donde está el nombre
        for (int columna = 62; columna < 127; columna++) {
            Console::SetCursorPosition(columna, fila);
            if (MapaInicio[fila][columna] == 0) Console::ForegroundColor = ConsoleColor::Green;
            if (MapaInicio[fila][columna] == 2) Console::ForegroundColor = ConsoleColor::Green;
            if (MapaInicio[fila][columna] == 7) Console::ForegroundColor = ConsoleColor::Green;
            cout << (char)219;
        }
    }
    Console::SetCursorPosition(63, 36);
    Console::ForegroundColor = ConsoleColor::Black;
    cout << "Use las flechas para elegir y enter para seleccionar";

    Console::SetCursorPosition(83, 22);
    Console::ForegroundColor = ConsoleColor::Black;
    cout << (char)219 << " 1 Jugador";
    Console::SetCursorPosition(83, 24);
    cout << " " << " 2 Jugadores";

    int Jugadores;
    for (;;) {
        if (_kbhit) {
            char tecla = _getch();
            if (tecla == 72) {
                Jugadores = 1;

                Console::SetCursorPosition(83, 22);
                Console::ForegroundColor = ConsoleColor::Black;
                cout << (char)219;

                Console::SetCursorPosition(83, 24);
                Console::ForegroundColor = ConsoleColor::Green;
                cout << (char)219;
            }
            if (tecla == 80) {
                Jugadores = 2;

                Console::SetCursorPosition(83, 22);
                Console::ForegroundColor = ConsoleColor::Green;
                cout << (char)219;

                Console::SetCursorPosition(83, 24);
                Console::ForegroundColor = ConsoleColor::Black;
                cout << (char)219;
            }
            if (tecla == 13) {
                return Jugadores;
            }
        }
    
    }



    return 0;
}

ArregloRaton* InicializarDatos_Ratones() {

    //Creo ratones
    raton* mouse1 = new raton();
    raton* mouse2 = new raton();
    raton* mouse3 = new raton();
    raton* mouse4 = new raton();
    raton* mouse5 = new raton();

    //Establezco sus velocidades
    for (int i =0; i < 6; i++) {
        mouse1->agregar_velocidad(i);
    }
    for (int i = 2; i <= 4; i++) {
        mouse2->agregar_velocidad(i);
    }
    for (int i = 1; i <= 3; i++) {
        mouse3->agregar_velocidad(i);
    }
    for (int i = 1; i <= 4; i++) {
        mouse4->agregar_velocidad(i);
    }
    for (int i = -1; i <= 6; i++) {
        mouse5->agregar_velocidad(i);
    }
         
    //Los agrego a un arreglo
    ArregloRaton* Ratones = new ArregloRaton();
    Ratones->agregarRaton(mouse1);
    Ratones->agregarRaton(mouse2);
    Ratones->agregarRaton(mouse3);
    Ratones->agregarRaton(mouse4);
    Ratones->agregarRaton(mouse5);

    //Establezco posiciones y colores
    for (int i = 0; i < 5; i++) {
        Ratones->RetornarArreglo()[i].cambiar_posx(0);
        if(i==0) Ratones->RetornarArreglo()[i].cambiar_posy(4);
        else {
            Ratones->RetornarArreglo()[i].cambiar_posy(Ratones->RetornarArreglo()[i - 1].retornar_posy() + espaciado);
        }
        Ratones->RetornarArreglo()[i].cambiar_color(i);
    }
    return Ratones;
}

ArregloQueso* InicializarDatos_Quesos() {
    queso* queso1 = new queso();
    queso* queso2 = new queso();
    queso* queso3 = new queso();
    queso* queso4 = new queso();
    queso* queso5 = new queso();

    ArregloQueso* Quesos = new ArregloQueso();
    Quesos->agregarQueso(queso1);
    Quesos->agregarQueso(queso2);
    Quesos->agregarQueso(queso3);
    Quesos->agregarQueso(queso4);
    Quesos->agregarQueso(queso5);

    for (int i = 0; i < 5; i++) {
        if (i == 0) Quesos->RetornarArreglo()[i].cambiar_posy(3);
        else {
            Quesos->RetornarArreglo()[i].cambiar_posy(Quesos->RetornarArreglo()[i - 1].retornar_posy() + espaciado);
        }
    }

    return Quesos;

}

int SeleccionRaton(ArregloRaton* Ratones) {
    Console::BackgroundColor = ConsoleColor::Black;
    system("cls");
    //Dando posiciones a los ratones para mostrarlos:
    for (int i = 0; i < 5; i++) {
        Ratones->RetornarArreglo()[i].cambiar_posx(20+30*(i));
        Ratones->RetornarArreglo()[i].cambiar_posy(1);
    }

    Ratones->DibujarTodos();

    //Escribo Nombres y Características:
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(1, 8);
    cout << "Velocidad:";
    string Nombres[5] = { "RATATOUI", "BOLT", "MISHU", "VELOCITO", "C0CK" };
    int PosicionesNombres[5] = { 24, 56, 87, 114, 147 };

    for (int i = 0; i < 5; i++) {
        //Nombres
        Console::SetCursorPosition(PosicionesNombres[i], 0);
        cout << Nombres[i];
        //Características
        Console::SetCursorPosition(30 * (i+1) - 5, 8);
        cout << "["<< Ratones->RetornarArreglo()[i].retornar_arreglo()[0] <<"-"<< Ratones->RetornarArreglo()[i].retornar_arreglo()[Ratones->RetornarArreglo()[i].retornar_cantidad() - 1] <<"]";
    }

    for (;;) {

    }

    return 1;
}




bool Game() {
    //Consigo la cantidad de jugadores
    int Jugadores = PantallaInicio();
    srand(time(NULL));

    //Inicializo los arreglos con ratones y quesos
    ArregloRaton* Ratones = InicializarDatos_Ratones();
    ArregloQueso* Quesos = InicializarDatos_Quesos();

    //hago que el jugador seleccione un raton
    int Seleccion = SeleccionRaton(Ratones);


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