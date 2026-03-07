#pragma once
#include <string> 


class Vecteur {

    // vecteur 3d de double
    
    private:
        double x;
        double y;
        double z;

    public:

        Vecteur(double x, double y, double z);
        Vecteur();

        double getX();
        double getY();
        double getZ();

        void setX(double x);
        void setY(double y);
        void setZ(double z);

        std::string toString();


};