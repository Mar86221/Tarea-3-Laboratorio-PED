#include "PupuseriaEjercicio.hpp"
using namespace std;

int menu()
{
    int opcion;
    cout<<"\n"<<"Sistema de ordenes Pupuseria La Cubana"<<"\n"<<endl;
    cout<<"1) Insertar pedidos "<<endl;
    cout<<"2) Mostrar los pedidos. "<<endl;
    cout<<"3) Eliminar pedidos ya despachados. "<<endl;
    cout<<"4) Salir "<<endl;
    cout<<"Opcion: ";
    cin>>opcion; cin.ignore();
    return opcion;
}


int main(int argc, char const *argv[])
{
    cout<<"\n"<<"---PUPUSERIA LA CUBANA---"<<"\n"<<endl;

    listasimple listdatos;

    nodo *pInicio = NULL;
    bool continuar=true;
    int num = 0;
    string nombr = "";
    string arrmai = "";
    double F = 0;
    double Q = 0;
    double R = 0;
    double C = 0;
    double L = 0;
    int cke = 0;

    do
    {
        switch (menu())
        {
        case 1:
            cout<<"Digite el numero de la orden (1-99): ";
            cin>>num; cin.ignore();
            cout<<"Nombre del cliente: ";
            getline(cin,nombr); 
            cout<<"Arroz o Maiz (A o M): ";
            getline(cin,arrmai);
            cout<<"Digite cuantas pupusas y de que sabor (sino ha pedido de alguna digite 0): "<<"\n"<<endl;
            cout<<"Frijol con queso: ";
            cin>>F;
            cout<<"Queso: ";
            cin>>Q;
            cout<<"Revueltas: ";
            cin>>R;
            cout<<"Queso con Chicharron: ";
            cin>>C;
            cout<<"Queso con loroco: ";
            cin>>L;
            cout<<"Con Coca-Cola o sin (Inserte 1 para SI o 0 para NO): ";
            cin>>cke;
            listdatos.insinicio(num, nombr, arrmai, F, Q, R, C, L, cke);
            cout<<"\n"<<"Pedido guardado exitosamente! "<<"\n"<<endl;
            break;
        case 2:
            listdatos.mostrarlistaiter();
            
            break;
        case 3:
            cout<<"Digite la orden que desea eliminar (ingrese el numero de orden): ";
            cin>>num;
            if(listdatos.borrado(num)){
                cout<<"\n"<<"Se ha eliminado la orden "<<"\n"<<endl;   
            }else{
                cout<<"\n"<<"No se pudo eliminar la orden "<<"\n"<<endl;
            }
            break;
        case 4:
            continuar = false;
            break;
        default:
            cout<<"La opcion no es valida o no existe, favor intentar denuevo "<<endl;
            break;
        }
    } while (continuar);
    

    return 0;
}