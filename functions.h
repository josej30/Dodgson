#include <vector>
#include <string>
#include "nodo.h"

using std::string;
using std::vector;

int bitsCand(int);
int buscaCand(string,vector<string>);
int N(int,int,vector<int>);
bool condorIndiv(int,vector< vector<int> >,vector<string>);
int condorcet(vector< vector<int> >, vector<string>);
bool existe(vector<int>, int);
vector<int> permuta(int, int, vector<int>);
void sust(vector<Nodo>, vector<vector <int> >);
bool repetidos(Nodo, Nodo);
