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

// FILA = COLUMNA - 3 Para que se visualice bien (hasta el momento)
const int FILA = 9;
const int COLUMNA = 12;
const int MARGEN_COLUMNA = 80;
const int MARGEN_FILA =30;


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

	//Voy a redimensionar la imagen de los cultivos segun la cantidad de filas y columnas
	Rescale(cultivo, 'f', (ejemploTerreno.TellWidth()-(2*MARGEN_COLUMNA))/ COLUMNA);

	//Redimensionar el alto del terreno
	Rescale(terreno, 'H', (MARGEN_FILA*2)+(FILA*cultivo.TellHeight()));

	//Redimensionar el terreno del fondo. Aun no editado bien.
	//Rescale(ejemploTerreno, 'H', terreno.TellHeight()+usuario.TellHeight());
	//Rescale(ejemploTerreno, 'W', terreno.TellWidth());

	//Pego el fondo del terreno
	RangedPixelToPixelCopy(terreno, 0, terreno.TellWidth(), terreno.TellHeight(), 0, ejemploTerreno,0, 0);

	// Pego el fondo azul
	RangedPixelToPixelCopy(usuario, 0, terreno.TellWidth(), terreno.TellHeight()-1, 0, ejemploTerreno,0, terreno.TellHeight());

	//Pega la imagen del cultivo no transparente
	for (int fila = 0; fila < FILA; fila++){
		for (int columna = 0; columna < COLUMNA; columna++){
			RangedPixelToPixelCopy(cultivo,0,cultivo.TellWidth(),cultivo.TellHeight(),0,
											  ejemploTerreno,(columna*cultivo.TellWidth())+MARGEN_COLUMNA,(fila*cultivo.TellHeight())+MARGEN_FILA);
		}
	}

	RGBApixel color;
	//Color blanco en rgba.
	color.Red = 225;
	color.Green = 225;
	color.Blue = 225;

	//Pega nombre jugador en el fondo azul
	PrintString(ejemploTerreno, Jugador , usuario.TellWidth()/3, terreno.TellHeight()+50 , 60, color);

	ejemploTerreno.WriteToFile("ejemploterreno.bmp");
}
