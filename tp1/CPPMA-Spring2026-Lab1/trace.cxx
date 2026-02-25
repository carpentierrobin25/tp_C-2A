/// Code élémentaire pour le calcul de la trace d'une matrice.
/// Printemps 2026
/// Objectif : manipuler les éléments de base du C++
///            utiliser des outils de profiling et de débogage
/// ref: l'exercice est inspiré très largement de ressources WWW

#include <cmath>
#include <cstdlib>
#include <iostream>

double **initialization(int);
double *fill_vectors(double *, int);
void print_matrix(double **, int);
double trace(double **, int);
void libere(double **, int);
double *initialization_vect(int);
void libere_vect(double *,int);
void affiche_vect(double *, int);
template <typename TFunc>
double *resolution(int, double, double, double, TFunc);
using std::cout;
using std::endl;
using std::flush;
using std::cin;

/// Driver principal pour le calcul de la tace d'une matrice
int main() {
  int i, n;
  double **matrix;
  double sum;

  cout << endl << "Enter the Dimension for a square matrix: " << flush;
  cin >> n;
  matrix = initialization(n);
  for (i = 1; i < n; i++)
    matrix[i] = fill_vectors(matrix[i], n);
  sum = trace(matrix, n);
  print_matrix(matrix, n);
  libere(matrix, n);
  cout << endl << "Sum of the diagonal elements are: " << sum;
  double *vect = resolution(100, 0.005, 0, 1, [](double x, double y) {return 2*x*y;});
  affiche_vect(vect, 100);
  libere_vect(vect, 100);
  return 0;
}

/// @brief Routine d'initialization qui permet d'allouer la mémoire pour une
///        matrice carrée de taille n et renvoie un pointer vers
///        la matrice allouée
/// @param[in] n est la taille souhaitée de la matrice
/// @return    Renvoie le pointeur vers la matrice allouée
double **initialization(int n) {
  int i;
  double **matrix;
  matrix = new double*[n]();;
  for (i = 0; i < n; ++i)
    matrix[i] = new double[n]();
  return matrix;
}


/// @brief Intitialise un vecteur avec des valeurs aléatoires comprises
///        entre dans l'intervalle [-10;10]
/// @param[in] vec est le vecteur à initialiser
/// @param[in] n   est la taille du vecteur à initialiser
/// @return    Renvoie le vecteur initialisé.
double *fill_vectors(double *vec, int n) {
  int i;
  for (i = 0; i < n; i++)
    vec[i] = rand() % 20 - 10;
  return vec;
}

/// @brief Affiche les éléments d'une matrice de taille n
/// @param[in] matrix est la matrice à afficher
/// @param[in] n est la taille de la matrice à afficher
void print_matrix(double **matrix, int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      cout << matrix[i][j] << ", ";
    cout << endl;
  }
}

/// @brief Calcul la trace d'une matrice
/// @param[in] matrix est la matrice dont on souhaite connaître la trace.
/// @param[in] n est la taille de la matrice.
double trace(double **matrix, int n) {
  int i;
  double sum = 0.0;
  for (i = 0; i < n; i++)
    sum += matrix[i][i];
  return sum;
}

/// @brief libere la matrice
/// @param matrix la matrice
/// @param n taille de la matrice
void libere(double **matrix, int n) {
  for(int i = 0; i < n; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
}

double *initialization_vect(int n) {
  double *matrix;
  matrix = new double[n]();
  return matrix;
}

void libere_vect(double *vect, int n) {
  delete[] vect;
}

void affiche_vect(double *vect, int n) {
  cout << "[";
  for(int i = 0; i < n; i++) cout << vect[i] << "; ";
  cout << "]";
}


template <typename TFunc>
double* resolution(int n, double h, double a, double sol_init, TFunc phi){
  double *vect = initialization_vect(n);
  vect[0] = sol_init;
  for(int i = 1; i < n; i++){
      vect[i] = vect[i-1] + h * phi(a+i*h, vect[i-1]);
  }
  return vect;
}
