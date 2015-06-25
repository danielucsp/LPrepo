// Copyright (c) 2015, <your name>. All rights reserved. Use of this source code
// is governed by a BSD-style license that can be found in the LICENSE file.

import 'package:Trabajofinal/Trabajofinal.dart' as Trabajofinal;

import 'dart:io';
import 'dart:math';
import 'dart:isolate';

final int MAX = 10;
var FILA = 2000;
int COLUMNA = 2000;

class Matriz
{
  int f;
  int c;
  List< List<int> > mat;
  
  Matriz()
  {
    bool success = false;
    if(!success)
    {
      f = FILA;
      c = COLUMNA;    
      mat = new List< List<int> >();
      var rng = new Random();
      
      for (var i = 0; i < f; i++){
        List<int> list = new List<int>();
        for (var j = 0; j < c; j++){
          list.add(rng.nextInt(MAX));
        }
        mat.add(list);
      }
      success = true;
    }
    if(!success)
      throw new StateError("error!");
    
  }
  
  Matriz operator +(Matriz b)
  {
    Matriz res = new Matriz();
    res = this.suma(b);
    return res;
  }
  
  Matriz operator *(Matriz b)
  {
    Matriz res = new Matriz();
    res = this.multiplicacion(b);
    return res;
  }
  
  void imprimir()
  {
    try
    {
    for(int i = 0; i < f; i++)
    {
      for(int j = 0; j < c; j++)
        stdout.write("${mat[i][j]}\t");
      print("");
    }
    print("________________");
    }
    catch(e)
    {
      print("$e");
    }
  }
  
  Matriz suma(Matriz b)
  {
    Matriz res = new Matriz();
    
    for(int i = 0; i < this.f; i++)
      for(int j = 0; j < this.c; j++)
        res.mat[i][j] = this.mat[i][j] + b.mat[i][j];
    return res;
  }
  
  Matriz resta(Matriz b)
  {
    Matriz res = new Matriz();
    
    for(int i = 0; i < this.f; i++)
      for(int j = 0; j < this.c; j++)
        res.mat[i][j] = this.mat[i][j] - b.mat[i][j];
    return res;
  }
  
  Matriz multiplicacion(Matriz b)
  {
    try
    {
      Matriz res = new Matriz();
      for(int i = 0; i < this.f; i++)
      {
        int val = 0;
        for(int j = 0; j < b.c; j++){ 
          for(int k = 0; k < b.f; k++)
            val += this.mat[i][k] * b.mat[k][j];
          res.mat[i][j] = val;
        }
      }
      return res;
    }
    catch(e)
    {
      print(e);
    }
  }
  
  void op_escalar(int n, String c)
  {
    switch(c){
      case "+":
        for(int i = 0; i < FILA; i++)
          for(int j = 0; j < COLUMNA; j++)
            this.mat[i][j] = this.mat[i][j] + n;
        break;
      case "-":
        for(int i = 0; i < FILA; i++)
          for(int j = 0; j < COLUMNA; j++)
            this.mat[i][j] = this.mat[i][j] - n;
        break;
      case "*":
        for(int i = 0; i < FILA; i++)
          for(int j = 0; j < COLUMNA; j++)
            this.mat[i][j] = this.mat[i][j] * n;
        break;
      case "/":
        for(int i = 0; i < FILA; i++)
          for(int j = 0; j < COLUMNA; j++)
            this.mat[i][j] = this.mat[i][j] ~/ n;
        break;
    }
  }
  
  Matriz transpuesta()
  {
    Matriz tmp = new Matriz();
    for(int i = 0; i < FILA; i++)
      for(int j = 0; j < COLUMNA; j++)
        tmp.mat[i][j] = this.mat[i][j];
    
    for(int i = 0; i < FILA; i++)
      for(int j = 0; j < COLUMNA; j++)
        this.mat[i][j] = tmp.mat[j][i];
  }
}

Matriz m = new Matriz();
Matriz n = new Matriz();
Matriz o = new Matriz();

void sm1(_)
{
  for(int i = 0; i < FILA/2; i++)
    for(int j = 0; j < COLUMNA/2; j++)
      o.mat[i][j] = m.mat[i][j] + n.mat[i][j];
}

void sm2(_)
{
  for(int i = 0; i < FILA/2; i++)
    for(int j = COLUMNA~/2; j < COLUMNA; j++)
      o.mat[i][j] = m.mat[i][j] + n.mat[i][j];
}

void sm3(_)
{
  for(int i = FILA~/2; i < FILA; i++)
    for(int j = 0; j < COLUMNA/2; j++)
      o.mat[i][j] = m.mat[i][j] + n.mat[i][j];
}

void sm4(_)
{
  for(int i = FILA~/2; i < FILA; i++)
    for(int j = COLUMNA~/2; j < COLUMNA; j++)
      o.mat[i][j] = m.mat[i][j] + n.mat[i][j];
}

void suma_paralelo()
{
  Isolate.spawn(sm1, null);
  Isolate.spawn(sm2, null);
  Isolate.spawn(sm3, null);
  Isolate.spawn(sm4, null);
}

main(List<String> arguments) {
  
  Stopwatch cr1 = new Stopwatch()..start();
  o = m.suma(n);
  cr1..stop();
  print("${cr1.elapsedMilliseconds}");
  
  Stopwatch cr = new Stopwatch()..start();
  suma_paralelo();
  cr..stop();
  print("${cr.elapsedMilliseconds}");
  
  /*m.imprimir();
  m.op_escalar(4, "*");
  m.imprimir();*/
  
  /*m.imprimir();
  n.imprimir();
  o = m * n;
  o.imprimir();*/
  
}
