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
  prueba = lista->devuelvePorId("153874883");
  cout<<prueba->toString()<<endl;
  int tam;
  tam = prueba->getPrimerApellido().size() + prueba->getSegundoApellido().size();
  cout<<tam;

  cout<<prueba->formateaApellidosA19()<<endl;
  cout<<prueba->formateaApellidosA19().size();





    std::cout << "Hello, World!" << std::endl;
    return 0;
}
