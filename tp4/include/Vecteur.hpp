#pragma once
#include <string> 
#include <vector>


class Vecteur {

    // vecteur de dimension 1 2 ou 3
    
    private:
        std::vector<double> coor;
        int dim;

    public:

        // init à valeur précise, donne indirectement la dimension 
        Vecteur(double x, double y, double z);
        Vecteur(double x, double y);
        Vecteur(double x);

        // init à partir d'une dimension 1 2 ou 3, les coordonées à 0
        Vecteur(int dim);

        // dim par défaut 3, les coordonées à 0
        Vecteur();


        // accés et modif des coordonées assert si la dimension ne correspond pas 
        double getX() const;
        double getY() const;
        double getZ() const;

        void setX(double x);
        void setY(double y);
        void setZ(double z);

        int getDim() const;

        std::string toString() const;

        // addition coor par coor
        Vecteur& operator+=(const Vecteur& other);

        // soustraction coor par coor
        Vecteur& operator-=(const Vecteur& other);

        // opération élémentaire vectorielle

        Vecteur operator+(const Vecteur& other) const;
        Vecteur operator-(const Vecteur& other) const;
        Vecteur operator*(const Vecteur& other) const;
        Vecteur operator/(const Vecteur& other) const;

        Vecteur operator+(double scal) const;
        Vecteur operator-(double scal) const;
        Vecteur operator*(double scal) const;
        Vecteur operator/(double scal) const;

        Vecteur operator-() const;

        // opérations plus complexes à ajouter si besoin

        double diffX(const Vecteur& other) const;
        double diffY(const Vecteur& other) const;
        double diffZ(const Vecteur& other) const;

        // produit scalaire
        double ps(const Vecteur& other) const;

        // distance euclidienne
        double dist(const Vecteur& other) const;

        // appliquer une fonction qulconque
        template<typename F>
        
        void apply(F f) {
        switch(dim) {
            case 3:
            coor[2] = f(coor[2]);
            case 2:
            coor[1] = f(coor[1]);
            case 1:
            coor[0] = f(coor[0]);
        }
    }

};

// suite des opération élémentaire

Vecteur operator+(double scalar, const Vecteur& v);
Vecteur operator-(double scalar, const Vecteur& v);
Vecteur operator*(double scalar, const Vecteur& v);
Vecteur operator/(double scalar, const Vecteur& v);