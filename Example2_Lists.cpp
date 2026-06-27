#include <iostream>
using namespace std;

// Definimos la estructura nodo
struct nodito
{
    int dato;          // El dato que vamos a almacenar (en este caso, un número entero)
    nodito *siguiente; // Puntero al siguiente nodito

    // Constructor para inicializar los valores
    nodito(int valor)
    {
        dato = valor;
        siguiente = NULL; // Inicializamos el puntero siguiente como NULL
    }
};

// Función para agregar un nodito al final de la lista
void agregarAlFinal(nodito *&inicio, int valor)
{
    nodito *nuevonodito = new nodito(valor); // Creamos un nuevo nodito con el valor

    if (inicio == NULL)
    { // Si la lista está vacía, el nuevo nodito será el inicio
        inicio = nuevonodito;
    }
    else
    {
        nodito *temp = inicio; // Usamos un puntero temporal para recorrer la lista
        while (temp->siguiente != NULL)
        { // Buscamos el último nodito
            temp = temp->siguiente;
        }
        temp->siguiente = nuevonodito; // Enlazamos el último nodito con el nuevo
    }
}

// Función para imprimir la lista
void imprimirLista(nodito *inicio)
{
    nodito *temp = inicio;
    while (temp != NULL)
    {                              // Mientras haya noditos, seguimos recorriendo
        cout << temp->dato << " "; // Imprimimos el dato del nodito
        temp = temp->siguiente;    // Avanzamos al siguiente nodito
    }
    cout << endl;
}

int main()
{
    nodito *inicio = NULL; // La lista comienza vacía (NULL en vez de nullptr)
    int numeroDeElementos, valor;

    // Pedimos al usuario cuántos elementos desea agregar a la lista
    cout << "¿Cuántos elementos deseas agregar a la lista? ";
    cin >> numeroDeElementos;

    // Ingresamos los elementos uno por uno
    for (int i = 0; i < numeroDeElementos; i++)
    {
        cout << "Ingresa el valor para el nodito " << i + 1 << ": ";
        cin >> valor;
        agregarAlFinal(inicio, valor); // Llamamos a la función para agregar el valor
    }

    // Imprimimos la lista enlazada
    cout << "Lista Enlazada Resultante: ";
    imprimirLista(inicio);

    return 0;
}