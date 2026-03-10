#include "../include/Univers.hpp"
#include "../include/Particule.hpp"
#include <set>
#include <string>
#include <iostream>
#include <vector>
#include <iostream>
#include <cmath>

Univers::Univers() {
    this->dim = 1;
    this->nb = 0;
}

Univers::Univers(int dim) {
    this->dim = dim;
    this->nb = 0;
}

int Univers::getdim() {return dim;}

int Univers::getnb() {return nb;}

std::vector<Particule>& Univers::getParticules() {return listP;}

void Univers::add(Particule part) {
    listP.push_back(part);
    nb++;
}

std::string Univers::toString() {
    std::string res = "dim : " + std::to_string(dim) + "\n";
    res += "nombres : " + std::to_string(nb) + "\n";
    res += "/* particules */\n";
    for(Particule p : listP) {
        res += p.toString() + "\n";
    }
    return res;
}

void Univers::afficherEtat() {
    for(Particule p : listP) {
        std::cout << p.getId() << ": " << p.getPos().toString() << std::endl;
    }
}

void Univers::headEtat() {
    for(int i=0; i<15; i++) {
        if(nb <= i) {
            break;
        }
        std::cout << listP[i].getId() << ": " << listP[i].getPos().toString() << std::endl;
    }
}

void Univers::stromerVerlet(double tEnd, double deltaT) {
    int N = listP.size();
    // calcul des forces
    std::vector<Vecteur> forcesP(N);
    for(int i = 0; i < N; i++) {
        Particule objet = listP[i];
        for(int j = 0; j < i; j++) {
                Particule corps = listP[j];
                Vecteur force = objet.forceIG(corps);
                forcesP[i] += force;
                forcesP[j] -= force;
        }
    }
    double t = 0;
    while(t < tEnd) {
        t += deltaT;
        for(int i=0; i < N; i++) {
            Particule objet = listP[i];
            double x = objet.getPos().getX() + deltaT * (objet.getVit().getX() + 0.5 / objet.getMass() * forcesP[i].getX() * deltaT);
            objet.getPos().setX(x);
            double y = objet.getPos().getY() + deltaT * (objet.getVit().getY() + 0.5 / objet.getMass() * forcesP[i].getY() * deltaT);
            objet.getPos().setY(y);
            double z = objet.getPos().getZ() + deltaT * (objet.getVit().getZ() + 0.5 / objet.getMass() * forcesP[i].getZ() * deltaT);
            objet.getPos().setZ(z);
            objet.setForce(forcesP[i]);
            listP[i] = objet;
        }
        // calcul des forces f
        for(int i = 0; i < N; i++) {
            Particule objet = listP[i];
            for(int j = 0; j < i; j++) {
                Particule corps = listP[j];
                Vecteur force = objet.forceIG(corps);
                forcesP[i] += force;
                forcesP[j] -= force;
            }
        }
        for(int i=0; i < N; i++) {
            Particule objet = listP[i];
            double vx = objet.getVit().getX() + deltaT * 0.5 / objet.getMass() * (forcesP[i].getX() * objet.getForce().getX());
            objet.getVit().setX(vx);
            double vy = objet.getVit().getY() + deltaT * 0.5 / objet.getMass() * (forcesP[i].getY() * objet.getForce().getY());
            objet.getVit().setY(vy);
            double vz = objet.getVit().getZ() + deltaT * 0.5 / objet.getMass() * (forcesP[i].getZ() * objet.getForce().getZ());
            objet.getVit().setZ(vz);
            objet.setForce(forcesP[i]);
            listP[i] = objet;
        }
        // calcul des quantités dérivées
        /*std::cout << "t : " << t <<  std::endl;
        for(int i=0; i < N; i++) {
            std::cout << "x : " << listP[i].getPos().getX() << " | y : " << listP[i].getPos().getY() << std::endl;  
        }*/

    }
}

void Univers::avance() {stromerVerlet(1,1);}