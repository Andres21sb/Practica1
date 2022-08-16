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
string ListaGenerica<tipo>::minimoDeLosSalariosBrutos() {
    ListaGenerica<tipo>* l2 = this;
    IteradorLista<NodoGenerico<Trabajador>>* it= l2->getIterador();
    NodoGenerico<Trabajador>* pivote = nullptr, * actual = nullptr;
    //bubble sort
    Trabajador* bubble;
    pivote = it->Inicio();
    while(pivote != it->Final()){
        actual = pivote->getSig();
        while(actual != nullptr){
            if(pivote->getTipo()->getSalario()>actual->getTipo()->getSalario()){
                bubble = pivote->getTipo();
                pivote->setTipo(actual->getTipo());
                actual->setTipo(bubble);

            }
            actual = actual ->getSig();                                     //j++
        }
        pivote = pivote->getSig();                                          //i++
    }
    double cantSalida = it->Inicio()->getTipo()->getSalario();
    return it->Inicio()->getTipo()->formateaCifras(cantSalida);
}

template <class tipo>
string ListaGenerica<tipo>::minimoDeLosSalariosNetos() {
    ListaGenerica<tipo>* l2 = this;
    IteradorLista<NodoGenerico<Trabajador>>* it= l2->getIterador();
    NodoGenerico<Trabajador>* pivote = nullptr, * actual = nullptr;
    //bubble sort
    Trabajador* bubble;
    pivote = it->Inicio();
    while(pivote != it->Final()){
        actual = pivote->getSig();
        while(actual != nullptr){
            if(pivote->getTipo()->salarioNeto() >actual->getTipo()->salarioNeto()){
                bubble = pivote->getTipo();
                pivote->setTipo(actual->getTipo());
                actual->setTipo(bubble);

            }
            actual = actual ->getSig();                                     //j++
        }
        pivote = pivote->getSig();                                          //i++
    }
    double cantSalida = it->Inicio()->getTipo()->salarioNeto();
    return it->Inicio()->getTipo()->formateaCifras(cantSalida);
}

template <class tipo>
string ListaGenerica<tipo>::minimoDeducciones() {
    ListaGenerica<tipo>* l2 = this;
    IteradorLista<NodoGenerico<Trabajador>>* it= l2->getIterador();
    NodoGenerico<Trabajador>* pivote = nullptr, * actual = nullptr;
    //bubble sort
    Trabajador* bubble;
    pivote = it->Inicio();
    while(pivote != it->Final()){
        actual = pivote->getSig();
        while(actual != nullptr){
            if(pivote->getTipo()->deducciones()>actual->getTipo()->deducciones()){
                bubble = pivote->getTipo();
                pivote->setTipo(actual->getTipo());
                actual->setTipo(bubble);

            }
            actual = actual ->getSig();                                     //j++
        }
        pivote = pivote->getSig();                                          //i++
    }
    double cantSalida = it->Inicio()->getTipo()->deducciones();
    return it->Inicio()->getTipo()->formateaCifras(cantSalida);
}

template <class tipo>
string ListaGenerica<tipo>::maximoDeLosSalariosBrutos() {
    ListaGenerica<tipo>* l2 = this;
    IteradorLista<NodoGenerico<Trabajador>>* it= l2->getIterador();
    NodoGenerico<Trabajador>* pivote = nullptr, * actual = nullptr;
    //bubble sort
    Trabajador* bubble;
    pivote = it->Inicio();
    while(pivote != it->Final()){
        actual = pivote->getSig();
        while(actual != nullptr){
            if(pivote->getTipo()->getSalario()<actual->getTipo()->getSalario()){
                bubble = pivote->getTipo();
                pivote->setTipo(actual->getTipo());
                actual->setTipo(bubble);

            }
            actual = actual ->getSig();                                     //j++
        }
        pivote = pivote->getSig();                                          //i++
    }
    double cantSalida = it->Inicio()->getTipo()->getSalario();
    return it->Inicio()->getTipo()->formateaCifras(cantSalida);
}

template <class tipo>
string ListaGenerica<tipo>::maximoDeLosSalariosNetos() {
    ListaGenerica<tipo>* l2 = this;
    IteradorLista<NodoGenerico<Trabajador>>* it= l2->getIterador();
    NodoGenerico<Trabajador>* pivote = nullptr, * actual = nullptr;
    //bubble sort
    Trabajador* bubble;
    pivote = it->Inicio();
    while(pivote != it->Final()){
        actual = pivote->getSig();
        while(actual != nullptr){
            if(pivote->getTipo()->salarioNeto() <actual->getTipo()->salarioNeto()){
                bubble = pivote->getTipo();
                pivote->setTipo(actual->getTipo());
                actual->setTipo(bubble);

            }
            actual = actual ->getSig();                                     //j++
        }
        pivote = pivote->getSig();                                          //i++
    }
    double cantSalida = it->Inicio()->getTipo()->salarioNeto();
    return it->Inicio()->getTipo()->formateaCifras(cantSalida);
}

template <class tipo>
string ListaGenerica<tipo>::maximoDeducciones() {
    ListaGenerica<tipo>* l2 = this;
    IteradorLista<NodoGenerico<Trabajador>>* it= l2->getIterador();
    NodoGenerico<Trabajador>* pivote = nullptr, * actual = nullptr;
    //bubble sort
    Trabajador* bubble;
    pivote = it->Inicio();
    while(pivote != it->Final()){
        actual = pivote->getSig();
        while(actual != nullptr){
            if(pivote->getTipo()->deducciones()<actual->getTipo()->deducciones()){
                bubble = pivote->getTipo();
                pivote->setTipo(actual->getTipo());
                actual->setTipo(bubble);

            }
            actual = actual ->getSig();                                     //j++
        }
        pivote = pivote->getSig();                                          //i++
    }
    double cantSalida = it->Inicio()->getTipo()->deducciones();
    return it->Inicio()->getTipo()->formateaCifras(cantSalida);
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

template <class tipo>
string ListaGenerica<tipo>::promedioSalariosBrutos(){
    IteradorLista<NodoGenerico<Trabajador>>* it = this->getIterador();
    //aux
    double sumatoria = 0;
    double promedio = 0;
    while(it->Actual() != nullptr){
        sumatoria +=it->Actual()->getTipo()->getSalario();
        it->Mover();
    }
    promedio=(double) sumatoria/this->cuentaNodos();
    return it->Inicio()->getTipo()->formateaCifras(promedio);
}

template <class tipo>
string ListaGenerica<tipo>::promedioDeducciones() {
    IteradorLista<NodoGenerico<Trabajador>>* it = this->getIterador();
    //aux
    double sumatoria = 0;
    double promedio = 0;
    while(it->Actual() != nullptr){
        sumatoria +=it->Actual()->getTipo()->deducciones();
        it->Mover();
    }
    promedio=(double) sumatoria/this->cuentaNodos();
    return it->Inicio()->getTipo()->formateaCifras(promedio);
}

template <class tipo>
string ListaGenerica<tipo>::promedioSalariosNetosString()  {
    IteradorLista<NodoGenerico<Trabajador>>* it = this->getIterador();
    //aux
    double sumatoria = 0;
    double promedio = 0;
    while(it->Actual() != nullptr){
        sumatoria +=it->Actual()->getTipo()->salarioNeto();
        it->Mover();
    }
    promedio=(double) sumatoria/this->cuentaNodos();
    return it->Inicio()->getTipo()->formateaCifras(promedio);
}
template<class tipo>
string ListaGenerica<tipo>::creaLinea(int tam){
    stringstream s;
    s<<'+';
    while(tam!=0){
        s<<"-";
        tam--;
    }

    return s.str();
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
    cuentaCaracteres=22;
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
    cuentaCaracteres = 19;
    while(cuentaCaracteres!=0){
        s<<"-";
        cuentaCaracteres--;
    }
    s<<"+";
    cuentaCaracteres = 15;
    while(cuentaCaracteres!=0){
        s<<"-";
        cuentaCaracteres--;
    }
    s<<"+";
    cuentaCaracteres = 15;
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
string ListaGenerica<tipo>::sangria(int tam){
    stringstream s;
    while (tam>0){
        s<<' ';
        tam--;
    }
    return s.str();
}

template<class tipo>
string ListaGenerica<tipo>::reporte() {
    IteradorLista<NodoGenerico<Trabajador>>* it = this->getIterador();
    stringstream s;
    //header
s<<this->lineaDivisora();
//fila que indica datos
s<<"|"<<'\t'<<"Id"<<' '<<' '<<"|"<<' '<<"Apellidos"<<'\t'<<'\t'<<"   "<<"|"<<" "<<"Nombre"<<'\t'<<"    "<<"|"
<<'\t'<<"Sal. bruto"<<'\t'<<'|'<<' '<<"Deducciones"<<'\t'<<'|'<<' '<<"Sal. neto"<<'\t'<<'|'<<" "<<"*"<<' '<<'|'<<endl;
    s<<this->lineaDivisora();
    //data
    while (it->Actual()!= nullptr){
        s<<it->Actual()->getTipo()->toStringFormatoReporte()<<" "<<it->Actual()->getTipo()->netoMenorOIgualAlPromedio(promedioSalariosNetos())<<' '<<'|'<<endl;;
        it->Mover();
    }
    s<<lineaDivisora();
    //footer
    s<<sangria(52);
    s<<'|'<<'\t'<<minimoDeLosSalariosBrutos()<<'\t'<<'|'<<' '<<minimoDeducciones()<<'\t'<<'|'
    <<' '<<minimoDeLosSalariosNetos()<<'\t'<<'|'<<endl;
    s<<sangria(52);
    s<<'|'<<'\t'<<promedioSalariosBrutos()<<'\t'<<'|'<<' '<<promedioDeducciones()<<'\t'<<'|'
     <<' '<<promedioSalariosNetosString()<<'\t'<<'|'<<endl;
    s<<sangria(52);
    s<<'|'<<'\t'<<maximoDeLosSalariosBrutos()<<'\t'<<'|'<<' '<<maximoDeducciones()<<'\t'<<'|'
     <<' '<<maximoDeLosSalariosNetos()<<'\t'<<'|'<<endl;

    //linea final
    s<<sangria(52)<< creaLinea(19)<< creaLinea(15)<< creaLinea(15)<<'+';

return s.str();
}
