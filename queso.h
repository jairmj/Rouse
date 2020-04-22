#pragma once
class queso
{
	int posx = 164;
	int posy;

public:
	queso();
	~queso();

	void cambiar_posy(int nuevo);

	int retornar_posx();
	int retornar_posy();

	void Dibujar();
	void Borrar();
};
