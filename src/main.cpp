#include <iostream>
#include "EasyBMPTest.h"

using namespace std;

// FILA = COLUMNA - 3 Para que se visualice bien (hasta el momento)

int main() {
	cout << "Easy BMP Test" << endl;
	cout << "Ejemplo con TDA-s"<<endl;

	char jugador[] = "Jugador";

	Imagen imagen;

	imagen.obtenerImagenDelTerreno(jugador);

	return 0;
}
