#include <iostream>
using namespace std;

// Definir el tamaño máximo de la pila
#define MAX 5

// Crear un arreglo para representar la pila
int pila[MAX];
int tope = -1; // El índice del "tope" de la pila (inicialmente vacío)

// Función para insertar un elemento en la pila
void insertar(int dato)
{
    if (tope == MAX - 1)
    { // Verifica si la pila está llena
        cout << "La pila está llena. No se puede insertar más elementos." << endl;
    }
    else
    {
        tope++;            // Aumenta el índice del tope
        pila[tope] = dato; // Inserta el elemento en la pila
        cout << "Elemento " << dato << " insertado." << endl;
    }
}

// Función para eliminar el elemento superior de la pila
void eliminar()
{
    if (tope == -1)
    { // Verifica si la pila está vacía
        cout << "La pila está vacía. No se puede hacer eliminar." << endl;
    }
    else
    {
        cout << "Elemento " << pila[tope] << " eliminado." << endl;
        tope--; // Disminuye el índice del tope
    }
}

// Función para ver el elemento superior de la pila sin eliminarlo
int cima()
{
    if (tope == -1)
    {
        cout << "La pila está vacía." << endl;
        return -1; // Retorna un valor indicativo de que la pila está vacía
    }
    return pila[tope];
}

// Función para verificar si la pila está vacía
bool estavacia()
{
    return tope == -1; // Si tope es -1, la pila está vacía
}

// Función para imprimir los elementos de la pila
void imprimir()
{
    if (estavacia())
    {
        cout << "La pila está vacía." << endl;
    }
    else
    {
        cout << "Contenido de la pila (de cima a base): ";
        for (int i = tope; i >= 0; i--)
        {
            cout << pila[i] << " ";
        }
        cout << endl;
    }
}

// Función principal
int main()
{
    setlocale(LC_CTYPE, "Spanish");
    int n, dato;

    cout << "¿Cuántos elementos quieres insertar en la pila? ";
    cin >> n; // Ingreso de la cantidad de elementos

    // Comprobar que no se inserten más elementos de los que permite la pila
    if (n > MAX)
    {
        cout << "No puedes insertar más de " << MAX << " elementos." << endl;
        return 1; // Salir del programa si excede el límite
    }

    // Insertar los elementos proporcionados por el usuario
    for (int i = 0; i < n; i++)
    {
        cout << "Ingresa el elemento #" << i + 1 << ": ";
        cin >> dato;    // Ingreso de un dato por el usuario
        insertar(dato); // Insertar el dato en la pila
    }

    // Imprimir los elementos de la pila
    imprimir();

    // Mostrar el elemento superior de la pila
    cout << "Elemento superior: " << cima() << endl;

    // Eliminar los dos elementos superiores de la pila
    eliminar();
    eliminar();

    // Imprimir los elementos restantes de la pila
    imprimir();

    return 0;
}