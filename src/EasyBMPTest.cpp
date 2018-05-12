#include "EasyBMPTest.h"

Imagen::Imagen(){

	cultivo.ReadFromFile("cultivo.bmp");
	fondoTerreno.ReadFromFile("terreno.bmp");
	fondoUsuario.ReadFromFile("fondoJugador.bmp");
	imagenDelTerreno.SetSize(fondoTerreno.TellWidth(), fondoTerreno.TellHeight()+fondoUsuario.TellHeight());
	imagenDelTerreno.SetBitDepth(24);

	color.Red =255;
	color.Green=255;
	color.Blue =225;
}

void Imagen::rescalarImagenes(){
	Rescale(cultivo, 'f', (imagenDelTerreno.TellWidth()-(2*MARGEN_COLUMNA))/ COLUMNA);
}

void Imagen::pegarFondos(){
	RangedPixelToPixelCopy(fondoTerreno, 0, fondoTerreno.TellWidth(), fondoTerreno.TellHeight(), 0, imagenDelTerreno,0, 0);
	RangedPixelToPixelCopy(fondoUsuario, 0, fondoTerreno.TellWidth(), fondoTerreno.TellHeight()-1, 0, imagenDelTerreno,0, fondoTerreno.TellHeight());
}

void Imagen::obtenerImagenDelTerreno(char* jugador){
	this->rescalarImagenes();
	this->pegarFondos();

	for (int fila = 0; fila < FILA; fila++){
		for (int columna = 0; columna < COLUMNA; columna++){
			RangedPixelToPixelCopy(cultivo,0,cultivo.TellWidth(),cultivo.TellHeight(),0,imagenDelTerreno,(columna*cultivo.TellWidth())+MARGEN_COLUMNA,(fila*cultivo.TellHeight())+MARGEN_FILA);
		}
	}

	PrintString(imagenDelTerreno, jugador , fondoUsuario.TellWidth()/3, fondoTerreno.TellHeight()+50 , 60, color);

	imagenDelTerreno.WriteToFile("ejemploterreno.bmp");
}
