#pragma once
#include "queso.h"
class ArregloQueso
{
private:
	queso* Quesos = new queso[5];
	int cantidad = -1;

public:
	ArregloQueso();
	~ArregloQueso();


	void agregarQueso(queso* nuevo);
	void borrarQueso(int indice);
	queso* RetornarArreglo();

	void DibujarTodos();
	void BorrarTodos();


};
