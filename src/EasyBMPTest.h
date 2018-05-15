#ifndef IMAGEN_H_
#define IMAGEN_H_

#include "lib/EasyBMP.h"
#include "lib/EasyBMP_Geometry.h"
#include "lib/EasyBMP_Font.h"

const int COLUMNA = 12;
const int FILA = 9;
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
	 * PRE las imagenes utilizadas deben existir
	 * POST imagen del estado del terreno en cada turno creado.
	 */
	void obtenerImagenDelTerreno(std::string jugador, int cantidadAlmacenada, int cantidadMaximaEnElAlmacen, int cantidadTanque, int cantidadTanqueMax);

private:
	/*
	 * PRE
	 * POST adecua las medidas del cultivo.
	 */
	void rescalarImagenes();
	/*
	 * PRE
	 * POST pega en la imagen final los cultivos en su respectiva parcela
	 */
	void pegarEstadoDelCultivo();
	/*
	 * PRE
	 * POST coloca los fondos del disenio en la imagen final.
	 */
	void pegarFondos();

	/*
	 * PRE
	 * POST casquea un int a un string
	 */
	std::string casquearNumeroAString(int numero);

	/*
	 * PRE
	 * POST adecua el string para poder pegarlo en la imagen
	 */
	std::string obtenerDatos(int cantidadAlmacenada, int CantidadMaximaEnElAlmacen);

	/*
	 * PRE
	 * POST pega los datos del usuario y de su juego en la imagen
	 */
	void pegarDatos(int, int, int, int, std::string);
};
#endif
