#include "../include/Univers.hpp"
#include "../include/Particule.hpp"
#include <set>
#include <string>
#include <iostream>

Univers::Univers() {
    this->dim = 1;
    this->nb = 0;
}

Univers::Univers(int dim) {
    this->dim = dim;
}

int Univers::getdim() {return dim;}

int Univers::getnb() {return nb;}

std::set<Particule>& Univers::getParticules() {return particules;}

void Univers::add(Particule part) {
    particules.insert(part);
    nb++;
}

std::string Univers::toString() {
    std::string res = "dim : " + std::to_string(dim) + "\n";
    res += "nombres : " + std::to_string(nb) + "\n";
    res += "/* particules */\n";
    for(Particule p : particules) {
        res += p.toString() + "\n";
    }
    return res;
}