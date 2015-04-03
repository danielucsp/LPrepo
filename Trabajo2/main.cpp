#include <iostream>
#include "Matriz.h"

using namespace std;

void game(Matriz tablero)
{
    tablero.gravedad();
    tablero.juntar_izquierda();
    while(!tablero.tablero_vacio())
    {
        int x,y;
        tablero.print();
        cin >> x >> y;
        tablero.encontrar_adyacencia(x,y);
        tablero.gravedad();
        tablero.juntar_izquierda();
    }

    tablero.print();
    cout << "-------- FIN!!!!!! --------" << endl;
}

int main()
{
    Matriz a("a.txt");
    /*a.print();
    a.encontrar_adyacencia(0,0);
    a.print();
    a.gravedad();
    a.print();
    a.juntar_izquierda();
    a.print();*/
    game(a);
    return 0;
}
