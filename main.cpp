#include "FileManager.h"

int main() {
    SetConsoleOutputCP( 1252 );
    SetConsoleCP( 1252 );
  FileManager arch;
    ListaGenerica<Trabajador>* lista = new ListaGenerica<Trabajador>;
    lista = arch.recuperaTrabajadores();
    lista->ordenaPorPrimerApellidoAscendente();
  cout<<"Reporte"<<endl;
  cout<<lista->reporte()<<endl;

    return 0;
}
