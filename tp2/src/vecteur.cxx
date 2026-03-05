#include "../include/vecteur.hpp"
#include <string> 

Vecteur::Vecteur(double x, double y) {
    this->x = x;
    this->y = y;
}

Vecteur::Vecteur() {
    this->x = 0;
    this->y = 0;
}

double Vecteur::getX() {return x;}
double Vecteur::getY() {return y;}

void Vecteur::setX(double x) {this->x = x;}
void Vecteur::setY(double y) {this->y = y;}