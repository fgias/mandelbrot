#include <iostream>
#include <cstdint>
#include "Bitmap.h"
#include "Mandelbrot.h"
using namespace std;
using namespace fgias;

int main() {

    int const WIDTH = 800;
    int const HEIGHT = 600;

    Bitmap bitmap(WIDTH, HEIGHT);

    for (int y=0; y<HEIGHT; y++) {
        for (int x=0; x<WIDTH; x++) {
            double xFractal = (x - WIDTH/2 - 200) * 2.0/HEIGHT;
            double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;
            
            int iters = Mandelbrot::getIterations(xFractal, yFractal);
            cout << iters << endl;

            uint8_t color = ((double)iters/Mandelbrot::MAX_ITERATIONS * 256);

            uint8_t red = color * color;
            uint8_t green = color;
            uint8_t blue = color * color * color;

            bitmap.setPixel(x, y, red, green, blue);
        }
    }

    bitmap.write("test.bmp");

    cout << "Finished." << endl;

    return 0;
}


/* 

clear; 
g++ -std=c++11 src/main.cpp src/Mandelbrot.cpp src/Bitmap.cpp -I include -o bin/exec; 
bin/exec

*/