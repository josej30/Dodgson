#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include "limits.h"
#include "nodo.h"

using std::string;
using std::vector;

int bitsCand(int);
int buscaCand(string,vector<string>);
int N(int,int,vector<int>);
bool condorIndiv(int,vector< vector<int> >,vector<string>);
vector<int> condorcet(vector< vector<int> >, vector<string>);
bool existe(vector<int>, int);
vector<int> permuta(int, int, vector<int>);
void sust(vector<Nodo>, vector<vector <int> >);
bool repetidos(Nodo, Nodo);
float heuristica(Nodo nodo, int n, vector<string> cand);
float T_prima(int x, vector<int> cand, int n, Nodo nodo);
float T(int x, vector <int> cand,int n, Nodo nodo);
