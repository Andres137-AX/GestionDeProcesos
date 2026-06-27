/*. Escribe un programa que defina un vector de numeros y calcule el producto de sus elementos */

#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int numeros[] = {1, 2, 3, 4};
    int producto = 1;

    for (int i = 0; i < 4; i++)
    {
        producto = producto * numeros[i];
    }

    cout << "La producto de los elementos del vector es: " << producto << endl;

    getch();
    return 0;
}
