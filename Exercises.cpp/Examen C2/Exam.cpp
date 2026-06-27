#include <iostream>
#include <string>
using namespace std;

// Estructura básica del proceso
struct Proceso
{
    int id;
    string nombre;
    Proceso *siguiente;
};

// Punteros para Pila y Cola
Proceso *topePila = NULL;
Proceso *finalCola = NULL;

// Inserción en Pila (LIFO) - Complejidad O(1)
void insertarPila(int id, string nombre)
{
    Proceso *nuevo = new Proceso{id, nombre, topePila};
    topePila = nuevo;
}

// Inserción en Cola (FIFO) - Complejidad O(1)
void insertarCola(int id, string nombre)
{
    Proceso *nuevo = new Proceso{id, nombre, NULL};
    if (finalCola == NULL)
        finalCola = nuevo;
    else
    {
        // Lógica simplificada de encolado
        finalCola->siguiente = nuevo;
        finalCola = nuevo;
    }
}