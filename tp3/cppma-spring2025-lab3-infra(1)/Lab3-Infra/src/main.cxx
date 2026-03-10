#include "../include/Particule.hpp"
#include "../include/Univers.hpp"
#include <string>
#include <set>
#include <list>
#include <deque>
#include <vector>
#include <random>
#include <iostream>
#include <cmath>
#include <chrono>



int main() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);


    for(int k=1; k<5; k++) {


        int n = pow(pow(2, k), 3);

        Univers u = Univers(3);

        for(int i=0; i<n; i++) {
            u.add(Particule(dist(mt), dist(mt), dist(mt), i+1));
        }

        auto start = std::chrono::steady_clock::now();

        u.avance();

        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "elapsed time for k = " << std::to_string(k) << " : " << elapsed_seconds.count() << "s\n";

        u.headEtat();

        //std::cout << u.toString() << std::endl;
}



}