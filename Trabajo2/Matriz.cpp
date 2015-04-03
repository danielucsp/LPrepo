#include "Matriz.h"

Matriz::Matriz()
{
    //ctor
}

Matriz::Matriz(char* filename)
{
    ifstream file;
    file.open(filename);

    string buffer, word;
    while(!file.eof())
    {
        vector<int> fila;
        getline(file, buffer);
        for(int i = 0; i < buffer.size(); i++)
            if(buffer[i] != ' ')
            {
                word.push_back(buffer[i]);
                fila.push_back(atoi(word.c_str()));
                word.clear();
            }
        tablero.push_back(fila);
    }
}

Matriz::~Matriz()
{
    //dtor
}

void Matriz::print()
{
    cout << "**************************" << endl;
    for(int i = 0; i < tablero.size(); i++)
    {
        cout << tablero.size()-1-i << " | ";
        for(int j = 0; j < tablero[i].size(); j++)
            cout << tablero[i][j] << " ";
        cout << endl;
    }

    cout << "--+";
    for(int i = 0; i < tablero[0].size()*2; i++)
        cout <<"-";
    cout << endl << "  | ";
    for(int i = 0; i < tablero[0].size(); i++)
        cout << i << " ";
    cout << endl << endl;
}

bool Matriz::tablero_vacio()
{
    for(int i = 0; i < tablero.size(); i++)
        for(int j = 0; j < tablero[i].size(); j++)
            if(tablero[i][j] != 0)
                return false;
    return true;
}

bool Matriz::repetido(vector< pair<int,int> > v, int a, int b)
{
    for(int i = 0; i < v.size(); i++)
        if(v[i].first == a && v[i].second == b)
            return true;
    return false;
}

void Matriz::encontrar_adyacencia(int x, int y)
{
    vector< pair<int,int> > adyacencias;

    pair<int,int> coor;
    int X = tablero.size()-1-x;
    coor.first = X;
    coor.second = y;

    int color = tablero[X][y];

    adyacencias.push_back(coor);

    int i = 0;
    do
    {
        if(adyacencias[i].first-1 >= 0) ///ARRIBA
        {
            if(tablero[adyacencias[i].first-1][adyacencias[i].second] == color)
            {
                if(!repetido(adyacencias, adyacencias[i].first-1, adyacencias[i].second))
                {
                    coor.first = adyacencias[i].first-1;
                    coor.second = adyacencias[i].second;
                    adyacencias.push_back(coor);
                }
            }
        }

        if(adyacencias[i].first+1 <= tablero.size()-1) ///ABAJO
        {
            if(tablero[adyacencias[i].first+1][adyacencias[i].second] == color)
            {
                if(!repetido(adyacencias, adyacencias[i].first+1, adyacencias[i].second))
                {
                    coor.first = adyacencias[i].first+1;
                    coor.second = adyacencias[i].second;
                    adyacencias.push_back(coor);
                }
            }
        }

        if(adyacencias[i].second-1 >= 0) ///IZQUIERDA
        {
            if(tablero[adyacencias[i].first][adyacencias[i].second-1] == color)
            {
                if(!repetido(adyacencias, adyacencias[i].first, adyacencias[i].second-1))
                {
                    coor.first = adyacencias[i].first;
                    coor.second = adyacencias[i].second-1;
                    adyacencias.push_back(coor);
                }
            }
        }

        if(adyacencias[i].second+1 <= tablero[X].size()-1) ///DERECHA
        {
            if(tablero[adyacencias[i].first][adyacencias[i].second+1] == color)
            {
                if(!repetido(adyacencias, adyacencias[i].first, adyacencias[i].second+1))
                {
                    coor.first = adyacencias[i].first;
                    coor.second = adyacencias[i].second+1;
                    adyacencias.push_back(coor);
                }
            }
        }

        i++;
    }
    while(i < adyacencias.size());

    /*for(int j = 0; j < adyacencias.size(); j++)
        cout << adyacencias[j].first << " " << adyacencias[j].second << endl;*/

    for(int a = 0; a < adyacencias.size(); a++)
        tablero[adyacencias[a].first][adyacencias[a].second] = 0;
}

void Matriz::gravedad()
{
    for(int i = tablero.size()-1 ; i > 0 ; i--)
    {
        for(int j = 0 ; j < tablero[i].size() ; j++)
        {
            if(tablero[i][j] == 0)
            {
                tablero[i][j] = tablero[i-1][j];
                tablero[i-1][j] = 0;
            }
        }
    }
}

void Matriz::juntar_izquierda()
{
    for(int i = 0 ; i < tablero.size() ; i++)
    {
        for(int j = 0 ; j < tablero[i].size()-1 ; j++)
        {
            if(tablero[i][j] == 0)
            {
                tablero[i][j] = tablero[i][j+1];
                tablero[i][j+1] = 0;
            }
        }
    }
}
