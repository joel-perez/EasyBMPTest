#include "EasyBMPTest.h"
#include <iostream>
#include<string>
#include <sstream>

Imagen::Imagen(){

	//cultivo.ReadFromFile("cultivo.bmp");
	cultivo.ReadFromFile("trigo.bmp");
	fondoTerreno.ReadFromFile("terreno.bmp");
	fondoUsuario.ReadFromFile("fondoJugador.bmp");
	imagenDelTerreno.SetSize(fondoTerreno.TellWidth(), fondoTerreno.TellHeight()+fondoUsuario.TellHeight());
	imagenDelTerreno.SetBitDepth(24);

	color.Red = 225;
	color.Green = 225;
	color.Blue = 225;
}

void Imagen::rescalarImagenes(){
	Rescale(cultivo, 'f', (imagenDelTerreno.TellWidth()-(2*MARGEN_COLUMNA))/ COLUMNA);
}

void Imagen::pegarFondos(){
	RangedPixelToPixelCopy(fondoTerreno, 0, fondoTerreno.TellWidth(), fondoTerreno.TellHeight(), 0, imagenDelTerreno,0, 0);
	RangedPixelToPixelCopy(fondoUsuario, 0, fondoTerreno.TellWidth(), fondoTerreno.TellHeight()-1, 0, imagenDelTerreno,0, fondoTerreno.TellHeight());
}
void Imagen::pegarEstadoDelCultivo(){
	int fila = 1;
	int columna =1;

	for (fila=0; fila<FILA;fila++){
		for (columna = 0; columna<COLUMNA; columna++){
			PrintLetter(cultivo, 'D', cultivo.TellWidth()/2, (cultivo.TellHeight()/2)+17, 12, color);
			RangedPixelToPixelCopyTransparent(cultivo, 0, cultivo.TellWidth(), cultivo.TellHeight(), 0, imagenDelTerreno, (columna * cultivo.TellWidth()) + MARGEN_COLUMNA, (fila * cultivo.TellHeight()) + MARGEN_FILA, *cultivo(0, 49));
		}

	}
}
void Imagen::obtenerImagenDelTerreno(std::string jugador, int cantidadAlmacenada, int cantidadMaximaEnElAlmacen, int cantidadTanque, int cantidadTanqueMax){
	this->rescalarImagenes();
	this->pegarFondos();

	this->pegarEstadoDelCultivo();


	this->pegarDatos(cantidadAlmacenada, cantidadMaximaEnElAlmacen,cantidadTanque, cantidadTanqueMax,jugador);

	imagenDelTerreno.WriteToFile("ejemploterreno.bmp");
}
void Imagen::pegarDatos(int cantidadAlmacenada, int cantidadMaximaEnElAlmacen,int cantidadTanque, int cantidadTanqueMax, std::string jugador){
	char datoParaImprimir[20];

	std::strcpy(datoParaImprimir,jugador.c_str());
	PrintString(imagenDelTerreno, datoParaImprimir, fondoUsuario.TellWidth()/3, fondoTerreno.TellHeight()+50 , 60, color);


	std::string dato = this->obtenerDatos(cantidadAlmacenada, cantidadMaximaEnElAlmacen);
	std::strcpy(datoParaImprimir,dato.c_str());

	PrintString(imagenDelTerreno, datoParaImprimir, (fondoUsuario.TellWidth()/4)-80, imagenDelTerreno.TellHeight()-30 , 10, color);

	std::string datoDos = this->obtenerDatos(cantidadTanque, cantidadTanqueMax);
	std::strcpy(datoParaImprimir,datoDos.c_str());

	PrintString(imagenDelTerreno, datoParaImprimir, fondoUsuario.TellWidth()-210, imagenDelTerreno.TellHeight()-30 , 10, color);
}
std::string Imagen::casquearNumeroAString(int numero){
	//   int to string en c++
	std::ostringstream convert;
	convert<<numero;
	return convert.str();
}
std::string Imagen::obtenerDatos(int cantidadAlmacenada, int cantidadMaximaEnElAlmacen){

	std::string primerDato= this->casquearNumeroAString(cantidadAlmacenada);
	std::string segundoDato = this->casquearNumeroAString(cantidadMaximaEnElAlmacen);
	std::string dato = primerDato +"/"+ segundoDato;
	return dato;
}
