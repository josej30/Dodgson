#include <vector>
#include <iostream>

typedef std::vector<int> Pref;
typedef std::vector<Pref> MatPref;

using namespace std;

class Nodo{

 public:
  //Nodo(vector< vector <int> >);
  MatPref perfil; /* Matriz que representa las preferencias */
  void insertar(vector<int>); /* Inserta una preferencia a la matriz */ 
  void mostrar(); /* Muestra un preferencia*/


};
