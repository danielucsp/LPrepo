#include <iostream>
#include "Matriz.h"
using namespace std;

int main()
{
    Matriz a("a.txt");
    int w = a.hora_a_minuto("23:55");
    cout << w;
    string x = a.minuto_a_hora(1435);
    cout << x;
    return 0;
}
