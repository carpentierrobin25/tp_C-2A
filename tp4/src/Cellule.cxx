#include "../include/Cellule.hpp"
#include "../include/Particule.hpp"
#include "../include/Vecteur.hpp"

#include <vector>
#include <string>
#include <cmath>
#include <assert.h>

Cellule::Cellule(int dim, double cote, Vecteur pos) {
    this->dim = dim;
    this->cote = cote;
    this->pos = pos;
    this->particules = std::vector<Particule>();
    this->nbVoisins = pow(3, dim) - 1;
    this->voisins = new Cellule*[this->nbVoisins];
    for (int i = 0; i < this->nbVoisins; i++) {
        this->voisins[i] = nullptr;
    }
}

Cellule::Cellule(int dim, double cote, int nbParticules, Vecteur pos) {
    this->dim = dim;
    this->cote = cote;
    this->pos = pos;
    this->particules = std::vector<Particule>(nbParticules);
    this->nbVoisins = pow(3, dim) - 1;
    this->voisins = new Cellule*[this->nbVoisins];
    for (int i = 0; i < this->nbVoisins; i++) {
        this->voisins[i] = nullptr;
    }
}

Cellule::Cellule(int dim, double cote, Cellule** voisins, Vecteur pos) {
    assert(voisins != nullptr);
    this->dim = dim;
    this->cote = cote;
    this->pos = pos;
    this->particules = std::vector<Particule>();
    this->nbVoisins = pow(3, dim) - 1;
    this->voisins = voisins;
}

Cellule::Cellule(int dim, double cote, Cellule** voisins, int nbParticules, Vecteur pos) {
    assert(voisins != nullptr);
    this->dim = dim;
    this->cote = cote;
    this->pos = pos;
    this->particules = std::vector<Particule>(nbParticules);
    this->nbVoisins = pow(3, dim) - 1;
    this->voisins = voisins;
}

Cellule::~Cellule() {
    delete[] voisins;
}

Cellule Cellule::operator=(const Cellule& other) {
    if(this == &other) return *this;
    this->dim = other.dim;
    this->cote = other.cote;
    this->pos = other.pos;
    this->particules = other.particules;
    this->nbVoisins = other.nbVoisins;
    delete[] voisins;
    this->voisins = new Cellule*[nbVoisins];
    for(int i = 0; i < nbVoisins; i++) {
        this->voisins[i] = other.voisins[i];
    }
    return *this;
}

Cellule::Cellule(const Cellule& other) {
    this->dim = other.dim;
    this->cote = other.cote;
    this->pos = other.pos;
    this->particules = other.particules;
    this->nbVoisins = other.nbVoisins;
    this->voisins = new Cellule*[nbVoisins];
    for(int i = 0; i < nbVoisins; i++) {
        this->voisins[i] = other.voisins[i];
    }
}

bool Cellule::operator==(const Cellule& other) const {
    if(this->dim != other.dim || this->cote != other.cote || !(this->pos == other.pos) || this->particules != other.particules || this->nbVoisins != other.nbVoisins) return false;
    for(int i = 0; i < nbVoisins; i++) {
        if(this->voisins[i] != other.voisins[i]) return false;
    }
    return true;
}