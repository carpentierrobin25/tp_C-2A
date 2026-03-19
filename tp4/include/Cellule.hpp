#ifndef CELLULE_HPP
#define CELLULE_HPP 
#include "Particule.hpp"


class Cellule {

    private:
        // nombre de particules présentes dans la cellule
        // plus pratique de faire un vecteur car on peut ajouter et enlever des particules rapidement
        std::vector<Particule> particules;
        int dim;
        double cote;
        // tableau de pointeurs vers les cellules voisines pour ne pas à avoir à les recopier dans chaque cellule
        Cellule** voisins;
        int nbVoisins;
        Vecteur pos;

    public:
    // Constructeurs
        Cellule(int dim, double cote, Vecteur pos);
        Cellule(int dim, double cote, int nbParticules, Vecteur pos);
        Cellule(int dim, double cote, Cellule** voisins, Vecteur pos);
        Cellule(int dim, double cote, Cellule** voisins, int nbParticules, Vecteur pos);

    // Règle de 3
        ~Cellule();
        Cellule operator=(const Cellule& other);
        Cellule(const Cellule& other);
        bool operator==(const Cellule& other) const;


};

#endif