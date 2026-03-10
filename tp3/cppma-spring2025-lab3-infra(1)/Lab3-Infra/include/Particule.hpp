#pragma once
#include "../include/Vecteur.hpp"
#include <string> 

class Particule {
    
    private:
        // nombre de particule présente pour calculer l id si pas précisé
        inline static int nb = 0;

        // position en 3d
        Vecteur pos;

        // vitesse en 3d
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

        Particule(double x, double y, double z, double vx, double vy, double vz, double masse, std::string nom); 
        Particule(double x, double y, double z); 
        Particule();
        Particule(double x, double y, double z, double vx, double vy, double vz, double masse, std::string nom, int id); 
        Particule(double x, double y, double z, int id); 
        Particule(int id);

        double getMass();
        void setMass(double mass);

        Vecteur& getPos();
        void setPos(Vecteur pos);

        Vecteur& getVit();
        void setVit(Vecteur vit);

        Vecteur& getForce();
        void setForce(Vecteur force);

        int getId();

        std::string toString();

        bool operator<(const Particule& other) const;

        double distEucl(const Particule& other) const;

        Vecteur forceIG(const Particule& other) const;


};