#include "../include/Particule.hpp"
#include <set>
#include <vector>

class Univers {
    
    private:
        int dim;
        int nb;
        std::vector<Particule> listP;

    public:
        Univers();
        Univers(int dim);

        int getdim();

        int getnb();

        std::vector<Particule>& getParticules();
        void add(Particule part);

        std::string toString();

        void afficherEtat();

        void headEtat();

        void stromerVerlet(double tEnd, double deltaT);

        void avance();


};