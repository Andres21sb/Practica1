//
// Created by Serch on 14/8/2022.
//

#include "FileManager.h"
ListaGenerica<Trabajador>* FileManager::recuperaTrabajadores(){
    //aux
    Trabajador* auxTrabajador;
    ListaGenerica<Trabajador>* listaSalida= new ListaGenerica<Trabajador>;
    string auxid;
    string auxprimerApellido;
    string auxsegundoApellido;
    string auxnombre;
    string auxfechaNacimiento;
    string auxsalarioString;
    double auxsalario;
    fstream inputFile ("salarios.txt",ios::in);
    if(inputFile.is_open()){
        while(!inputFile.eof()){
            getline(inputFile,auxid,'\t');
            getline(inputFile,auxprimerApellido,'\t');
            getline(inputFile,auxsegundoApellido,'\t');
            getline(inputFile,auxnombre,'\t');
            getline(inputFile,auxfechaNacimiento,'\t');
            getline(inputFile,auxsalarioString,'\n');
            auxsalario = stod(auxsalarioString);
            auxTrabajador= new Trabajador(auxid,auxprimerApellido,auxsegundoApellido,auxnombre,auxfechaNacimiento,
                                          auxsalario);
            listaSalida->ingresaObj(auxTrabajador);
        }
        inputFile.close();
    }
    return listaSalida;
}