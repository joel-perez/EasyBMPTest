#ifndef IMAGEN_H_
#define IMAGEN_H_

#include "lib/EasyBMP.h"
#include "lib/EasyBMP_Geometry.h"
#include "lib/EasyBMP_Font.h"

const int COLUMNA = 12;
const int FILA = 7;
const int MARGEN_COLUMNA = 80;
const int MARGEN_FILA =30;
// .......

class Imagen{
private:
	RGBApixel color;
	BMP cultivo;
	BMP fondoTerreno;
	BMP fondoUsuario;
	BMP imagenDelTerreno;

public:
	/*
	 * PRE
	 * POST dimensiones de la imagen final creada.
	 */
	Imagen();

	/*
	 * PRE
	 * POST imagen del estado del terreno en cada turno creado.
	 */
	void obtenerImagenDelTerreno(char* jugador);

private:
	/*
	 * PRE
	 * POST adecua las medidas del cultivo.
	 */
	void rescalarImagenes();
	/*
	 * PRE
	 * POST coloca los fondos del disenio en la imagen final.
	 */
	void pegarFondos();
};
#endif
