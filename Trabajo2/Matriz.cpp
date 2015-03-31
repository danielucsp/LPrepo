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
        vector<string> fila;
        getline(file, buffer);
        for(int i = 0; i < buffer.size(); i++)
            if(buffer[i] != ' ')
            {
                word.push_back(buffer[i]);
                fila.push_back(word);
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
    for(int i = 0; i < tablero.size(); i++)
    {
        for(int j = 0; j < tablero[i].size(); j++)
            cout << tablero[i][j] << " ";
        cout << endl;
    }
}
