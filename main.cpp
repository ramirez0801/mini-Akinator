#include "arbol.h"
#include "nodoA.h"

int main(int argc, char const *argv[])
{
    cArbol arbol;
	int opc;
	do
	{
		cout<<"1)Jugar\n2)Cargar\n3)Guardar\nOpc: ";
		cin>>opc;
		switch (opc)
		{
		case 1:
			arbol.insertar();
			arbol.insertar();
			break;
		case 2:
			break;
		case 3:
			arbol.guardar();
			break;
		case 0:
			cout<<"\nSaliendo...\n";
			break;
		default:
			cout<<"Opcion no valida\n";
			break;
		}
	}while(opc!=0);
	

	cout << "\nExito\n";

    return 0;
}
