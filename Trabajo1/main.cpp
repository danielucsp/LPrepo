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

vector< vector<string> > encontrar_tiempo(vector<Matriz> h, int minutos)
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
            vector<string> r;
            r.push_back(dias[a]);
            res.push_back(r);

            vector< vector< pair<int,int> > > eval;
            int aa;

            for(int i = 0; i < h.size(); i++)
            {
                vector< pair<int,int> > tmp;
                aa = encontrar_pos_dia(h[i], dias[a]);

                for(int j = 1; j < h[i].horario[aa].size(); j++)
                {
                    pair<int,int> tm;
                    tm = rango(h[i].horario[aa][j]);
                    tmp.push_back(tm);
                }

                eval.push_back(tmp);
            }


            llenar_vacios(eval);

            for(int i = 0; i < eval[0].size() && eval[0][i].first != -1 && eval[0][i].second != -1; i++)
            {
                pair<int,int> interseccion = eval[0][i];
                //cout << interseccion.first << " " << interseccion.second << endl;

                for(int j = 0; j < eval[0].size(); j++)
                {
                    interseccion = eval[0][i];
                    for(int k = 1; k < eval.size(); k++)
                    {
                        if(eval[k][j].first != -1 && eval[k][j].second != -1)
                        {
                            if(eval[k][j].first >= interseccion.first)
                                interseccion.first = eval[k][j].first;

                            if(eval[k][j].second <= interseccion.second)
                                interseccion.second = eval[k][j].second;

                            if(interseccion.first < interseccion.second && abs(interseccion.first - interseccion.second) >= minutos)
                            {
                                string h1 = minuto_a_hora(interseccion.first);
                                string h2 = minuto_a_hora(interseccion.second);
                                string inter = h1 + "-" + h2;

                                res[res.size()-1].push_back(inter);
                            }
                        }
                    }
                }
             }
        }
        else
        {
            cont = 0;
            continue;
        }
        //break;
    }

    return res;
}

void planificador (vector<Matriz> horarios, int tiempo){

    if(horarios.size()==2){
      vector< vector<string> > res;
      res = encontrar_tiempo(horarios, tiempo);
      for(int i = 0; i < res.size(); i++)
      {
         for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
            cout << endl;
      }
    }
    else{
        vector< pair <Matriz,Matriz> > para_proc;
        vector< vector<string> > res;
        int tam = 0;
        while(tam<horarios.size()){

             pair <Matriz, Matriz> par_matriz;
             Matriz a = horarios[tam];
             par_matriz.first = a;
             if(tam==horarios.size()-1){
                par_matriz.second = horarios[0];
             }
             else{
                par_matriz.second = horarios[tam+1];
             }

             para_proc.push_back(par_matriz);
             tam++;
        }
        vector <Matriz> schedules;
        for(int i=0; i<para_proc.size()-1; i++){
            vector<Matriz> h;
            pair<Matriz, Matriz> par_hor = para_proc[i];
            h.push_back(par_hor.first);
            h.push_back(par_hor.second);
            res= encontrar_tiempo(h,tiempo);
            Matriz m_horario(res);
            schedules.push_back(m_horario);
        }
        //cout<<schedules.size()<<endl;
        if(schedules.size()>= 2){
           planificador(schedules,tiempo);
        }
    }
}



int main()
{
    int tiempo = 45;
    Matriz a("aa.txt");
    Matriz b("bb.txt");
    Matriz c("c.txt");
    vector<Matriz> horarios;
    horarios.push_back(a);
    horarios.push_back(b);
    horarios.push_back(c);
    planificador(horarios, tiempo);
    return 0;
}
