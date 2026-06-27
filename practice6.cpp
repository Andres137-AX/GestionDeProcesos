
#include <iostream>
#include <cstring> // Para las funciones de cadenas (strlen, strcpy, strcat, strstr)
#include <clocale> // Para setlocale
using namespace std;

void ingresarFrase(char frase[], int size)
{
    cout << "Ingrese una frase: ";
    cin.getline(frase, size); // Usamos getline para permitir espacios
}

void copiarFrase(char copia[], char original[])
{
    strcpy(copia, original); // Copiamos la frase original a 'copia'
    cout << "\nFrase copiada: " << copia << endl;
}

void concatenarFrase(char frase[], char mensaje[])
{
    strcat(frase, mensaje); // Concatenamos el mensaje al final de la frase original
    cout << "\nFrase después de concatenar: " << frase << endl;
}

void calcularLongitud(char frase[])
{
    int longitud = strlen(frase); // Calculamos la longitud de la frase
    cout << "\nLongitud de la frase: " << longitud << endl;
}

void buscarPalabra(char frase[], char palabra[])
{
    if (strstr(frase, palabra) != NULL)
    {
        cout << "\nLa palabra '" << palabra << "' está presente en la frase." << endl;
    }
    else
    {
        cout << "\nLa palabra '" << palabra << "' no está presente en la frase." << endl;
    }
}

int main()
{
    setlocale(LC_CTYPE, "Spanish");
    const int MAX_SIZE = 200;             // Tamaño máximo para las cadenas
    char frase[MAX_SIZE];                 // Arreglo para almacenar la frase
    char fraseCopia[MAX_SIZE];            // Arreglo para almacenar la copia de la frase
    char mensaje[] = " Aprendiendo C++!"; // Mensaje para concatenar (con espacio al inicio)

    int opcion;
    bool fraseIngresada = false; // Controla si la frase fue ingresada

    do
    {
        // Menú de opciones
        cout << "\n--- Menu de Opciones ---\n";
        cout << "1. Ingresar una frase\n";
        cout << "2. Copiar la frase a otra variable\n";
        cout << "3. Concatenar un mensaje adicional a la frase\n";
        cout << "4. Calcular la longitud de la frase\n";
        cout << "5. Buscar la palabra 'código' en la frase\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer para evitar problemas con getline()

        switch (opcion)
        {
        case 1:
            ingresarFrase(frase, MAX_SIZE);
            fraseIngresada = true; // Indicamos que la frase ha sido ingresada
            break;
        case 2:
            if (fraseIngresada)
            {
                copiarFrase(fraseCopia, frase);
            }
            else
            {
                cout << "\nPrimero debes ingresar una frase." << endl;
            }
            break;
        case 3:
            if (fraseIngresada)
            {
                concatenarFrase(frase, mensaje);
            }
            else
            {
                cout << "\nPrimero debes ingresar una frase." << endl;
            }
            break;
        case 4:
            if (fraseIngresada)
            {
                calcularLongitud(frase);
            }
            else
            {
                cout << "\nPrimero debes ingresar una frase." << endl;
            }
            break;
        case 5:
            if (fraseIngresada)
            {
                buscarPalabra(frase, "código");
            }
            else
            {
                cout << "\nPrimero debes ingresar una frase." << endl;
            }
            break;
        case 6:
            cout << "\n¡Gracias por usar el programa! Hasta luego." << endl;
            break;
        default:
            cout << "\nOpción no válida. Intente de nuevo." << endl;
            break;
        }
    } while (opcion != 6); // El programa sigue ejecutándose hasta que el usuario elija salir

    return 0;
}