//
// Created by Serch on 14/8/2022.
//

#include "ListaGenerica.h"

template<class tipo>
ListaGenerica<tipo>::ListaGenerica() {
    ppio = nullptr;

}

template<class tipo>
ListaGenerica<tipo>::~ListaGenerica() {
    if (ppio)
        delete ppio;
}

template<class tipo>
int
ListaGenerica<tipo>::
getCant() { return cant; }

template<class tipo>
bool
ListaGenerica<tipo>::
isEmpty() {
    if (ppio)
        return false;
    else
        return true;
}

template<class tipo>
bool
ListaGenerica<tipo>::
ingresaObj(tipo* obj){
    NodoGenerico<tipo>* p = ppio;
    IteradorLista<NodoGenerico<tipo>>* it = this->getIterador();
    if (this->isEmpty()) {
        ppio = new NodoGenerico<tipo>(obj, ppio);
        return true;
    }

    p=it->Final();
    NodoGenerico<tipo> *nuevo = new NodoGenerico<tipo>(obj, nullptr);
    p->setSig(nuevo);
    return true;
}

template<class tipo>
string ListaGenerica<tipo>::toString() {
    stringstream s;
    IteradorLista<NodoGenerico<tipo>>* it = this->getIterador();
    s<<"         --- Lista --- "<<endl;
    while(it->Actual() != nullptr ){
        s<<it->Actual()->getTipo()->toString()<<endl;
        it->Mover();
    }
    return s.str();
}




//----------- Iterador --------
template<class tipo>
IteradorLista<NodoGenerico<tipo>>*ListaGenerica<tipo>::getIterador()
{
    return new IteradorLista<NodoGenerico<tipo>>(ppio);
}


//tra
/*template<class tipo>
void ListaGenerica<tipo>::ordenaPorIdAscendiente(){
    IteradorLista<NodoGenerico<Trabajador>>* it1 = this->getIterador();
    IteradorLista<NodoGenerico<Trabajador>>* it2 = this->getIterador();
    //bubble sort
    Trabajador* bubble;
    while(it1->Actual() != nullptr) {
        while (it2->Actual() != nullptr) {
            if (it2->Actual()->getTipo()->idMayor(it2->Actual()->getSig()->getTipo())){
                bubble = it2->Actual()->getTipo();
                it1->
            }
        }
        it2->Mover();
    }
}*/
template<class tipo>
void ListaGenerica<tipo>::ordenaPorPrimerApellidoAscendente(){
    IteradorLista<NodoGenerico<Trabajador>>* it = this->getIterador();
    NodoGenerico<Trabajador>* pivote = nullptr, * actual = nullptr;
    //bubble sort
    Trabajador* bubble;
    pivote = it->Inicio();
    while(pivote != it->Final()){
        actual = pivote->getSig();
        while(actual != nullptr){
            if(pivote->getTipo()->apellidoMayor(actual->getTipo())){
                bubble = pivote->getTipo();
                pivote->setTipo(actual->getTipo());
                actual->setTipo(bubble);

            }
            actual = actual ->getSig();
        }
        pivote = pivote->getSig();
    }
}

template<class tipo>
string ListaGenerica<tipo>::reporte() {
    stringstream s;
    //header

}
