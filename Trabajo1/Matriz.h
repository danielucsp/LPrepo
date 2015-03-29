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
        vector< vector<string> > horario;
        Matriz(){}
        Matriz (vector< vector<string> > h){
            horario = h;
        }
        Matriz(char* filename)
        {
            ifstream file;
            file.open(filename);

            string buffer, word;
            while(!file.eof())
            {
                getline(file, buffer);

                istringstream iss(buffer);
                vector<string> dia;
                while(iss >> word)
                    dia.push_back(word);
                horario.push_back(dia);
            }

            /*for(int i = 0; i < horario.size(); i++)
            {
                for(int j = 0; j < horario[i].size(); j++)
                    cout << horario[i][j] << " ";
                cout << endl;
            }*/
        }
        virtual ~Matriz(){}

        bool buscar_dia(string d)
        {
            for(int i = 0; i < horario.size(); i++)
                if(horario[i][0] == d)
                    return true;
            return false;
        }

    protected:
    private:
};

#endif // MATRIZ_H
