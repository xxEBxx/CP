#include <iostream>
#include <cmath>
#include <limits>

using namespace std;
double calculateTime(double x, double ys, double ym, double d, double vs, double vm) {
    double ts = sqrt(x * x + ys * ys) / vs;
    double tm = sqrt((d - x) * (d - x) + ym * ym) / vm;
    return ts + tm;
}

double findOptimalX(double d, double ys, double ym, double vs, double vm, int n) {
    double minTime = numeric_limits<double>::max(); // Temps minimal initialisé à un grand nombre
    double optimalX = 0.0; // Valeur optimale de x
    double step = d / n; // Pas pour subdiviser OK
    //iterate all
    for (int i = 0; i <= n; ++i) {
        double x = i * step; // Position actuelle
        double time = calculateTime(x, ys, ym, d, vs, vm); // Calcul du temps pour ce x
        if (time < minTime) {
            minTime = time; // Mettre à jour le temps minimal
            optimalX = x; // Mettre à jour la position optimale
        }
    }

    return optimalX;
}

int main() {
    double d = 10;
    double ys = 5.0;
    double ym = 8.0;
    double vs = 6.0;
    double vm = 3.0;
    int n = 1000;

    double optimalX = findOptimalX(d, ys, ym, vs, vm, n);
    cout << "La position optimale x est : " << optimalX << endl;

    return 0;
}
