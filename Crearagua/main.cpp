#include <iostream>
#include <string>
using namespace std;

#include "moleculeManager.h"
#include "Aleatorizador.h"

/*
#include "Aleatorizador.h"
*/



int main()
{

	// Hidrogenos y oxigenos con los que se inicia
	int Hs;
	int Os;

	// La cantidad de moléculas de agua se maneja en el main
	int aguas = 0;

	// El usuario define la cantidad de Hs y Os
	cout << "Digite la cantidad de hidrogenos en el sistema: "; cin >> Hs;
	cout << "Digite la cantidad de oxigenos en el sistema: "; cin >> Os;

	moleculeManager manager(Hs, Os);

	Aleatorizador::inicializar_generador_random();

}



void takeToBarrier(moleculeManager manager, barrera barrera) {
	manager
}