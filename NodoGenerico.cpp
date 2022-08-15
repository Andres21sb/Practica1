//
// Created by Serch on 14/8/2022.
//

#include "NodoGenerico.h"

template<class tipo>
NodoGenerico<tipo>::NodoGenerico(tipo* tip, NodoGenerico<tipo>* si) {
    this->ptr = tip;
    this->sig = si;
}
template<class tipo>
NodoGenerico<tipo>::~NodoGenerico(){
    if (ptr)delete ptr;
    if (sig)delete sig;
}

template<class tipo>
void NodoGenerico<tipo>::setTipo(tipo* tip) { ptr = tip; }

template<class tipo>
void NodoGenerico<tipo>::setSig(NodoGenerico<tipo>* si) { sig = si; }

template<class tipo>
tipo* NodoGenerico<tipo>::getTipo() { return ptr; }


template<class tipo>
NodoGenerico<tipo>* NodoGenerico<tipo>::getSig() { return sig; }
