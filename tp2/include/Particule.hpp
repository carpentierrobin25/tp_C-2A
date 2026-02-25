#pragma once
#include <string> 

class Particule {
    
    private:
        // position en 2d
        double x;
        double y;

        // vitesse
        double vx;
        double vy;

        // masse
        double mass;

        // id
        int id;

        // catégorie
        std::string type;

        // force
        double force;

    public:

        Particule(double x, double y, double vx, double vy, int id, double masse, std::string nom);


};