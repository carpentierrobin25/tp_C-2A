#include "../include/Particule.hpp"
#include <string>
#include <set>
#include <list>
#include <deque>
#include <vector>
#include <random>
#include <iostream>
#include <cmath>


void stromerVerlet(std::vector<Particule> listP, double tEnd, double deltaT) {
    int N = listP.size();
    // calcul des forces
    std::vector<Vecteur> forcesP(N);
    for(int i = 0; i < N; i++) {
        forcesP[i] = new Vecteur();
        Particule objet = listP[i];
        for(int j = 0; j < N; j++) {
            Particule corps = forceP[j];
            double dist_pow3 = (corps.getPos().getX()-objet.getPos().getX()) * (corps.getPos().getX()-objet.getPos().getX()) + (corps.getPos().getY()-objet.getPos().getY()) * (corps.getPos().getY()-objet.getPos().getY());
            dist_pow3 = pow(dist_pow3, 3/2);
            double produit_mass = objet.getMass * corps.getMass;
            forcesP.setX(produit_mass * (corps.getPos().getX()-objet.getPos().getX()) / dist_pow3);
            forcesP.setY(produit_mass * (corps.getPos().getY()-objet.getPos().getY()) / dist_pow3);
        }
    }
    while(t < tEnd) {
        t += deltaT;
        for(int i=0; i < N; i++) {
            Particule objet = listP[i];
            double x = objet.getPos.getX() + deltaT * (objet.getVit.getX() + 0.5 / objet.getMass() * forceP[i] * deltaT);
            objet.setX(x);
            objet.setForce(forceP[i]);
        }
    }
}




int main() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);


    int n = 64;

    std::vector<Particule> listP;
    listP.push_back(Particule(0, 0, 0, 0, 1, 1, "Soleil"));

}