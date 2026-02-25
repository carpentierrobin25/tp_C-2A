#include "../include/Particule.hpp"
#include <string>
#include <set>
#include <list>
#include <deque>
#include <vector>
#include <random>
#include <iostream>






int main() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);


    int n = 64;

    std::list<Particule> listP;
    listP.push_back(Particule(0, 0, 0, 0, 1, 1, "Soleil"));

}