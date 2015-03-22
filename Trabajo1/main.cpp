#include <iostream>
#include <vector>
#include "Matriz.h"

#define DIAS 5
using namespace std;

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

    if(m == 0)
        hora = ho + ":" + mi + "0";
    else
        hora = ho + ":" + mi;
    return hora;
}

pair<int, int> rango(string hora)
{
    pair<int,int> res;
    string rango;
    int i;
    for(i = 0; hora[i] != '-'; i++)
        rango.push_back(hora[i]);

    res.first = hora_a_minuto(rango);
    rango.clear();
    i++;

    for(; i < hora.size(); i++)
        rango.push_back(hora[i]);

    res.second = hora_a_minuto(rango);

    return res;
}

void llenar_vacios(vector< vector< pair<int,int> > > &v)
{
    int maxx = v[0].size();

    for(int i = 1; i < v.size(); i++)
        if(v[i].size() > maxx)
            maxx = v[i].size();

    for(int i = 0; i < v.size(); i++)
    {
        while(v[i].size() != maxx)
        {
            pair<int,int> t;
            t.first = -1;
            t.second = -1;
            v[i].push_back(t);
        }
    }
}

int encontrar_pos_dia(Matriz m, string d)
{
    for(int i = 0; i < DIAS; i++)
        if(m.horario[i][0] == d)
            return i;
    return -1;
}

vector< vector<string> > encontrar_tiempo(vector<Matriz> h)
{

}

int main()
{
    Matriz a("aa.txt");
    Matriz b("bb.txt");
    //Matriz c("c.txt");

    vector<Matriz> horarios;
    horarios.push_back(a);
    horarios.push_back(b);
    //horarios.push_back(c);

    vector< vector<string> > res;

    res = encontrar_tiempo(horarios);

    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
}
