#include "../include/Vecteur.hpp"
#include <string>
#include <iostream>

int main(){
  Vecteur v1 = Vecteur(1,2,3);
  Vecteur v2 = Vecteur(4,5,6);

  std::cout << v1.toString() << std::endl;
  std::cout << v2.toString() << std::endl;

  return EXIT_SUCCESS;
}