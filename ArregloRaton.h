#pragma once
#include "raton.h"
class ArregloRaton
{
private:
	raton* Ratones = new raton[5];
	int cantidad = -1;
	bool status = false;//Estado de la carrera, por defecto no funciona
	
public:
	bool nuevo = false;//Indicia si hay un ganador
	ArregloRaton();
	~ArregloRaton();

	void cambiar_estado(bool nuevo);
	void agregarRaton(raton* nuevo);
	void borrarRaton(int indice);
	void MoverTodos(int quesoX);
	void DibujarTodos();
	void BorrarTodos();
	raton* RetornarArreglo();
};
