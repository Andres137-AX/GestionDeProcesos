#include <iostream>
using namespace std;

// Definir el tamaño máximo de la cola
#define MAX 5

// Crear un arreglo para representar la cola
int cola[MAX];
int frente = -1; // El índice del frente de la cola
int final = -1;  // El índice del final de la cola

// Función para verificar si la cola está vacía
bool estaVacia()
{
    return frente == -1; // Si el frente es -1, la cola está vacía
}

// Función para verificar si la cola está llena
bool estaLlena()
{
    return final == MAX - 1; // Si el final es el último índice, la cola está llena
}

// Función para encolar (insertar un elemento)
void encolar(int dato)
{
    if (estaLlena())
    {
        cout << "La cola está llena. No se puede insertar más elementos." << endl;
    }
    else
    {
        if (frente == -1)
        { // Si la cola está vacía, el primer elemento se inserta
            frente = 0;
        }
        final++;            // Aumenta el índice del final
        cola[final] = dato; // Inserta el elemento en la cola
        cout << "Elemento " << dato << " encolado." << endl;
    }
}

// Función para desencolar (eliminar el primer elemento)
void desencolar()
{
    if (estaVacia())
    {
        cout << "La cola está vacía. No se puede hacer desencolar." << endl;
    }
    else
    {
        cout << "Elemento " << cola[frente] << " desencolado." << endl;
        frente++; // Mueve el frente de la cola

        if (frente > final)
        { // Si la cola se vacía, reinicia los índices
            frente = final = -1;
        }
    }
}

// Función para ver el primer elemento (frente de la cola) sin eliminarlo
int frenteCola()
{
    if (estaVacia())
    {
        cout << "La cola está vacía." << endl;
        return -1; // Retorna un valor indicativo de que la cola está vacía
    }
    return cola[frente];
}

// Función para imprimir los elementos de la cola
void imprimir()
{
    if (estaVacia())
    {
        cout << "La cola está vacía." << endl;
    }
    else
    {
        cout << "Contenido de la cola (de frente a final): ";
        for (int i = frente; i <= final; i++)
        {
            cout << cola[i] << " ";
        }
        cout << endl;
    }
}

// Función principal
int main()
{
    encolar(10); // Encolar 10
    encolar(20); // Encolar 20
    encolar(30); // Encolar 30
    encolar(40); // Encolar 40
    encolar(50); // Encolar 50
    encolar(60); // Intentar encolar 60, pero la cola está llena

    imprimir(); // Imprimir los elementos de la cola

    cout << "Elemento en el frente de la cola: " << frenteCola() << endl; // Mostrar el primer elemento

    desencolar(); // Desencolar el primer elemento
    desencolar(); // Desencolar el siguiente elemento

    imprimir(); // Imprimir los elementos restantes de la cola

    return 0;
}