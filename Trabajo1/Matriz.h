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
    vector< vector<string> > horario;
    public:
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

        int hora_a_minuto(string hora)
        {
            int minuto = 0;
            string n;
            int i;
            for(i = 0; hora[i] != ':'; i++)
                n.push_back(hora[i]);
            int tmp = atoi(n.c_str());
            tmp = tmp * 60;
            minuto = minuto + tmp;

            n.clear();

            i++;
            for(; i < hora.size(); i++)
                n.push_back(hora[i]);
            tmp = atoi(n.c_str());
            minuto = minuto + tmp;

            return minuto;
        }

        string minuto_a_hora(int minuto)
        {
            int h = minuto / 60;
            int m = minuto % 60;
            string hora;

            stringstream ssh;
            stringstream ssm;
            ssh << h;
            ssm << m;
            string ho = ssh.str();
            string mi = ssm.str();

            hora = ho + ":" + mi;
            return hora;
        }
    protected:
    private:
};

#endif // MATRIZ_H
