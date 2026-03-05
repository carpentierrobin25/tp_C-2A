#include "../include/Particule.hpp"
#include <string> 

Particule::Particule(double x, double y, double vx, double vy, int id, double masse, std::string nom) {
    this->pos = new Vecteur(x, y);
    this->vit = new Vecteur(vx, vy);
    this->id = id;
    this->mass = masse;
    this->type = nom;

}

Particule::Particule(int id, std::string nom) {
    this->pos = new Vecteur();
    this->vit = new Vecteur();
    this->id = id;
    this->mass = 0;
    this->type = nom;

}

double getMass() {return mass;}

void setMass(double mass) {this->mass = mass;}

Vecteur getPos() {return pos;}
        
void setPos(Vecteur pos) {this->pos = pos;}

Vecteur getPos() {return vit;}
        
void setPos(Vecteur pos) {this->vit = vit;}

Vecteur getForce() {return force;}
        
void setPos(Vecteur force) {this->force = force;}