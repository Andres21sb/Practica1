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

char Trabajador::netoMenorOIgualAlPromedio(double netoTotal){
    if(salarioNeto()<=netoTotal)
        return '*';
    else
        return' ';
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
    s<<"|"<<' '<<id<<' '<<'|'<<' '<<this->formateaApellidosA20()<<' '<<'|'<<' '<<formateaNombreA14()
    <<' '<<'|'<<'\t'<<formateaCifras(salario)<<'\t'<<'|'<<' '<<formateaCifras(deducciones())<<'\t'<<'|'
    <<' '<<formateaCifras(salarioNeto())<<'\t'<<'|';
    return s.str();
}

int Trabajador::tamNombre(){
    int tam = nombre.size();
    return tam;
}

string Trabajador::formateaApellidosA20(){
    int faltante;
    stringstream s;
    s<<primerApellido<<' '<<segundoApellido;
    int tamNombre = primerApellido.size()+segundoApellido.size()+1;
    if(tamNombre<20){
        faltante = 20 - tamNombre;
        while(faltante !=0){
            s<<' ';
            faltante--;
        }
    }
    return s.str();
}

string Trabajador::formateaNombreA14(){
    int faltante;
    stringstream s;
    s<<nombre;
    int tamNombre = nombre.size();
    if(tamNombre<14){
        faltante = 14 - tamNombre;
        while(faltante !=0){
            s<<' ';
            faltante--;
        }
    }
    return s.str();
}

string Trabajador::formateaCifras(double numEntrada){
    stringstream  s;
    if(numEntrada>=1000000) {
        int unidadesMillon = (int) numEntrada / 1000000;
        int centenasMillar = (int) (numEntrada - (unidadesMillon * 1000000)) / 1000;
        int centenas = (int) ((numEntrada - (unidadesMillon * 1000000)) - centenasMillar * 1000);
        int decimales = (((numEntrada - (unidadesMillon * 1000000)) - centenasMillar * 1000)-centenas)*100;
        if(centenas == 0){
            if(decimales == 0){
                s<<unidadesMillon<<','<<centenasMillar<<','<<"000"<<'.'<<"00";
            } else{
                s<<unidadesMillon<<','<<centenasMillar<<','<<"000"<<'.'<<decimales;

            }
        }else{
            if(decimales == 0){
                s<<unidadesMillon<<','<<centenasMillar<<','<<centenas<<'.'<<"00";
            } else{
                s<<unidadesMillon<<','<<centenasMillar<<','<<centenas<<'.'<<decimales;

            }
        }
    }else{
        if(numEntrada>=1000){
            int centenasMillar = (int) numEntrada/1000;
            int centenas = (int) (numEntrada - centenasMillar * 1000);
            int decimales = ((numEntrada - centenasMillar * 1000)-centenas)*100;
            if(centenas == 0){
                if(decimales == 0){
                    s<<centenasMillar<<','<<"000"<<'.'<<"00";
                } else{
                    s<<centenasMillar<<','<<"000"<<'.'<<decimales;

                }
            }else{
                if(decimales == 0){
                    s<<centenasMillar<<','<<centenas<<'.'<<"00";
                } else{
                    s<<centenasMillar<<','<<centenas<<'.'<<decimales;

                }
            }
        }
        else{
            if(numEntrada>100){
                int centenas = (int) numEntrada;
                int decimales =  (numEntrada -centenas)*100;
                if(centenas == 0){
                    if(decimales == 0){
                        s<<"0"<<'.'<<"00";
                    } else{
                        s<<centenas<<'.'<<decimales;

                    }
                }else{
                    if(decimales == 0){
                        s<<"0"<<'.'<<"00";
                    } else{
                        s<<centenas<<'.'<<decimales;

                    }                }
            }
        }
    }
    return s.str();
}

string Trabajador::formateaCifras(int numEntrada){
    stringstream  s;
    if(numEntrada>=1000000) {
        int unidadesMillon = (int) numEntrada / 1000000;
        int centenasMillar = (int) (numEntrada - (unidadesMillon * 1000000)) / 1000;
        int centenas = (int) ((numEntrada - (unidadesMillon * 1000000)) - centenasMillar * 1000);
        int decimales = (int) (((numEntrada - (unidadesMillon * 1000000)) - centenasMillar * 1000)-centenas)*100;
        if(centenas == 0){
            if(decimales == 0){
                s<<unidadesMillon<<','<<centenasMillar<<','<<"000"<<'.'<<"00";
            } else{
                s<<unidadesMillon<<','<<centenasMillar<<','<<"000"<<'.'<<decimales;

            }
        }else{
            s<<unidadesMillon<<','<<centenasMillar<<','<<centenas<<'.'<<decimales;
        }
    }else{
        if(numEntrada>=1000){
            int centenasMillar = (int) numEntrada/1000;
            int centenas = (int) (numEntrada - centenasMillar * 1000);
            int decimales = (int) ((numEntrada - centenasMillar * 1000)-centenas)*100;
            if(centenas == 0){
                if(decimales == 0){
                    s<<centenasMillar<<','<<"000"<<'.'<<"00";
                } else{
                    s<<centenasMillar<<','<<"000"<<'.'<<decimales;

                }
            }else{
                s<<centenasMillar<<','<<centenas<<'.'<<decimales;
            }
        }
        else{
            if(numEntrada>100){
                int centenas = (int) numEntrada;
                int decimales = (int) (numEntrada -centenas)*100;
                if(centenas == 0){
                    if(decimales == 0){
                        s<<"0"<<'.'<<"00";
                    } else{
                        s<<centenas<<'.'<<decimales;

                    }
                }else{
                    s<<centenas<<'.'<<decimales;
                }
            }
        }
    }

    return s.str();
}