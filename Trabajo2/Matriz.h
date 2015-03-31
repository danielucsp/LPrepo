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
        vector< vector<string> > tablero;

        Matriz();
        Matriz(char* filename);

        virtual ~Matriz();

        void print();

    protected:
    private:
};
#endif // MATRIZ_H
