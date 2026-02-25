#include "../include/Particule.hpp"
#include <string> 

Particule::Particule(double x, double y, double vx, double vy, int id, double masse, std::string nom) {
    this->x = x;
    this->y = y;
    this->vx = vx;
    this->vy = vy;
    this->id = id;
    this->mass = masse;
    this->type = nom;

}

