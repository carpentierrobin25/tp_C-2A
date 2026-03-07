#include "../include/Particule.hpp"
#include "../include/Univers.hpp"
#include <string>
#include <set>
#include <list>
#include <deque>
#include <vector>
#include <random>
#include <iostream>
#include <cmath>
#include <chrono>


void stromerVerlet(std::vector<Particule> listP, double tEnd, double deltaT) {
    int N = listP.size();
    // calcul des forces
    std::vector<Vecteur> forcesP(N);
    for(int i = 0; i < N; i++) {
        Particule objet = listP[i];
        for(int j = 0; j < N; j++) {
            if(i!=j) {
                Particule corps = listP[j];
                double dist_pow3 = (corps.getPos().getX()-objet.getPos().getX()) * (corps.getPos().getX()-objet.getPos().getX()) + (corps.getPos().getY()-objet.getPos().getY()) * (corps.getPos().getY()-objet.getPos().getY());
                dist_pow3 = pow(dist_pow3, 3/2);
                double produit_mass = objet.getMass() * corps.getMass();
                forcesP[i].setX(forcesP[i].getX() + produit_mass * (corps.getPos().getX()-objet.getPos().getX()) / dist_pow3);
                forcesP[i].setY(forcesP[i].getY() + produit_mass * (corps.getPos().getY()-objet.getPos().getY()) / dist_pow3);
            }
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
            objet.setForce(forcesP[i]);
            listP[i] = objet;
        }
        // calcul des forces f
        for(int i = 0; i < N; i++) {
            Particule objet = listP[i];
            for(int j = 0; j < N; j++) {
                if(i!=j){
                    Particule corps = listP[j];
                    double dist_pow3 = (corps.getPos().getX()-objet.getPos().getX()) * (corps.getPos().getX()-objet.getPos().getX()) + (corps.getPos().getY()-objet.getPos().getY()) * (corps.getPos().getY()-objet.getPos().getY());
                    dist_pow3 = pow(dist_pow3, 3/2);
                    double produit_mass = objet.getMass() * corps.getMass();
                    forcesP[i].setX(forcesP[i].getX() + produit_mass * (corps.getPos().getX()-objet.getPos().getX()) / dist_pow3);
                    forcesP[i].setY(forcesP[i].getY() + produit_mass * (corps.getPos().getY()-objet.getPos().getY()) / dist_pow3);
                }
            }
        }
        for(int i=0; i < N; i++) {
            Particule objet = listP[i];
            double vx = objet.getVit().getX() + deltaT * 0.5 / objet.getMass() * (forcesP[i].getX() * objet.getForce().getX());
            objet.getVit().setX(vx);
            double vy = objet.getVit().getY() + deltaT * 0.5 / objet.getMass() * (forcesP[i].getY() * objet.getForce().getY());
            objet.getVit().setY(vy);
            objet.setForce(forcesP[i]);
            listP[i] = objet;
        }
        // calcul des quantités dérivées
        std::cout << "t : " << t <<  std::endl;
        for(int i=0; i < N; i++) {
            std::cout << "x : " << listP[i].getPos().getX() << " | y : " << listP[i].getPos().getY() << std::endl;  
        }

    }
}



int main() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);


    for(int k=3; k<7; k++) {


        int n = pow(pow(2, k), 3);

        Univers u = Univers(3);

        auto start = std::chrono::steady_clock::now();
        for(int i=0; i<n; i++) {
            u.add(Particule(dist(mt), dist(mt), dist(mt)));
        }

        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "elapsed time for k = " << std::to_string(k) << " : " << elapsed_seconds.count() << "s\n";

        //std::cout << u.toString() << std::endl;
}



}