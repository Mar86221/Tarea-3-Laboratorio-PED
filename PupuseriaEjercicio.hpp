#include <iostream>
using namespace std;

struct nodo
{
    int numorder;
    string nombreclient;
    string tipo;
    double FQ;
    double Q;
    double R;
    double QC;
    double QL;
    int coke;
    nodo *sig;
};
class listasimple
{
private:
public:
    nodo *pInicio;
    listasimple();
    void insinicio(int, string, string, double, double, double, double, double, int);
    void mostrarlistaiter(void);
    bool borrado(int);
};

listasimple::listasimple(void)
{
    pInicio = NULL;
}

void listasimple::insinicio(int numorder, string nombreclient, string tipo, double FQ, double Q, double R, double QC, double QL, int coke)
{
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->numorder = numorder;
    nuevo->nombreclient = nombreclient;
    nuevo->tipo = tipo;
    nuevo->FQ = FQ;
    nuevo->Q = Q;
    nuevo->R = R;
    nuevo->QC = QC;
    nuevo->QL = QL;
    nuevo->coke = coke;
    nuevo->sig = pInicio;
    pInicio = nuevo;
}

void listasimple::mostrarlistaiter(void)
{
    nodo *saltarin;
    cout << endl;
    saltarin = pInicio;
    while (saltarin != NULL)
    {
        cout<<"Orden: #" <<saltarin->numorder<<""<<endl;
        cout<<"Nombre cliente: " <<saltarin->nombreclient<<endl;
        cout<<"ARROZ O MAIZ: "<<saltarin->tipo<<endl;
        cout<<"Pupusas y cantidad " <<endl;
        cout<<"FQ: "<<saltarin->FQ<<endl;
        cout<<"Q: "<<saltarin->Q<<endl;
        cout<<"R: "<<saltarin->R<<endl;
        cout<<"QC: "<<saltarin->QC<<endl;
        cout<<"QL: "<<saltarin->QL<<endl;
        cout<<"Coca-Cola?: "<<saltarin->coke<<endl;
        double aux1=1, aux2=1, aux3=1, aux4=1, aux5=1, cke=1, tot=0;
        aux1=saltarin->FQ*0.80;
        //
        aux2=saltarin->Q*0.90;
        //
        aux3=saltarin->R*0.90;
        //
        aux4=saltarin->QC*0.95;
        //
        aux5=saltarin->QL*0.95;
        //
        if (saltarin->coke==1)
        {
            cke=1.25;
        }else{
            cke=0;
        }
        tot=aux1+aux2+aux3+aux4+aux5+cke;
        cout<<"#"<<saltarin->numorder<<" Total: "<<"$"<<tot<<endl;
        cout<<endl;
        saltarin=saltarin->sig;
    }
}

bool listasimple::borrado(int oderx)

{
    if (!pInicio) 
        return false;
    else
    {   
        nodo *borrar = pInicio, *aux;
        if (borrar->numorder == oderx)
        {                             
            pInicio = pInicio->sig;
            delete borrar;
            return true;
        }
        else
        {
            while (borrar->sig && borrar->sig->numorder != oderx)
                borrar = borrar->sig;

            if (!borrar->sig)
                return false;
            else
            {
                aux = borrar->sig;
                borrar->sig=borrar->sig->sig;
                delete aux;
                return true;
            }
        }
    }
}