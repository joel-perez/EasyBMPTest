#include "EasyBMPTest.h"

Imagen::Imagen(){

	cultivo.ReadFromFile("cultivo.bmp");
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
	//redimensionar la imagen del terreno, solo la altura.
	Rescale(fondoTerreno, 'H', (2*MARGEN_FILA)+(FILA*cultivo.TellHeight()));
	// ... FALTA: Buscar forma para que la imagen no se agrande demasiado para que se vean todas las imagenes.
	//Redimensionar la imagen principal, solo la altura.
	//Rescale(imagenDelTerreno,'H',fondoTerreno.TellHeight()+fondoUsuario.TellHeight());
}

void Imagen::pegarFondos(){
	RangedPixelToPixelCopy(fondoTerreno, 0, fondoTerreno.TellWidth(), fondoTerreno.TellHeight(), 0, imagenDelTerreno,0, 0);
	RangedPixelToPixelCopy(fondoUsuario, 0, fondoTerreno.TellWidth(), fondoTerreno.TellHeight()-1, 0, imagenDelTerreno,0, fondoTerreno.TellHeight());
}

void Imagen::obtenerImagenDelTerreno(char* jugador, int cantidadAlmacenada, int cantidadMaximaEnElAlmacen, int cantidadTanque, int cantidadTanqueMax){
	this->rescalarImagenes();
	this->pegarFondos();

	for (int fila = 0; fila < FILA; fila++){
		for (int columna = 0; columna < COLUMNA; columna++){
			//Imprime LETRA del cultivo sobre la imagen de cada cultivo.
			PrintLetter(cultivo, 'D', cultivo.TellWidth()/2, (cultivo.TellHeight()/2)+17, 12, color);
			RangedPixelToPixelCopy(cultivo,0,cultivo.TellWidth(),cultivo.TellHeight(),0,imagenDelTerreno,(columna*cultivo.TellWidth())+MARGEN_COLUMNA,(fila*cultivo.TellHeight())+MARGEN_FILA);
		}
	}

	PrintString(imagenDelTerreno, jugador , fondoUsuario.TellWidth()/3, fondoTerreno.TellHeight()+50 , 60, color);

	//Preparar dato para pegar como string, el del almacen
	char datoParaImprimir[]=" ";

	std::string dato = this->obtenerDatos(cantidadAlmacenada, cantidadMaximaEnElAlmacen);
	std::strcpy(datoParaImprimir,dato.c_str());

	//Pego el dato en la imagen
	PrintString(imagenDelTerreno, datoParaImprimir, (fondoUsuario.TellWidth()/4)-80, imagenDelTerreno.TellHeight()-40 , 10, color);

	// Preparo el otro dato para pegar como string, el del tanque.
	std::string datoDos = this->obtenerDatos(cantidadTanque, cantidadTanqueMax);
	std::strcpy(datoParaImprimir,datoDos.c_str());

	//Pego el dato en la imagen
	PrintString(imagenDelTerreno, datoParaImprimir, fondoUsuario.TellWidth()-210, imagenDelTerreno.TellHeight()-40 , 10, color);

	imagenDelTerreno.WriteToFile("ejemploterreno.bmp");
}
std::string Imagen::casquearNumeroAString(int numero){
	//   int to string en c++
	std::string num;
	int temp;

	while(numero/10 != 0){
		temp = numero%10;
		numero= numero/10;
		temp =temp + 48;
		num = (char)temp + num;
	}

	numero=numero+48;
	num = (char)numero + num ;
	return num;
}
std::string Imagen::obtenerDatos(int cantidadAlmacenada, int cantidadMaximaEnElAlmacen){

	std::string primerDato= this->casquearNumeroAString(cantidadAlmacenada);
	std::string segundoDato = this->casquearNumeroAString(cantidadMaximaEnElAlmacen);
	std::string dato = primerDato +"/"+ segundoDato;
	return dato;
}
