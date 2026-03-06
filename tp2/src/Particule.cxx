#include "../include/Particule.hpp"
#include <string> 

Particule::Particule(double x, double y, double vx, double vy, double masse, std::string nom) {
    this->pos = Vecteur(x, y);
    this->vit = Vecteur(vx, vy);
    this->id = ++nb;
    this->mass = masse;
    this->type = nom;

}

Particule::Particule() {
    this->pos = Vecteur();
    this->vit = Vecteur();
    this->id = ++nb;
    this->mass = 0;
    this->type = "Default::" + std::to_string(nb);

}

double Particule::getMass() {return mass;}

void Particule::setMass(double mass) {this->mass = mass;}

Vecteur& Particule::getPos() {return pos;}
        
void Particule::setPos(Vecteur pos) {this->pos = pos;}

Vecteur& Particule::getVit() {return vit;}
        
void Particule::setVit(Vecteur pos) {this->vit = vit;}

Vecteur& Particule::getForce() {return force;}
        
void Particule::setForce(Vecteur force) {this->force = force;}