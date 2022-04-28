#include <complex>
#include "Mandelbrot.h"
using namespace std;
#include<iostream>
namespace fgias {

Mandelbrot::Mandelbrot() {

}

Mandelbrot::~Mandelbrot() {

}

int Mandelbrot::getIterations(double x, double y) {
    complex<double> c(x, y);
    complex<double> z = 0;

    int iters = 0;

    while (iters < MAX_ITERATIONS) {
        z = z*z + c;
        if (abs(z) > 2) {
            break;
        }
        iters++;
    }

    return iters;
}


}