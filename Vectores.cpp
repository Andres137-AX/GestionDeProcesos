
#include <iostream>
using namespace std;

int main()
{
    int vector[5];

    for (int i = 0; i < 5; i = i + 1)
    {
        cout << "Hello user, introduce un valor\n";
        cin >> vector[i];
    }

    cout << "\n\n";

    for (int i = 0; i < 5; i = i + 1)
    {
        cout << vector[i] << " "; /*Horizontalmente*/
    }

    cout << "\n\n";

    for (int i = 0; i < 5; i = i + 1)
    {
        cout << vector[i] << "\n"; /*Verticalmente*/
    }
    return 0;
}