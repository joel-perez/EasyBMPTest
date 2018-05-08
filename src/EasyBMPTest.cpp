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
	char jugador[] = "Jugador";
	crearEjemploTerreno(jugador);
	return 0;
}

void crearEjemploTerreno(char* Jugador) {
	BMP cultivo;
	cultivo.ReadFromFile("cultivo.bmp");

	BMP terreno;
	terreno.ReadFromFile("terreno.bmp");

	BMP usuario;
	usuario.ReadFromFile("fondoJugador.bmp");

	BMP ejemploTerreno;
	ejemploTerreno.SetSize(usuario.TellWidth(), terreno.TellHeight()+usuario.TellHeight());
	ejemploTerreno.SetBitDepth(24);

	//Pego el fondo del terreno
	RangedPixelToPixelCopy(terreno, 0, ejemploTerreno.TellWidth()-1, ejemploTerreno.TellHeight()-1, 0, ejemploTerreno,0, 0);

	// Pego el fondo azul
	RangedPixelToPixelCopy(usuario, 0, ejemploTerreno.TellWidth()-1, ejemploTerreno.TellHeight()-1, 0, ejemploTerreno,0, terreno.TellHeight());

	//Pega la imagen del cultivo transparente
	for (int fila = 0; fila < 5; fila++) {
		for (int columna = 0; columna < 6; columna++) {
			//Pego el cultivo actual...
			RangedPixelToPixelCopyTransparent(cultivo, 0,
					cultivo.TellWidth(), cultivo.TellHeight(), 0,
					ejemploTerreno,(columna * 140)+80, 30+(fila * 140),
					*cultivo(0, 49));
		}
	}

	//Color blanco en rgba.
	RGBApixel color;
	color.Red = 225;
	color.Green = 225;
	color.Blue = 225;

	//Pega edel jugador en el fondo azul
	PrintString(ejemploTerreno, Jugador , usuario.TellWidth()/3, terreno.TellHeight()+50 , 60, color);

	ejemploTerreno.WriteToFile("ejemploterreno.bmp");
}
