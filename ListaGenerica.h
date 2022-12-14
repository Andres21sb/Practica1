//
// Created by Serch on 14/8/2022.
//

#ifndef PRACTICA1_LISTAGENERICA_H
#define PRACTICA1_LISTAGENERICA_H


#include"NodoGenerico.cpp"
#include"IteradorLista.cpp"
#include "Trabajador.h"

template<class tipo>
class ListaGenerica {
private:
    NodoGenerico<tipo> *ppio;
    int cant;
public:
    ListaGenerica();

    virtual ~ListaGenerica();

    bool isEmpty();

    int getCant();

    bool ingresaObj(tipo *);

    string toString();

    int cuentaNodos();

    tipo* devuelvePorId(string);

    //---------- Iterador ----------
    IteradorLista<NodoGenerico<tipo>> *getIterador();

    //metodos de trabajador

    void ordenaPorPrimerApellidoAscendente();

    string minimoDeLosSalariosBrutos();
    string minimoDeLosSalariosNetos();
    string minimoDeducciones();

    string maximoDeLosSalariosBrutos();
    string maximoDeLosSalariosNetos();
    string maximoDeducciones();

    string creaLinea(int);
    string lineaDivisora();

    string sangria(int);

    string reporte();

    double promedioSalariosNetos();
    string promedioSalariosNetosString();
    string promedioSalariosBrutos();
    string promedioDeducciones();


};


#endif //PRACTICA1_LISTAGENERICA_H
