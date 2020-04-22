
#pragma once
class raton
{
private:
	int posx, posy, velocidad;

public:
	raton();
	~raton();

	void cambiar_posx(int nuevo);
	void cambiar_velocidad(int nuevo);
	void cambiar_posy(int nuevo);

	int retornar_posx();
	int retornar_posy();
	int retornar_Velocidad();

	void Dibujar();
	void Borrar();
	void Mover(int dx, bool status);


};
