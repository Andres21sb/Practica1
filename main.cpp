#include "FileManager.h"

int main() {
    FileManager arch;
    ListaGenerica<Trabajador>* lista = new ListaGenerica<Trabajador>;
    lista = arch.recuperaTrabajadores();
    lista->ordenaPorPrimerApellidoAscendente();
    cout<<lista->toString()<<endl;




    std::cout << "Hello, World!" << std::endl;
    return 0;
}
