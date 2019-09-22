#pragma once
#include <iostream>
#include <omp.h>
#include "Molecula.h"

using namespace std;

class Barrera {
    
public:
    
   
    Barrera();
    virtual ~Barrera();
    
    static int AguasFormadas;
    
    virtual void FormarAgua();
    
    virtual void cantidadMolecs();
	// Metodo que simboliza la formación de agua. remueve 2 Hs y un O de la barrera.


    
private:
    shared_ptr< Molecula> hidrogeno_ptr;
    shared_ptr< Molecula> oxigeno_ptr;
};

//Revisa que se cumplan las premisas de haber dos hidrogenos y dos oxigenos en cola, los saca de la cola y a cada hilo le pone el estado de estar formando agua, ademas cuenta una agua.
void Barrera::FormarAgua() {
    if((Molecula::HidrogenosEsperando.size())>=2 && (Molecula::OxigenosEsperando.size()) >=1){

            for( int i =0; i<2; i++){
            hidrogeno_ptr = Molecula::HidrogenosEsperando.front();
            Molecula& hidrogeno = *hidrogeno_ptr;
            Molecula::estadomoleculas[hidrogeno.obtId()] = Molecula::formandoagua;
            Molecula::HidrogenosEsperando.pop(); // pasa al siguiente hidrogeno, saca al que habia de la cola
            }
            //Saca a un oxigeno de la cola
            oxigeno_ptr = Molecula::OxigenosEsperando.front();
            Molecula& oxigeno = *oxigeno_ptr;
            Molecula::estadomoleculas[oxigeno.obtId()] = Molecula::formandoagua;
            Molecula::OxigenosEsperando.pop();
#pragma omp atomic
        AguasFormadas++;
        }
    //En caso de que no se cumpla ninguna de las especificaciones, entonces las moleculas seguiran esperando.
	}
void Barrera::cantidadMolecs(){
    cout << "En este momento hay " << Molecula::HidrogenosEsperando.size() << " hidrogenos" << endl;
    cout << "En este momento hay " << Molecula::OxigenosEsperando.size() << " oxigenos" << endl;
    cout << "Se han formado " << AguasFormadas << endl;
}
    


