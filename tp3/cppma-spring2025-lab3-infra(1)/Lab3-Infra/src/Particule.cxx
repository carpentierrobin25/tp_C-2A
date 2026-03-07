#include "../include/Particule.hpp"
#include <string> 

Particule::Particule(double x, double y, double z, double vx, double vy, double vz, double masse, std::string nom) {
    this->pos = Vecteur(x, y, z);
    this->vit = Vecteur(vx, vy, vz);
    this->id = ++nb;
    this->mass = masse;
    this->type = nom;

}

Particule::Particule(double x, double y, double z) {
    this->pos = Vecteur(x, y, z);
    this->vit = Vecteur();
    this->id = ++nb;
    this->mass = 1;
    this->type = "Default::" + std::to_string(nb);

}

Particule::Particule() {
    this->pos = Vecteur();
    this->vit = Vecteur();
    this->id = ++nb;
    this->mass = 1;
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

std::string Particule::toString() {
    std::string res = "/* " + type + " */" + "\n";
    res += "/* " + std::to_string(id) + " */" + "\n";
    res += "Position : " + pos.toString() + "\n";
    res += "Vitesse : " + vit.toString() + "\n";
    res += "Masse : " + std::to_string(mass) + "\n";
    return res;
}

bool Particule::operator<(const Particule& other) const {
    return id < other.id;
}
