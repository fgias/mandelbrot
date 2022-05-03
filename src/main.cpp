#include <iostream>
#include "FractalCreator.h"
using namespace std;
using namespace fgias;

int main() {

    int height=600;

    FractalCreator fractalCreator(800, 600);

    fractalCreator.addZoom(Zoom(295, height - 202, 0.1));
    fractalCreator.addZoom(Zoom(312, height - 304, 0.1));

    fractalCreator.calculateIterations();
    fractalCreator.calculateTotalIterations();
    fractalCreator.drawFractal();
    fractalCreator.writeBitmap("test.bmp");

    cout << "Finished." << endl;

    return 0;
}


/* 

clear; 
g++ -std=c++11 src/main.cpp src/Mandelbrot.cpp src/Bitmap.cpp src/ZoomList.cpp src/FractalCreator.cpp -I include -o bin/exec; 
bin/exec

*/