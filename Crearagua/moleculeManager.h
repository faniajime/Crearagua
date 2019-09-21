#pragma once
#include <iostream>
#include <omp.h>
#include "barrera.h"
using namespace std;

class moleculeManager {

	int hidrogenos;
	int oxigenos;



public:
	moleculeManager() {

	}
	moleculeManager(int hidrogenos, int oxigenos) {
		this->hidrogenos = hidrogenos;
		this->oxigenos = oxigenos;
	}

	// Funciones para obtener la cantidad de Hs y Os que hay en el pool de atomos.
	int getHs() {

		return this->hidrogenos;
	}

	int getOs() {

		return this->oxigenos;
	}

	// Con estos metodos se representa cuando un hilo agarra un atomo
	void quitaO() {
		this->oxigenos --;
	}

	void quitaHs() {
		this->hidrogenos --;
	}

	// Con este metodo se representa la formacion de una molecula de agua
	void formaAgua() {
		this->aguas ++;
	}

	
};