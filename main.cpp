#include "FileManager.h"

int main() {
  FileManager arch;
    ListaGenerica<Trabajador>* lista = new ListaGenerica<Trabajador>;
    lista = arch.recuperaTrabajadores();
    lista->ordenaPorPrimerApellidoAscendente();
    cout<<lista->toString()<<endl;
   Trabajador* prueba = new Trabajador("118210401","Mendez","Solano","Andres","1",650000);
   cout<<prueba->deducciones()<<endl;
   cout<<prueba->salarioNeto()<<endl;

  cout<<"Neto promedio -> "<<lista->promedioSalariosNetos()<<endl;

  cout<<"Reporte"<<endl;
  cout<<lista->reporte()<<endl;
  /*cout<<prueba->toStringFormatoReporte()<<endl;*/
  prueba = lista->devuelvePorId("736847602");
  cout<<prueba->toString()<<endl;
  int tam;
  tam = prueba->formateaApellidosA20().size();
  cout<<tam<<endl;





    std::cout << "Hello, World!" << std::endl;
    return 0;
}
