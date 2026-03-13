#include <iostream>
#include <cmath>
#include <string>
#include "../include/Vecteur.hpp"

// ── utilitaire ──────────────────────────────────────────────────────────────

int passed = 0, failed = 0;

void check(const std::string& name, bool condition) {
    if (condition) {
        std::cout << "[PASS] " << name << "\n";
        passed++;
    } else {
        std::cout << "[FAIL] " << name << "\n";
        failed++;
    }
}

bool approx(double a, double b, double eps = 1e-9) {
    return std::abs(a - b) < eps;
}

// ── tests ────────────────────────────────────────────────────────────────────

void testConstructeurs() {
    std::cout << "\n=== Constructeurs ===\n";

    Vecteur v3(1.0, 2.0, 3.0);
    check("dim3 : getDim", v3.getDim() == 3);
    check("dim3 : getX",   approx(v3.getX(), 1.0));
    check("dim3 : getY",   approx(v3.getY(), 2.0));
    check("dim3 : getZ",   approx(v3.getZ(), 3.0));

    Vecteur v2(4.0, 5.0);
    check("dim2 : getDim", v2.getDim() == 2);
    check("dim2 : getX",   approx(v2.getX(), 4.0));
    check("dim2 : getY",   approx(v2.getY(), 5.0));

    Vecteur v1(7.0);
    check("dim1 : getDim", v1.getDim() == 1);
    check("dim1 : getX",   approx(v1.getX(), 7.0));

    Vecteur vd3(3);
    check("dim(3) : getDim", vd3.getDim() == 3);
    check("dim(3) : getX",   approx(vd3.getX(), 0.0));
    check("dim(3) : getY",   approx(vd3.getY(), 0.0));
    check("dim(3) : getZ",   approx(vd3.getZ(), 0.0));

    Vecteur vd2(2);
    check("dim(2) : getDim", vd2.getDim() == 2);
    check("dim(2) : getX",   approx(vd2.getX(), 0.0));
    check("dim(2) : getY",   approx(vd2.getY(), 0.0));

    Vecteur vd1(1);
    check("dim(1) : getDim", vd1.getDim() == 1);
    check("dim(1) : getX",   approx(vd1.getX(), 0.0));

    Vecteur vdef;
    check("defaut : getDim", vdef.getDim() == 3);
    check("defaut : getX",   approx(vdef.getX(), 0.0));
    check("defaut : getY",   approx(vdef.getY(), 0.0));
    check("defaut : getZ",   approx(vdef.getZ(), 0.0));
}

void testSetters() {
    std::cout << "\n=== Setters ===\n";

    Vecteur v3(0.0, 0.0, 0.0);
    v3.setX(9.0); v3.setY(8.0); v3.setZ(7.0);
    check("dim3 : setX", approx(v3.getX(), 9.0));
    check("dim3 : setY", approx(v3.getY(), 8.0));
    check("dim3 : setZ", approx(v3.getZ(), 7.0));

    Vecteur v2(0.0, 0.0);
    v2.setX(3.0); v2.setY(4.0);
    check("dim2 : setX", approx(v2.getX(), 3.0));
    check("dim2 : setY", approx(v2.getY(), 4.0));

    Vecteur v1(0.0);
    v1.setX(5.0);
    check("dim1 : setX", approx(v1.getX(), 5.0));
}

void testPlusEgalMoinsEgal() {
    std::cout << "\n=== += et -= ===\n";

    // dim 3
    Vecteur a3(1,2,3), b3(4,5,6);
    a3 += b3;
    check("dim3 : += x", approx(a3.getX(), 5.0));
    check("dim3 : += y", approx(a3.getY(), 7.0));
    check("dim3 : += z", approx(a3.getZ(), 9.0));
    a3 -= b3;
    check("dim3 : -= x", approx(a3.getX(), 1.0));
    check("dim3 : -= y", approx(a3.getY(), 2.0));
    check("dim3 : -= z", approx(a3.getZ(), 3.0));

    // dim 2
    Vecteur a2(1,2), b2(3,4);
    a2 += b2;
    check("dim2 : += x", approx(a2.getX(), 4.0));
    check("dim2 : += y", approx(a2.getY(), 6.0));
    a2 -= b2;
    check("dim2 : -= x", approx(a2.getX(), 1.0));
    check("dim2 : -= y", approx(a2.getY(), 2.0));

    // dim 1
    Vecteur a1(3.0), b1(7.0);
    a1 += b1;
    check("dim1 : += x", approx(a1.getX(), 10.0));
    a1 -= b1;
    check("dim1 : -= x", approx(a1.getX(), 3.0));
}

void testOpsVecteur() {
    std::cout << "\n=== Ops vecteur/vecteur ===\n";

    // dim 3
    Vecteur a(1,2,3), b(4,5,6);
    Vecteur add = a + b;
    check("dim3 : + x", approx(add.getX(), 5.0));
    check("dim3 : + y", approx(add.getY(), 7.0));
    check("dim3 : + z", approx(add.getZ(), 9.0));

    Vecteur sub = a - b;
    check("dim3 : - x", approx(sub.getX(), -3.0));
    check("dim3 : - y", approx(sub.getY(), -3.0));
    check("dim3 : - z", approx(sub.getZ(), -3.0));

    Vecteur mul = a * b;
    check("dim3 : * x", approx(mul.getX(), 4.0));
    check("dim3 : * y", approx(mul.getY(), 10.0));
    check("dim3 : * z", approx(mul.getZ(), 18.0));

    Vecteur div = b / a;
    check("dim3 : / x", approx(div.getX(), 4.0));
    check("dim3 : / y", approx(div.getY(), 2.5));
    check("dim3 : / z", approx(div.getZ(), 2.0));

    // dim 2
    Vecteur a2(2,4), b2(1,2);
    check("dim2 : + x", approx((a2+b2).getX(), 3.0));
    check("dim2 : + y", approx((a2+b2).getY(), 6.0));
    check("dim2 : - x", approx((a2-b2).getX(), 1.0));
    check("dim2 : * x", approx((a2*b2).getX(), 2.0));
    check("dim2 : / x", approx((a2/b2).getX(), 2.0));

    // dim 1
    Vecteur a1(6.0), b1(3.0);
    check("dim1 : + x", approx((a1+b1).getX(), 9.0));
    check("dim1 : - x", approx((a1-b1).getX(), 3.0));
    check("dim1 : * x", approx((a1*b1).getX(), 18.0));
    check("dim1 : / x", approx((a1/b1).getX(), 2.0));
}

void testOpsScalaire() {
    std::cout << "\n=== Ops vecteur/scalaire ===\n";

    Vecteur v3(2,4,6);
    check("dim3 : v+s x", approx((v3+1.0).getX(), 3.0));
    check("dim3 : v+s y", approx((v3+1.0).getY(), 5.0));
    check("dim3 : v+s z", approx((v3+1.0).getZ(), 7.0));
    check("dim3 : v-s x", approx((v3-1.0).getX(), 1.0));
    check("dim3 : v*s x", approx((v3*2.0).getX(), 4.0));
    check("dim3 : v*s z", approx((v3*2.0).getZ(), 12.0));
    check("dim3 : v/s x", approx((v3/2.0).getX(), 1.0));
    check("dim3 : v/s z", approx((v3/2.0).getZ(), 3.0));

    // scalaire à gauche
    check("dim3 : s+v x", approx((1.0+v3).getX(), 3.0));
    check("dim3 : s-v x", approx((1.0-v3).getX(), -1.0));
    check("dim3 : s*v x", approx((2.0*v3).getX(), 4.0));
    check("dim3 : s/v x", approx((8.0/v3).getX(), 4.0));

    Vecteur v2(2,4);
    check("dim2 : v*s y", approx((v2*3.0).getY(), 12.0));
    check("dim2 : s*v y", approx((3.0*v2).getY(), 12.0));

    Vecteur v1(5.0);
    check("dim1 : v*s x", approx((v1*2.0).getX(), 10.0));
    check("dim1 : s*v x", approx((2.0*v1).getX(), 10.0));
}

void testUnaire() {
    std::cout << "\n=== Opérateur unaire - ===\n";

    Vecteur v3(1,2,3);
    Vecteur n3 = -v3;
    check("dim3 : -v x", approx(n3.getX(), -1.0));
    check("dim3 : -v y", approx(n3.getY(), -2.0));
    check("dim3 : -v z", approx(n3.getZ(), -3.0));

    Vecteur v2(3,4);
    Vecteur n2 = -v2;
    check("dim2 : -v x", approx(n2.getX(), -3.0));
    check("dim2 : -v y", approx(n2.getY(), -4.0));

    Vecteur v1(7.0);
    check("dim1 : -v x", approx((-v1).getX(), -7.0));
}

void testPS() {
    std::cout << "\n=== Produit scalaire ===\n";

    Vecteur a3(1,2,3), b3(4,5,6);
    check("dim3 : ps", approx(a3.ps(b3), 32.0));  // 1*4+2*5+3*6

    Vecteur a2(1,2), b2(3,4);
    check("dim2 : ps", approx(a2.ps(b2), 11.0));  // 1*3+2*4

    Vecteur a1(3.0), b1(5.0);
    check("dim1 : ps", approx(a1.ps(b1), 15.0));
}

void testDist() {
    std::cout << "\n=== Distance euclidienne ===\n";

    Vecteur a3(1,2,3), b3(4,6,3);
    // sqrt((3)^2+(4)^2+(0)^2) = 5
    check("dim3 : dist", approx(a3.dist(b3), 5.0));

    Vecteur a2(0,0), b2(3,4);
    check("dim2 : dist", approx(a2.dist(b2), 5.0));

    Vecteur a1(1.0), b1(4.0);
    check("dim1 : dist", approx(a1.dist(b1), 3.0));
}

void testApply() {
    std::cout << "\n=== Apply ===\n";

    Vecteur v3(1,4,9);
    v3.apply([](double x){ return std::sqrt(x); });
    check("dim3 : apply sqrt x", approx(v3.getX(), 1.0));
    check("dim3 : apply sqrt y", approx(v3.getY(), 2.0));
    check("dim3 : apply sqrt z", approx(v3.getZ(), 3.0));

    Vecteur v2(2,3);
    v2.apply([](double x){ return x*x; });
    check("dim2 : apply carre x", approx(v2.getX(), 4.0));
    check("dim2 : apply carre y", approx(v2.getY(), 9.0));

    Vecteur v1(5.0);
    v1.apply([](double x){ return x+10; });
    check("dim1 : apply +10 x", approx(v1.getX(), 15.0));
}

void testDiff() {
    std::cout << "\n=== Diff ===\n";

    Vecteur a3(1,2,3), b3(4,6,9);
    check("dim3 : diffX", approx(a3.diffX(b3), 3.0));  // 4-1
    check("dim3 : diffY", approx(a3.diffY(b3), 4.0));  // 6-2
    check("dim3 : diffZ", approx(a3.diffZ(b3), 6.0));  // 9-3

    Vecteur a2(1,2), b2(4,6);
    check("dim2 : diffX", approx(a2.diffX(b2), 3.0));
    check("dim2 : diffY", approx(a2.diffY(b2), 4.0));

    Vecteur a1(1.0), b1(4.0);
    check("dim1 : diffX", approx(a1.diffX(b1), 3.0));
}


// ── main ─────────────────────────────────────────────────────────────────────

int main() {
    testConstructeurs();
    testSetters();
    testPlusEgalMoinsEgal();
    testOpsVecteur();
    testOpsScalaire();
    testUnaire();
    testPS();
    testDist();
    testApply();
    testDiff();

    std::cout << "\n============================\n";
    std::cout << "PASSED : " << passed << "\n";
    std::cout << "FAILED : " << failed << "\n";
    std::cout << "============================\n";

    return failed == 0 ? 0 : 1;
}
