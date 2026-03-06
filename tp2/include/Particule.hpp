#pragma once
#include "../include/vecteur.hpp"
#include <string> 

class Particule {
    
    private:
        // nombre de particule présente pour calculer l id
        inline static int nb = 0;

        // position en 2d
        Vecteur pos;

        // vitesse
        Vecteur vit;

        // masse
        double mass;

        // id
        int id;

        // catégorie
        std::string type;

        // force
        Vecteur force;

    public:

        Particule(double x, double y, double vx, double vy, double masse, std::string nom); 
        Particule();

        double getMass();
        void setMass(double mass);

        Vecteur& getPos();
        void setPos(Vecteur pos);

        Vecteur& getVit();
        void setVit(Vecteur vit);

        Vecteur& getForce();
        void setForce(Vecteur force);

};