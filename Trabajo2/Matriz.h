#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

class Matriz
{
    public:
        vector< vector<int> > tablero;

        Matriz();
        Matriz(char* filename);

        virtual ~Matriz();

        void print();
        bool tablero_vacio();
        bool repetido(vector< pair<int,int> > v, int a, int b);
        bool fin();

        void encontrar_adyacencia(int x, int y);
        void gravedad();
        void juntar_izquierda();

    protected:
    private:
};
#endif // MATRIZ_H
