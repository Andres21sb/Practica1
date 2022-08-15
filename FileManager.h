//
// Created by Serch on 14/8/2022.
//

#ifndef PRACTICA1_FILEMANAGER_H
#define PRACTICA1_FILEMANAGER_H
#include "ListaGenerica.cpp"
#include "Trabajador.h"

class FileManager {
public:
    ListaGenerica<Trabajador>* recuperaTrabajadores();
};


#endif //PRACTICA1_FILEMANAGER_H
