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
    this->type = "Default::" + std::to_string(nb);
    this->id = id;
}

Particule::Particule(int id) {
    this->pos = Vecteur();
    this->vit = Vecteur();
    ++nb;
    this->mass = 1;
    this->type = "Default::" + std::to_string(nb);
    this->id = id;
}

double Particule::getMass() {return mass;}

void Particule::setMass(double mass) {this->mass = mass;}

Vecteur& Particule::getPos() {return pos;}
        
void Particule::setPos(Vecteur pos) {this->pos = pos;}

Vecteur& Particule::getVit() {return vit;}
        
void Particule::setVit(Vecteur pos) {this->vit = vit;}

Vecteur& Particule::getForce() {return force;}
        
void Particule::setForce(Vecteur force) {this->force = force;}

int Particule::getId() {return id;}

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

double Particule::distEucl(const Particule& corps) const {
    const Particule& objet = *this;
    double distCarre = (corps.pos.getX()-objet.pos.getX()) * (corps.pos.getX()-objet.pos.getX()) + (corps.pos.getY()-objet.pos.getY()) * (corps.pos.getY()-objet.pos.getY()) + (corps.pos.getZ()-objet.pos.getZ()) * (corps.pos.getZ()-objet.pos.getZ());
    return pow(distCarre, 1/2);
}

Vecteur Particule::forceIG(const Particule& corps) const {
    const Particule& objet = *this;
    double dist_pow3 = pow(objet.distEucl(corps), 3);
    double produit_mass = objet.mass * corps.mass;
    double forceX = produit_mass * (corps.pos.getX()-objet.pos.getX()) / dist_pow3;
    double forceY = produit_mass * (corps.pos.getY()-objet.pos.getY()) / dist_pow3;
    double forceZ = produit_mass * (corps.pos.getZ()-objet.pos.getZ()) / dist_pow3;
    return Vecteur(forceX, forceY, forceZ);
}

