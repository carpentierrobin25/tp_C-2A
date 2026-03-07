#include "../include/Particule.hpp"
#include <set>

class Univers {
    
    private:
        int dim;
        int nb;
        std::set<Particule> particules;

    public:
        Univers();
        Univers(int dim);

        int getdim();

        int getnb();

        std::set<Particule>& getParticules();
        void add(Particule part);

        std::string toString();




};