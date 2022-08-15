//
// Created by Serch on 14/8/2022.
//

#include "Trabajador.h"

Trabajador::Trabajador(const string &id, const string &primerApellido, const string &segundoApellido,
                       const string &nombre, const string &fechaNacimiento, double salario) : id(id), primerApellido(
        primerApellido), segundoApellido(segundoApellido), nombre(nombre), fechaNacimiento(fechaNacimiento),
                                                                                              salario(salario) {}

Trabajador::~Trabajador() {

}

const string &Trabajador::getId() const {
    return id;
}

void Trabajador::setId(const string &id) {
    Trabajador::id = id;
}

const string &Trabajador::getPrimerApellido() const {
    return primerApellido;
}

void Trabajador::setPrimerApellido(const string &primerApellido) {
    Trabajador::primerApellido = primerApellido;
}

const string &Trabajador::getSegundoApellido() const {
    return segundoApellido;
}

void Trabajador::setSegundoApellido(const string &segundoApellido) {
    Trabajador::segundoApellido = segundoApellido;
}

const string &Trabajador::getNombre() const {
    return nombre;
}

void Trabajador::setNombre(const string &nombre) {
    Trabajador::nombre = nombre;
}

const string &Trabajador::getFechaNacimiento() const {
    return fechaNacimiento;
}

void Trabajador::setFechaNacimiento(const string &fechaNacimiento) {
    Trabajador::fechaNacimiento = fechaNacimiento;
}

double Trabajador::getSalario() const {
    return salario;
}

void Trabajador::setSalario(double salario) {
    Trabajador::salario = salario;
}

string Trabajador::toString(){
    stringstream s;
    s<<"    Trabajador      "<<endl
    <<"id; ->"<<id<<endl
      <<"primerApellido; -> "<<primerApellido<<endl
      <<"segundoApellido;-> "<<segundoApellido<<endl
      <<"nombre; -> "<<nombre<<endl
      <<"fechaNacimiento; -> "<<fechaNacimiento<<endl
      <<"salario; -> "<<salario<<endl;
    return s.str();
}

bool Trabajador::idMayor(Trabajador* trabajadorEntrada){
    if(trabajadorEntrada->getId()<this->getId()){
        return true;
    }else
        return false;
}
Trabajador& Trabajador::operator=(Trabajador a) {

        id = a.id ;
        primerApellido= a.primerApellido;
        segundoApellido = a.segundoApellido;
        nombre= a.nombre;
        fechaNacimiento = a.fechaNacimiento;
        salario = a.salario;
        return *this;

}
bool Trabajador::apellidoMayor(Trabajador *trabajadorEntrada) {
    if(trabajadorEntrada->getPrimerApellido()<this->getPrimerApellido())
        return true;
    else{
        if(trabajadorEntrada->getPrimerApellido()==this->getPrimerApellido()){
            if(trabajadorEntrada->getSegundoApellido()<this->getSegundoApellido())
                return true;
            else{
                if(trabajadorEntrada->getSegundoApellido()==this->getSegundoApellido()){
                    if(trabajadorEntrada->getNombre()<this->getNombre())
                        return true;
                    else
                        return false;
                }
            }
        }
    }
return false;
}

double Trabajador::deducciones(){
    double deducciones;
    if(this->salario<950000){
        deducciones = this->salario * 0.09;
        return deducciones;
    }else{
        deducciones = this->salario * 0.09 + ((this->salario - 950000)*0.05);
        return deducciones;
    }
}

double Trabajador::salarioNeto(){
    double netoSalida;
    netoSalida = this->salario - this->deducciones();
    return netoSalida;
}

bool Trabajador::netoMayorAlPromedio(double promedio){
    if(this->salarioNeto()>promedio)
        return true;
    else
        return false;
}

string Trabajador::toStringFormatoReporte(){
    stringstream s;
    s<<"|"<<' '<<id<<' '<<'|'<<' '<<this->formateaApellidosA19()<<' '<<'\t'<<'\t'<<'|'<<' '<<nombre
    <<'\t'<<'|'<<'\t'<<salario<<'\t'<<"    "<<'|'<<'\t'<<deducciones()<<'\t'<<"     "<<'|'<<'\t'<<"   "<<salarioNeto()<<'\t'<<'|'<<" "<<"*"<<' '<<'|'<<endl;
    return s.str();
}

int Trabajador::tamNombre(){
    int tam = nombre.size();
    return tam;
}

string Trabajador::formateaApellidosA19(){
    int faltante;
    stringstream s;
    s<<primerApellido<<' '<<segundoApellido;
    int tamNombre = primerApellido.size()+segundoApellido.size()+1;
    if(tamNombre<19){
        faltante = 19 - tamNombre;
        while(faltante !=0){
            s<<' ';
            faltante--;
        }
    }
    return s.str();
}