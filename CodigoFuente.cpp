#include <iostream>
#include <cstring>

using namespace std;

// ================================
// PASO 1: REGISTRO DEL ESTUDIANTE
// ================================
struct Estudiante
{
    char nombre[60];
    char direccion[80];
    char contacto[50];
    char programaAcademico[50];
    int creditosCursados;
    float promedioCalificaciones;
};

// =================================
// PASO 2: PROTOTIPOS DE FUNCIONES
// =================================
void registrarEstudiante(Estudiante &est);
void mostrarEstudiantes(const Estudiante *lista, int cantidad);
void buscarEstudiante(Estudiante lista[], int cantidad);

// FUNCIÓN PRINCIPAL
int main()
{
    setlocale(LC_CTYPE, "Spanish");

    int const MAX_ESTUDIANTES = 100;
    Estudiante listaEstudiantes[MAX_ESTUDIANTES];
    int cantidadActual = 0;
    int opcion;

    do
    {
        cout << "\n=== SISTEMA DE GESTION - UNIVERSIDAD CONTINENTAL ===\n";
        cout << "1. Registrar nuevo estudiante\n";
        cout << "2. Mostrar todos los estudiantes\n";
        cout << "3. Buscar estudiante por nombre\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            if (cantidadActual < MAX_ESTUDIANTES)
            {
                registrarEstudiante(listaEstudiantes[cantidadActual]);
                cantidadActual++;
            }
            else
            {
                cout << "Memoria llena. No se pueden registrar mas estudiantes.\n";
            }
            break;
        case 2:
            if (cantidadActual > 0)
            {
                mostrarEstudiantes(listaEstudiantes, cantidadActual);
            }
            else
            {
                cout << "No hay estudiantes registrados aun.\n";
            }
            break;
        case 3:
            if (cantidadActual > 0)
            {
                buscarEstudiante(listaEstudiantes, cantidadActual);
            }
            else
            {
                cout << "No hay estudiantes registrados aun para buscar.\n";
            }
            break;
        case 4:
            cout << "Saliendo del sistema... ¡Exitos en la Universidad Continental!\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}

// ============================
// PASO 3: FUNCION DE REGISTRO
// ============================
void registrarEstudiante(Estudiante &est)
{
    cout << "\n--- Registro de Nuevo Estudiante ---\n";

    cin.ignore();

    cout << "Nombre completo: ";
    cin.getline(est.nombre, 60);

    cout << "Direccion: ";
    cin.getline(est.direccion, 80);

    cout << "Contacto (Email o Telefono): ";
    cin.getline(est.contacto, 50);

    cout << "Programa Academico (Ej. Ingenieria de Sistemas): ";
    cin.getline(est.programaAcademico, 50);

    cout << "Creditos Cursados: ";
    cin >> est.creditosCursados;

    cout << "Promedio de Calificaciones: ";
    cin >> est.promedioCalificaciones;

    cout << "¡Estudiante registrado con exito en la Universidad Continental!\n";
}

// ===============================================
// PARTE 4: FUNCIONES DE VISUALIZACION Y BUSQUEDA
// ===============================================

void mostrarEstudiantes(const Estudiante *lista, int cantidad)
{
    cout << "\n--- Lista de Estudiantes Matriculados ---\n";
    for (int i = 0; i < cantidad; i++)
    {
        cout << i + 1 << ". Nombre: " << lista[i].nombre
             << " | Programa: " << lista[i].programaAcademico
             << " | Promedio: " << lista[i].promedioCalificaciones << "\n";
    }
}

void buscarEstudiante(Estudiante lista[], int cantidad)
{
    char nombreBuscado[60];
    bool encontrado = false;

    cout << "\n--- Busqueda de Estudiante ---\n";
    cout << "Ingrese el nombre (o parte del nombre) a buscar: ";
    cin.ignore();
    cin.getline(nombreBuscado, 60);

    for (int i = 0; i < cantidad; i++)
    {
        if (strstr(lista[i].nombre, nombreBuscado) != NULL)
        {
            cout << "\n¡Estudiante Encontrado!\n";
            cout << "Nombre: " << lista[i].nombre << "\n";
            cout << "[Dato extra] La longitud del nombre es de " << strlen(lista[i].nombre) << " caracteres.\n";
            cout << "Contacto: " << lista[i].contacto << "\n";
            cout << "Programa: " << lista[i].programaAcademico << "\n";
            encontrado = true;
        }
    }

    if (!encontrado)
    {
        cout << "No se encontro ningun estudiante con ese nombre en la base de datos.\n";
    }
}