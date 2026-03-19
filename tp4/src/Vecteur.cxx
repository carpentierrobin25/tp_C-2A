#include "../include/Vecteur.hpp"
#include <string> 
#include <vector>
#include <assert.h>
#include <cmath>

Vecteur::Vecteur(double x, double y, double z) : dim{3} {
    coor = new double[3];
    coor[0] = x;
    coor[1] = y;
    coor[2] = z;
}

Vecteur::Vecteur(double x, double y) : dim{2} {
    coor = new double[2];
    coor[0] = x;
    coor[1] = y;
}

Vecteur::Vecteur(double x) : dim{1} {
    coor = new double[1];
    coor[0] = x;
}

Vecteur::Vecteur(int dim) : dim{dim} {
    assert(dim >= 0 && dim <= 3);
    coor = new double[dim];
    for(int i = 0; i < dim; i++) {
        coor[i] = 0.0;
    }
}

Vecteur::Vecteur() : dim{3} {
    coor = new double[3];
    for(int i = 0; i < 3; i++) {
        coor[i] = 0.0;
    }
}

Vecteur::~Vecteur() {
    delete[] coor;
}

Vecteur::Vecteur(const Vecteur& other) : dim{other.dim} {
    coor = new double[dim];
    for(int i = 0; i < dim; i++) {
        coor[i] = other.coor[i];
    }
}

bool Vecteur::operator==(const Vecteur& other) const {
    if(dim != other.dim) return false;
    for(int i = 0; i < dim; i++) {
        if(coor[i] != other.coor[i]) return false;
    }
    return true;
}

Vecteur& Vecteur::operator=(const Vecteur& v) {
    if(this == &v) return *this;
    delete[] coor;      
    dim = v.dim;
    coor = new double[dim];
    for(int i = 0; i < dim; i++)
        coor[i] = v.coor[i];
    return *this;
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

Vecteur& Vecteur::setX(double x) {
    this->coor[0] = x; 
    return *this;
}
Vecteur& Vecteur::setY(double y) {
    assert(dim >= 2);
    this->coor[1] = y;
    return *this;
}
Vecteur& Vecteur::setZ(double z) {
    assert(dim == 3);
    this->coor[2] = z;
    return *this;
}

int Vecteur::getDim() const {return dim;}

std::string Vecteur::toString() const {
    std::string res = "(";
    for(int i=0; i<dim-1; i++) res += std::to_string(coor[i]) + ";";
    res += std::to_string(coor[dim]) + ")";
    return res;
}

std::ostream& operator<<(std::ostream& os, const Vecteur& v) {
    os << v.toString();
    return os;
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

Vecteur& Vecteur::operator*=(const Vecteur& other) {
        verif_dim(*this, other);
        switch(dim) {
        case 3:
        coor[2] *= other.getZ();
        case 2:
        coor[1] *= other.getY();
        case 1:
        coor[0] *= other.getX();
    }
    return *this;
}

Vecteur& Vecteur::operator/=(const Vecteur& other) {
        verif_dim(*this, other);
        switch(dim) {
        case 3:
        coor[2] /= other.getZ();
        case 2:
        coor[1] /= other.getY();
        case 1:
        coor[0] /= other.getX();
    }
    return *this;
}


Vecteur operator+(Vecteur mainV, const Vecteur& other) {
    return mainV += other;
}
Vecteur operator-(Vecteur mainV, const Vecteur& other) {
    return mainV -= other;
}
Vecteur operator*(Vecteur mainV, const Vecteur& other) {
    return mainV *= other;
}
Vecteur operator/(Vecteur mainV, const Vecteur& other) {
    return mainV /= other;
}

Vecteur Vecteur::operator+(double scal) const {
    switch(dim) {
        case 3:
        return Vecteur(coor[0] + scal, coor[1] + scal, coor[2] + scal);
        break;
        case 2:
        return Vecteur(coor[0] + scal, coor[1] + scal);
        break;
        case 1:
        return Vecteur(coor[0] + scal);
        break;
    }
    return Vecteur(0);
}


Vecteur Vecteur::operator-(double scal) const {
    switch(dim) {
        case 3:
        return Vecteur(coor[0] - scal, coor[1] - scal, coor[2] - scal);
        break;
        case 2:
        return Vecteur(coor[0] - scal, coor[1] - scal);
        break;
        case 1:
        return Vecteur(coor[0] - scal);
        break;
    }
    return Vecteur(0);
}

Vecteur Vecteur::operator*(double scal) const {
    switch(dim) {
        case 3:
        return Vecteur(coor[0] * scal, coor[1] * scal, coor[2] * scal);
        break;
        case 2:
        return Vecteur(coor[0] * scal, coor[1] * scal);
        break;
        case 1:
        return Vecteur(coor[0] * scal);
        break;
    }
    return Vecteur(0);
}


Vecteur Vecteur::operator/(double scal) const {
    switch(dim) {
        case 3:
        return Vecteur(coor[0] / scal, coor[1] / scal, coor[2] / scal);
        break;
        case 2:
        return Vecteur(coor[0] / scal, coor[1] / scal);
        break;
        case 1:
        return Vecteur(coor[0] / scal);
        break;
    }
    return Vecteur(0);
}

Vecteur Vecteur::operator-() const {
    switch(dim) {
        case 3:
        return Vecteur(-coor[0], -coor[1], -coor[2]);
        break;
        case 2:
        return Vecteur(-coor[0], -coor[1]);
        break;
        case 1:
        return Vecteur(-coor[0]);
        break;
    }
    return Vecteur(0);
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
    switch(v.getDim()) {
        case 3:
        return Vecteur( scalar / v.getX(), scalar / v.getY(), scalar / v.getZ());
        break;
        case 2:
        return Vecteur(scalar / v.getX(), scalar / v.getY());
        break;
        case 1:
        return Vecteur(scalar / v.getX());
        break;
    }
    return Vecteur(0);
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