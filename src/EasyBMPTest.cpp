//============================================================================
// Name        : EasyBMPTest.cpp
// Author      : Joel Perez
// Version     :
// Copyright   : Copyright 2018 Joel Perez
// Description : Test application for EasyBMP Library.
//============================================================================

#include <iostream>
#include "EasyBMPTest.h"

using namespace std;

int main() {
	cout << "Easy BMP Test" << endl;

	//crearEjemploTexto();
	crearEjemploTerreno();

	return 0;
}

void crearEjemploTexto() {
	BMP bmpEjemploTexto;
	bmpEjemploTexto.SetSize(1024, 768);
	bmpEjemploTexto.SetBitDepth(24);
	bmpEjemploTexto.WriteToFile("ejemplotexto.bmp");
}

void crearEjemploTerreno() {
	BMP cultivo;
	cultivo.ReadFromFile("cultivo.bmp");

	BMP terreno;
	terreno.ReadFromFile("terreno.bmp");

	BMP ejemploTerreno;
	ejemploTerreno.SetSize(terreno.TellWidth(), terreno.TellHeight());
	ejemploTerreno.SetBitDepth(24);

	//Pego el fondo...
	RangedPixelToPixelCopy(terreno, 0, ejemploTerreno.TellWidth() - 1,
			ejemploTerreno.TellHeight() - 1, 0, ejemploTerreno, 0, 0);

	for (int columna = 0; columna < 4; columna++) {
		for (int fila = 0; fila < 5; fila++) {
			//Pego el cultivo actual...
			RangedPixelToPixelCopyTransparent(cultivo, 0,
					cultivo.TellWidth() - 1, cultivo.TellWidth() - 1, 0,
					ejemploTerreno, 150 + (fila * 150), 150 + (columna * 150),
					*cultivo(0, 49));
		}
	}

	ejemploTerreno.WriteToFile("ejemploterreno.bmp");
}
