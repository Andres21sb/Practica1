//
// Created by Serch on 14/8/2022.
//

#ifndef PRACTICA1_ITERADOR_H
#define PRACTICA1_ITERADOR_H
#include "utiles.h"

template<class tipo>
class Iterador
{
public:
    virtual tipo* Inicio() = 0;
    virtual tipo* Final() = 0;
    virtual tipo* Actual() = 0;
    virtual bool Finalizo() = 0;
    virtual void Mover() = 0;
};



#endif //PRACTICA1_ITERADOR_H
