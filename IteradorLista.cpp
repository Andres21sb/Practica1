//
// Created by Serch on 14/8/2022.
//

#include "IteradorLista.h"

//------------ Constructor -------------
template<class tipo>
IteradorLista<tipo>::IteradorLista(tipo* n) {
    primero = iterador = n;
}

//-------------- Metodos ---------------
template<class tipo>
tipo* IteradorLista<tipo>::Inicio() {
    iterador = primero;
    return primero;
}

//----

template<class tipo>
tipo* IteradorLista<tipo>::Final() {
    while (iterador->getSig() != nullptr) {
        Mover();
    }
    return iterador;
}

//----

template<class tipo>
tipo* IteradorLista<tipo>::Actual() {
    return iterador;
}

//----

template<class tipo>
bool IteradorLista<tipo>::Finalizo() {
    if (iterador == nullptr) {
        return true;
    }
    return false;
}

//----

template<class tipo>
void IteradorLista<tipo>::Mover() {
    if (iterador != nullptr) {//Evito el error por si el usuario invoca cuando ya esta al final de lista
        iterador = iterador->getSig();
    }
}