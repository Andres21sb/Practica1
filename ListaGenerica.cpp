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
int ListaGenerica<tipo>::cuentaNodos(){
    IteradorLista<NodoGenerico<Trabajador>>* it = this->getIterador();
    int cantNodos = 0 ;
    while(it->Actual() != nullptr){
        cantNodos ++;
        it->Mover();
    }
return cantNodos;
}
template<class tipo>
tipo* ListaGenerica<tipo>::devuelvePorId(string idEntrada){
    IteradorLista<NodoGenerico<Trabajador>>* it = this->getIterador();
    while (it->Actual()!= nullptr){
        if(it->Actual()->getTipo()->getId() == idEntrada)
            return it->Actual()->getTipo();
        it->Mover();
    }
    return nullptr;
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
            actual = actual ->getSig();                                     //j++
        }
        pivote = pivote->getSig();                                          //i++
    }
}

template <class tipo>
double ListaGenerica<tipo>::promedioSalariosNetos(){
    IteradorLista<NodoGenerico<Trabajador>>* it = this->getIterador();
    //aux
    double sumatoriaNetos = 0;
    double promedioNetos = 0;
    while(it->Actual() != nullptr){
        sumatoriaNetos +=it->Actual()->getTipo()->salarioNeto();
        it->Mover();
    }
    promedioNetos=(double) sumatoriaNetos/this->cuentaNodos();
    return promedioNetos;
}
template<class tipo>
string ListaGenerica<tipo>::lineaDivisora(){
    stringstream s;
    //header
    s<<"+";
    int cuentaCaracteres=11;
    while(cuentaCaracteres!=0){
        s<<"-";
        cuentaCaracteres--;
    }
    s<<"+";
    cuentaCaracteres=27;
    while(cuentaCaracteres!=0){
        s<<"-";
        cuentaCaracteres--;
    }
    s<<"+";
    cuentaCaracteres = 18;
    while(cuentaCaracteres!=0){
        s<<"-";
        cuentaCaracteres--;
    }
    s<<"+";
    cuentaCaracteres = 16;
    while(cuentaCaracteres!=0){
        s<<"-";
        cuentaCaracteres--;
    }
    s<<"+";
    cuentaCaracteres = 16;
    while(cuentaCaracteres!=0){
        s<<"-";
        cuentaCaracteres--;
    }
    s<<"+";
    cuentaCaracteres = 18;
    while(cuentaCaracteres!=0){
        s<<"-";
        cuentaCaracteres--;
    }
    s<<"+";
    cuentaCaracteres = 3;
    while(cuentaCaracteres!=0){
        s<<"-";
        cuentaCaracteres--;
    }
    s<<"+"<<endl;

    return s.str();
}

template<class tipo>
string ListaGenerica<tipo>::reporte() {
    IteradorLista<NodoGenerico<Trabajador>>* it = this->getIterador();
    stringstream s;
    //header
s<<this->lineaDivisora();
//fila que indica datos
s<<"|"<<'\t'<<"Id"<<' '<<' '<<"|"<<' '<<"Apellidos"<<'\t'<<'\t'<<'\t'<<"|"<<" "<<"Nombre"<<'\t'<<"   "<<"|"
<<'\t'<<"Sal. bruto"<<"  "<<'|'<<'\t'<<"Deducciones"<<"  "<<'|'<<'\t'<<"   "<<"Sal. neto"<<'\t'<<'|'<<" "<<"*"<<' '<<'|'<<endl;
    s<<this->lineaDivisora();
    //data
    while (it->Actual()!= nullptr){
        s<<it->Actual()->getTipo()->toStringFormatoReporte();
        it->Mover();
    }
    s<<lineaDivisora();
return s.str();
}
