#include "../include/Vecteur.hpp"
#include <string> 
#include <vector>
#include <assert.h>
#include <cmath>

Vecteur::Vecteur(double x, double y, double z) {
    this->dim = 3;
    coor.push_back(x);
    coor.push_back(y);
    coor.push_back(z);
}

Vecteur::Vecteur(double x, double y) {
    this->dim = 2;
    coor.push_back(x);
    coor.push_back(y);
}

Vecteur::Vecteur(double x) {
    this->dim = 1;
    coor.push_back(x);
}

Vecteur::Vecteur(int dim) {
    assert(dim >= 0 && dim <= 3);
    for(int i=0; i < (this->dim = dim); i++) coor.push_back(0);
}

Vecteur::Vecteur() {
    this->dim = 3;
    coor.push_back(0);
    coor.push_back(0);
    coor.push_back(0);
}


double Vecteur::getX() const {return coor[0];}
double Vecteur::getY() const {
    assert(dim >= 2);
    return coor[1];
}
double Vecteur::getZ() const {
    assert(dim == 3);
    return coor[2];
}

void Vecteur::setX(double x) {this->coor[0] = x;}
void Vecteur::setY(double y) {
    assert(dim >= 2);
    this->coor[1] = y;
}
void Vecteur::setZ(double z) {
    assert(dim == 3);
    this->coor[2] = z;
}

int Vecteur::getDim() const {return dim;}

std::string Vecteur::toString() const {
    std::string res = "(";
    for(int i=0; i<dim-1; i++) res += std::to_string(coor[i]) + ";";
    res += std::to_string(coor[dim]) + ")";
    return res;
}

bool verif_dim(const Vecteur& v1, const Vecteur& v2) {
    return v1.getDim() == v2.getDim();
}

bool verif_dim(const Vecteur& v1, const Vecteur& v2, int dim_min) {
    return v1.getDim() == v2.getDim() && dim_min<=v1.getDim();
}


Vecteur& Vecteur::operator+=(const Vecteur& other) {
    verif_dim(*this, other);
    switch(dim) {
        case 3:
        coor[2] += other.getZ();
        case 2:
        coor[1] += other.getY();
        case 1:
        coor[0] += other.getX();
    }
    return *this;
}

Vecteur& Vecteur::operator-=(const Vecteur& other) {
        verif_dim(*this, other);
        switch(dim) {
        case 3:
        coor[2] -= other.getZ();
        case 2:
        coor[1] -= other.getY();
        case 1:
        coor[0] -= other.getX();
    }
    return *this;
}

Vecteur Vecteur::operator+(const Vecteur& other) const {
    verif_dim(*this, other);
    Vecteur res;
    switch(dim) {
        case 3:
        res = Vecteur(coor[0] + other.coor[0], coor[1] + other.coor[1], coor[2] + other.coor[2]);
        break;
        case 2:
        res = Vecteur(coor[0] + other.coor[0], coor[1] + other.coor[1]);
        break;
        case 1:
        res = Vecteur(coor[0] + other.coor[0]);
        break;
    }
    return res;
}

Vecteur Vecteur::operator-(const Vecteur& other) const {
    verif_dim(*this, other);
    Vecteur res;
    switch(dim) {
        case 3:
        res = Vecteur(coor[0] - other.coor[0], coor[1] - other.coor[1], coor[2] - other.coor[2]);
        break;
        case 2:
        res = Vecteur(coor[0] - other.coor[0], coor[1] - other.coor[1]);
        break;
        case 1:
        res = Vecteur(coor[0] - other.coor[0]);
        break;
    }
    return res;
}

Vecteur Vecteur::operator*(const Vecteur& other) const {
    verif_dim(*this, other);
    Vecteur res;
    switch(dim) {
        case 3:
        res = Vecteur(coor[0] * other.coor[0], coor[1] * other.coor[1], coor[2] * other.coor[2]);
        break;
        case 2:
        res = Vecteur(coor[0] * other.coor[0], coor[1] * other.coor[1]);
        break;
        case 1:
        res = Vecteur(coor[0] * other.coor[0]);
        break;
    }
    return res;
}

Vecteur Vecteur::operator/(const Vecteur& other) const {
    verif_dim(*this, other);
    Vecteur res;
    switch(dim) {
        case 3:
        res = Vecteur(coor[0] / other.coor[0], coor[1] / other.coor[1], coor[2] / other.coor[2]);
        break;
        case 2:
        res = Vecteur(coor[0] / other.coor[0], coor[1] / other.coor[1]);
        break;
        case 1:
        res = Vecteur(coor[0] / other.coor[0]);
        break;
    }
    return res;
}

Vecteur Vecteur::operator+(double scal) const {
    Vecteur res;
    switch(dim) {
        case 3:
        res = Vecteur(coor[0] + scal, coor[1] + scal, coor[2] + scal);
        break;
        case 2:
        res = Vecteur(coor[0] + scal, coor[1] + scal);
        break;
        case 1:
        res = Vecteur(coor[0] + scal);
        break;
    }
    return res;
}


Vecteur Vecteur::operator-(double scal) const {
    Vecteur res;
    switch(dim) {
        case 3:
        res = Vecteur(coor[0] - scal, coor[1] - scal, coor[2] - scal);
        break;
        case 2:
        res = Vecteur(coor[0] - scal, coor[1] - scal);
        break;
        case 1:
        res = Vecteur(coor[0] - scal);
        break;
    }
    return res;
}

Vecteur Vecteur::operator*(double scal) const {
    Vecteur res;
    switch(dim) {
        case 3:
        res = Vecteur(coor[0] * scal, coor[1] * scal, coor[2] * scal);
        break;
        case 2:
        res = Vecteur(coor[0] * scal, coor[1] * scal);
        break;
        case 1:
        res = Vecteur(coor[0] * scal);
        break;
    }
    return res;
}


Vecteur Vecteur::operator/(double scal) const {
    Vecteur res;
    switch(dim) {
        case 3:
        res = Vecteur(coor[0] / scal, coor[1] / scal, coor[2] / scal);
        break;
        case 2:
        res = Vecteur(coor[0] / scal, coor[1] / scal);
        break;
        case 1:
        res = Vecteur(coor[0] / scal);
        break;
    }
    return res;
}

Vecteur Vecteur::operator-() const {
    Vecteur res;
    switch(dim) {
        case 3:
        res = Vecteur(-coor[0], -coor[1], -coor[2]);
        break;
        case 2:
        res = Vecteur(-coor[0], -coor[1]);
        break;
        case 1:
        res = Vecteur(-coor[0]);
        break;
    }
    return res;
}


Vecteur operator+(double scalar, const Vecteur& v) {
    return v + scalar;
}

Vecteur operator-(double scalar, const Vecteur& v) {
    return -(v-scalar);
}

Vecteur operator*(double scalar, const Vecteur& v) {
    return v * scalar;
}

Vecteur operator/(double scalar, const Vecteur& v) {
    Vecteur res;
    switch(v.getDim()) {
        case 3:
        res = Vecteur( scalar / v.getX(), scalar / v.getY(), scalar / v.getZ());
        break;
        case 2:
        res = Vecteur(scalar / v.getX(), scalar / v.getY());
        break;
        case 1:
        res = Vecteur(scalar / v.getX());
        break;
    }
    return res;
}

double Vecteur::ps(const Vecteur& other) const {
    verif_dim(*this, other);
    double res;
    switch(dim) {
        case 3:
        res += coor[2] * other.getZ();
        case 2:
        res += coor[1] * other.getY();
        case 1:
        res += coor[0] * other.getX();
    }
    return res;
}

double Vecteur::dist(const Vecteur& other) const {
    verif_dim(*this, other);
    double res;
    switch(dim) {
        case 3:
        res += (other.getZ() - coor[2]) * (other.getZ() - coor[2]);
        case 2:
        res += (other.getY() - coor[1]) * (other.getY() - coor[1]);
        case 1:
        res += (other.getX() - coor[0]) * (other.getX() - coor[0]);
    }
    return sqrt(res);
}

double Vecteur::diffX(const Vecteur& other) const {
    verif_dim(*this, other);
    return other.getX() - coor[0];
}

double Vecteur::diffY(const Vecteur& other) const {
    verif_dim(*this, other, 2);
    return other.getY() - coor[1];
}

double Vecteur::diffZ(const Vecteur& other) const {
    verif_dim(*this, other, 3);
    return other.getZ() - coor[2];
}