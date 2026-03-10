#include "../include/Vecteur.hpp"
#include <string> 

Vecteur::Vecteur(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vecteur::Vecteur() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

double Vecteur::getX() const {return x;}
double Vecteur::getY() const {return y;}
double Vecteur::getZ() const {return z;}

void Vecteur::setX(double x) {this->x = x;}
void Vecteur::setY(double y) {this->y = y;}
void Vecteur::setZ(double z) {this->z = z;}

std::string Vecteur::toString() {
    return "(" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + ")";
}

Vecteur& Vecteur::operator+=(const Vecteur& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vecteur& Vecteur::operator-=(const Vecteur& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

