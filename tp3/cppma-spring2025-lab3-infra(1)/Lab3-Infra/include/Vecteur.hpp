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

        double getX() const;
        double getY() const;
        double getZ() const;

        void setX(double x);
        void setY(double y);
        void setZ(double z);

        std::string toString();

        Vecteur& operator+=(const Vecteur& other);

        Vecteur& operator-=(const Vecteur& other);


};