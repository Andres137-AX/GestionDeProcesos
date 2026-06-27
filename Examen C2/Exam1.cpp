#include <iostream>
#include <string>
using namespace std;

struct Proceso
{
    int id;
    string nombre;
    Proceso *siguiente;
};

Proceso *topePila = NULL;
Proceso *finalCola = NULL;

// La función devuelve el nuevo tope de la pila
Proceso *insertarPila(int id, string nombre, Proceso *actualTope)
{
    Proceso *nuevo = new Proceso{id, nombre, actualTope};
    return nuevo;
}

// La función devuelve el nuevo final de la cola
Proceso *insertarCola(int id, string nombre, Proceso *actualFinal)
{
    Proceso *nuevo = new Proceso{id, nombre, NULL};
    if (actualFinal != NULL)
    {
        actualFinal->siguiente = nuevo;
    }
    return nuevo;
}