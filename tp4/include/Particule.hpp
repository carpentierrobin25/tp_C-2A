#pragma once
#include "../include/Vecteur.hpp"
#include <string> 

class Particule {
    
    private:
        // nombre de particule présente en tout
        inline static int nb = 0;

        // position
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

        Particule(double x, double y, double z, double vx, double vy, double vz, double masse, std::string nom); 
        Particule(double x, double y, double z); 
        Particule();
        Particule(double x, double y, double z, double vx, double vy, double vz, double masse, std::string nom, int id); 
        Particule(double x, double y, double z, int id); 
        Particule(int id);

        double getMass() const;
        void setMass(double mass);

        const Vecteur& getPos() const;
        void setPos(Vecteur pos);

        const Vecteur& getVit() const;
        void setVit(Vecteur vit);

        const Vecteur& getForce() const;
        void setForce(Vecteur force);

        int getId () const;

        std::string toString() const;

        bool operator<(const Particule& other) const;

        Vecteur forceIG(const Particule& other) const;


};