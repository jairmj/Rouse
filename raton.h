#pragma once
class raton
{
private:
	int posx, posy, color;
	/*
							Colores:
-------------------------------------------------------------------------------
		0: Amarillo
		1: Rojo
		2: Cyan
		3: Azul
		4: Verde
	*/

	public:
		raton();
		~raton();
	
		void cambiar_posx(int nuevo);
		void cambiar_color(int nuevo);
		void cambiar_posy(int nuevo);

		int retornar_posx();
		int retornar_posy();
		int retornar_color();

		void Dibujar();
		void Borrar();
		void Mover(int dx, bool status);


};

