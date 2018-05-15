#include <iostream>
#include <string>

#include "EasyBMPTest.h"

using namespace std;

// FILA = COLUMNA - 3 Para que se visualice bien (hasta el momento)

int main() {
	cout << "Easy BMP Test" << endl;
	cout << "Ejemplo con TDA-s"<<endl;

	string jugador = "Jugador";
	int cantidadAlmacenada= 12;
	int cantidadMaximaEnElAlmacen = 23;
	int cantidadTanque =23;
	int cantidadTanqueMax = 50;

	Imagen imagen;

	imagen.obtenerImagenDelTerreno(jugador, cantidadAlmacenada, cantidadMaximaEnElAlmacen, cantidadTanque, cantidadTanqueMax);


	return 0;
}
