#ifndef UNIVERS_HPP
#define UNIVERS_HPP

#include "Particule.hpp"
#include "Vecteur.hpp"
#include "Cellule.hpp"
#include <vector>

class Univers {
    
    private:
        static constexpr double epsilon = 1;
        static constexpr double sigma = 1;
        int dim;
        double longueurC;
        double rCut;
        Cellule* cells;
        int nbCellsx;
        int nbCellsy;
        int nbCellsz;

    public:
    // Constructeurs
        Univers(int dim, double longueurC, double rCut);
        Univers(double longueurC, double rCut);

    // Règle de 3
        ~Univers();
        Univers operator=(const Univers& other);
        Univers(const Univers& other);
        bool operator==(const Univers& other) const;


};

#endif