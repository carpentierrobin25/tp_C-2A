#include "../include/Particule.hpp"
#include <string> 
#include <cmath>

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

Particule::Particule(double x, double y, double z, double vx, double vy, double vz, double masse, std::string nom, int id) {
    this->pos = Vecteur(x, y, z);
    this->vit = Vecteur(vx, vy, vz);
    ++nb;
    this->mass = masse;
    this->type = nom;
    this->id = id;
}

Particule::Particule(double x, double y, double z, int id) {
    this->pos = Vecteur(x, y, z);
    this->vit = Vecteur();
    ++nb;
    this->mass = 1;
    this->type = "Default::" + std::to_string(id);
    this->id = id;
}

Particule::Particule(int id) {
    this->pos = Vecteur();
    this->vit = Vecteur();
    ++nb;
    this->mass = 1;
    this->type = "Default::" + std::to_string(id);
    this->id = id;
}

double Particule::getMass() const {return mass;}

void Particule::setMass(double mass) {this->mass = mass;}

const Vecteur& Particule::getPos() const {return pos;}
        
void Particule::setPos(Vecteur pos) {this->pos = pos;}

const Vecteur& Particule::getVit() const {return vit;}
        
void Particule::setVit(Vecteur vit) {this->vit = vit;}

const Vecteur& Particule::getForce() const {return force;}
        
void Particule::setForce(Vecteur force) {this->force = force;}

int Particule::getId() const {return id;}

std::string Particule::toString() const {
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

Vecteur Particule::forceIG(const Particule& corps) const {
    return  mass * corps.mass * Vecteur(pos.diffX(corps.getPos()), pos.diffY(corps.getPos()), pos.diffZ(corps.getPos())) / pow(pos.dist(corps.getPos()), 3);
}

