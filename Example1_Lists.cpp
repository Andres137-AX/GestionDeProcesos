#include <iostream>
using namespace std;

// Definimos la estructura Nodo
struct Nodo
{
    int dato;        // El dato que vamos a almacenar (en este caso, un número entero)
    Nodo *siguiente; // Puntero al siguiente nodo

    // Constructor para inicializar los valores
    Nodo(int valor)
    {
        dato = valor;
        siguiente = NULL;
    }
};

// Función para agregar un nodo al final de la lista
void agregarAlFinal(Nodo *&inicio, int valor)
{
    Nodo *nuevoNodo = new Nodo(valor); // Creamos un nuevo nodo con el valor

    if (inicio == NULL)
    { // Si la lista está vacía, el nuevo nodo será el inicio
        inicio = nuevoNodo;
    }
    else
    {
        Nodo *temp = inicio; // Usamos un puntero temporal para recorrer la lista
        while (temp->siguiente != NULL)
        { // Buscamos el último nodo
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo; // Enlazamos el último nodo con el nuevo
    }
}

// Función para imprimir la lista
void imprimirLista(Nodo *inicio)
{
    Nodo *temp = inicio;
    while (temp != NULL)
    {                              // Mientras haya nodos, seguimos recorriendo
        cout << temp->dato << " "; // Imprimimos el dato del nodo
        temp = temp->siguiente;    // Avanzamos al siguiente nodo
    }
    cout << endl;
}

int main()
{
    Nodo *inicio = NULL; // La lista comienza vacía (NULL en vez de nullptr)

    // Agregamos algunos nodos a la lista
    agregarAlFinal(inicio, 10);
    agregarAlFinal(inicio, 20);
    agregarAlFinal(inicio, 30);

    // Imprimimos la lista
    cout << "Lista Enlazada Simple: ";
    imprimirLista(inicio);

    return 0;
}