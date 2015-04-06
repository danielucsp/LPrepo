#include <iostream>
#include "Matriz.h"

using namespace std;

bool game(Matriz tablero)
{
    int x,y;
    x = 0;
    y = 0;
    while(!tablero.tablero_vacio())
    {
        tablero.print();
        if(tablero.fin())
        {
            cout << "----NO SE PUEDEN ELIMINAR MAS BLOQUES----" << endl;
            cout << "--------------FIN DEL JUEGO--------------" << endl;
            return false;
        }
        if(tablero.tablero[x][y] == 0)
            y++;
        tablero.encontrar_adyacencia(x,y);
        tablero.gravedad();
        tablero.juntar_izquierda();
        if(y == (tablero.tablero[x]).size()-1)
        {
            x++;
            y = 0;
        }
        if(y == (tablero.tablero[x]).size()-1 && x == 0)
        {
            x = (tablero.tablero).size()-1;
            y = 0;
        }
    }
    tablero.print();
    cout << "-------- FIN!!!!!! --------" << endl;
    return true;
}


/*bool game(Matriz tablero)
{
    tablero.gravedad();
    tablero.juntar_izquierda();
    while(!tablero.tablero_vacio())
    {
        int x,y;
        tablero.print();
        if(tablero.fin())
        {
            cout << "----NO SE PUEDEN ELIMINAR MAS BLOQUES----" << endl;
            cout << "--------------FIN DEL JUEGO--------------" << endl;
            return false;
        }
        cin >> x >> y;
        tablero.encontrar_adyacencia(x,y);
        tablero.gravedad();
        tablero.juntar_izquierda();
    }

    tablero.print();
    cout << "-------- FIN!!!!!! --------" << endl;
    return true;
}*/


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
