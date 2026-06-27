#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int vector[5];
    for (int i = 0; i <= 4; i += 1)
    {
        cout << "Hello user, introduce un valor\n";
        cin >> vector[i];
    }

    cout << "\n\n";

    cout << "---Horizontalmente---\n";
    for (int i = 0; i <= 4; i += 1)
    {
        cout << vector[i] << " ";
    }

    cout << "\n\n";

    cout << "---Verticalmente---\n";
    for (int i = 0; i <= 4; i += 1)
    {
        cout << vector[i] << "\n";
    }

    return 0;
}