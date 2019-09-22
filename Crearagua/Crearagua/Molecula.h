//
//  Oxigeno.h
//  Crearagua
//
//  Created by Fabiola on 9/21/19.
//  Copyright © 2019 Fabiola Jimenez. All rights reserved.
//

#ifndef Oxigeno_h
#define Oxigeno_h

#pragma once
#include <queue>
#include <unordered_map>
#include <memory>
#include <string>
using namespace std;
#include "Aleatorizador.h"

class Molecula
{
public:
    
    enum Estado {
        esperando,
        formandoagua,
        destruido
    };
    
    enum Tipo {
        hidrogeno,
        oxigeno,
        agua
    };
    
    static unordered_map< int , int > estadomoleculas;
    /* Este es el estado de las moleculas de la barrera: Id == id del atomo, actuar = sera el mensaje de la barrera que indica si puede formar agua o no
     *  Si el nuevo estado es igual a formandoagua, indica que la molecula esta formando agua, pues la masa del agua es de 18gmol
     */
    
    static queue< shared_ptr<Molecula>> HidrogenosEsperando;
    static queue< shared_ptr<Molecula>> OxigenosEsperando;
    
    static int gnrdId;
    
    Molecula();
    Molecula(Estado ne, Tipo nt);
    virtual ~Molecula();
    
    int obtId();
    virtual int estado();
    virtual void actuar();
    virtual string estadoString();
    virtual int Tipo();
    
private:
    int id;
    Estado e;
    enum Tipo t;
};



Molecula::~Molecula()
{
}

int Molecula::obtId()
{
    return id;
}

int Molecula::Tipo()
{
    return t;
}

int Molecula::estado()
{
    return e;
}

void Molecula::actuar() //Dependiendo del mensaje que envio la barrera, la molecula se convierte en agua o sigue esperando
{
    switch (e)
    {
        case esperando:
        {
            try {
                int msj = estadomoleculas.at(id);
                if (msj == formandoagua){
                    cout << "se formo una agua con: " << id << endl;
                }else{
                    e = Estado(msj);
                 // Si aqui hay un mensaje hay que formar agua
                }
            }catch(out_of_range oor) {
                // no tiene ning˙n mensaje de la barrera ni de main => debe seguir esperando
            }
            break;
        }
        case formandoagua:
        {
            e = destruido;
            break;
        }
    }
}
    
    

string Molecula::estadoString()
{
    string rsl = "";
    switch (e)
    {
        case esperando:
        {
            rsl = "La molecula esta esperando en la barrera";
            break;
        }
        case formandoagua:
        {
            rsl = "La molecula esta formando agua";
            break;
        }
        case destruido:
        {
            rsl = "Se formo el agua";
            break;
        }
    }
    return rsl;
}
#endif /* Molecula_h */
