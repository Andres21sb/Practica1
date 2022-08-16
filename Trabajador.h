//
// Created by Serch on 14/8/2022.
//

#ifndef PRACTICA1_TRABAJADOR_H
#define PRACTICA1_TRABAJADOR_H
#include "utiles.h"

class Trabajador {
private:
    string id;
    string primerApellido;
    string segundoApellido;
    string nombre;
    string fechaNacimiento;
    double salario;

public:
    Trabajador(const string &id, const string &primerApellido, const string &segundoApellido, const string &nombre,
               const string &fechaNacimiento, double salario);

    virtual ~Trabajador();

    const string &getId() const;

    void setId(const string &id);

    const string &getPrimerApellido() const;

    void setPrimerApellido(const string &primerApellido);

    const string &getSegundoApellido() const;

    void setSegundoApellido(const string &segundoApellido);

    const string &getNombre() const;

    void setNombre(const string &nombre);

    const string &getFechaNacimiento() const;

    void setFechaNacimiento(const string &fechaNacimiento);

    double getSalario() const;

    void setSalario(double salario);

    string toString();

    bool idMayor(Trabajador*);
    bool apellidoMayor(Trabajador*);

    Trabajador& operator =(Trabajador a);

    double deducciones();

    double salarioNeto();

    char netoMenorOIgualAlPromedio(double);

    bool netoMayorAlPromedio(double);

    string toStringFormatoReporte();

    int tamNombre();

    string formateaApellidosA20();
    string formateaNombreA14();
    string formateaCifras(double);
    string formateaCifras(int);
};


#endif //PRACTICA1_TRABAJADOR_H
