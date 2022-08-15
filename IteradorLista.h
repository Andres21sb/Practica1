//
// Created by Serch on 14/8/2022.
//

#ifndef PRACTICA1_ITERADORLISTA_H
#define PRACTICA1_ITERADORLISTA_H
#include "Iterador.h"

template<class tipo>
class IteradorLista : public Iterador<tipo>
{
private:
    tipo* primero;//Me guarda el primero lugar siempre
    tipo* iterador;
public:
    IteradorLista(tipo*);//Constructor

    //------- Metodos -------
    tipo* Inicio();
    tipo* Final();
    tipo* Actual();
    bool Finalizo();
    void Mover();
};



#endif //PRACTICA1_ITERADORLISTA_H
