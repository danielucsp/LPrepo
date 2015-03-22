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

        pair<int, int> rango(string hora)
        {
            pair<int, int> res;
            string rango;
            int i;
            for(i = 0; hora[i] != '-'; i++)
                rango.push_back(hora[i]);

            res.first = hora_a_minuto(rango);
            rango.clear();
            i++;

            for(i = 0; i < hora.size(); i++)
                rango.push_back(hora[i]);

            res.second = hora_a_minuto(rango);

            return res;
        }

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
