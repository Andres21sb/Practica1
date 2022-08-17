#include "FileManager.h"

int main() {
   /* SetConsoleOutputCP( 65001 );
    SetConsoleCP( 65001 );*/
  FileManager arch;
    ListaGenerica<Trabajador>* lista = new ListaGenerica<Trabajador>;
    lista = arch.recuperaTrabajadores();
    lista->ordenaPorPrimerApellidoAscendente();


  cout<<"Reporte"<<endl;
 cout<<lista->reporte()<<endl;

    return 0;
}
