#include <iostream>
#include "FractalCreator.h"
using namespace std;
using namespace fgias;

int main() {
    
    FractalCreator fractalCreator(800, 600);
    fractalCreator.addZoom(Zoom(295, 202, 0.1));
    fractalCreator.addZoom(Zoom(312, 304, 0.1));

    fractalCreator.run("test.bmp");

    cout << "Finished." << endl;

    return 0;
}


/* 

clear; 
g++ -std=c++11 src/main.cpp src/Mandelbrot.cpp src/Bitmap.cpp \
src/ZoomList.cpp src/FractalCreator.cpp src/RGB.cpp \
-I include -o bin/exec; 
bin/exec

*/