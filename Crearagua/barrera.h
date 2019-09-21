#pragma once
#include <iostream>
#include <omp.h>
#include "moleculeManager.h"

class barrera {

	int Hs = 0;
	int Os = 0;

	// Metodo que simboliza la formación de agua. remueve 2 Hs y un O de la barrera.
	void formaAgua(moleculeManager manager) {
		this->Hs - 2;
		this->Os --;

		manager.formaAgua();
	}

};