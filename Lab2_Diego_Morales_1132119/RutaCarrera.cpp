#include "RutaCarrera.h"
#include<stdlib.h>
#include<time.h>

RutaCarrera::RutaCarrera() {

}
RutaCarrera::~RutaCarrera(){

}
void RutaCarrera::CambiarPosicion(int Ruta[70], int Movimientos[10], int **Pos) {
	srand(time(NULL));
	int Valor = rand() % 10;
	int NuevaPosicion = **Pos + Movimientos[Valor];
	if (NuevaPosicion >= 70) {
		NuevaPosicion = 69;
	}
	else
	{
		if (NuevaPosicion < 0)
		{
			NuevaPosicion = 0;
		}
		else
		{	
			NuevaPosicion = NuevaPosicion;
		}
	}
}