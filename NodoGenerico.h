//
// Created by Serch on 14/8/2022.
//

#ifndef PRACTICA1_NODOGENERICO_H
#define PRACTICA1_NODOGENERICO_H
#include "utiles.h"
template <class tipo>
class NodoGenerico {
private:
    tipo* ptr;
    NodoGenerico<tipo>* sig;
public:
    NodoGenerico(tipo*, NodoGenerico<tipo>*);
    virtual ~NodoGenerico();
    void setTipo(tipo*);
    void setSig(NodoGenerico<tipo>*);
    tipo* getTipo();
    NodoGenerico<tipo>* getSig();
};




#endif //PRACTICA1_NODOGENERICO_H
