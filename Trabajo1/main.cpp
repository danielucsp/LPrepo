#include <iostream>
#include <vector>
#include "Matriz.h"
using namespace std;

vector< vector<string> > encontrar_tiempo(vector<Matriz> h)
{
    vector< vector<string> > res;

    vector<string> dias;
    dias.push_back("mon");
    dias.push_back("tue");
    dias.push_back("wed");
    dias.push_back("thu");
    dias.push_back("fri");

    int cont = 0;

    for(int a = 0; a < dias.size(); a++)
    {
        for(int i = 0; i < h.size(); i++)
            if(h[i].buscar_dia(dias[a]))
                cont++;

        if(cont == h.size())
        {
            cont = 0;
            //CODIGO DE INTERSECCION
        }
        else
        {
            cont = 0;
            continue;
        }
        break;
    }

    return res;
}

int main()
{
    Matriz a("a.txt");
    Matriz b("b.txt");

    vector<Matriz> horarios;
    horarios.push_back(a);
    horarios.push_back(b);

    vector< vector<string> > res;

    res = encontrar_tiempo(horarios);

    return 0;
}
