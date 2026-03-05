#pragma once
#include <string> 

class Vecteur {

    // vecteur 2d de double
    
    private:
        double x;
        double y;

    public:

        Vecteur(double x, double y);
        Vecteur();

        double getX();
        double getY();

        void setX(double x);
        void setY(double y);




};