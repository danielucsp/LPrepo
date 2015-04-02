#include <iostream>
#include "Matriz.h"

using namespace std;

int main()
{
    Matriz a("a.txt");
    a.print();
    a.encontrar_adyacencia(0,0);
    a.print();
    return 0;
}
