#include <iostream>
#include "FractalCreator.h"
using namespace std;
using namespace fgias;

int main() {
    
    FractalCreator fractalCreator(800, 600);

    fractalCreator.addRange(0.0, RGB(0, 0, 0));
    fractalCreator.addRange(0.3, RGB(255, 0, 0));
    fractalCreator.addRange(0.5, RGB(0, 255, 0));
    fractalCreator.addRange(1.0, RGB(0, 0, 255));

    fractalCreator.addZoom(Zoom(295, 202, 0.1));
    fractalCreator.addZoom(Zoom(312, 304, 0.1));

    fractalCreator.run("out/test.bmp");

    cout << "Finished." << endl;

    return 0;
}