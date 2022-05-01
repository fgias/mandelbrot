#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Bitmap.h"
#include "Mandelbrot.h"
using namespace std;
using namespace fgias;

int main() {

    int const WIDTH = 800;
    int const HEIGHT = 600;

    Bitmap bitmap(WIDTH, HEIGHT);

    unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{});
    unique_ptr<int[]> fractal(new int[WIDTH*HEIGHT]{});

    for (int y=0; y<HEIGHT; y++) {
        for (int x=0; x<WIDTH; x++) {
            double xFractal = (x - WIDTH/2 - 200) * 2.0/HEIGHT;
            double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;
            
            int iters = Mandelbrot::getIterations(xFractal, yFractal);
            cout << iters << endl;

            if (iters != Mandelbrot::MAX_ITERATIONS) {
                histogram[iters]++;
            }
            fractal[y*WIDTH + x] = iters;
        }
    }

    int total = 0;
    for(int i = 0; i<Mandelbrot::MAX_ITERATIONS; i++) {
        total += histogram[i];
    }

    for (int y=0; y<HEIGHT; y++) {
        for (int x=0; x<WIDTH; x++) {
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iters = fractal[y*WIDTH + x];

            if (iters != Mandelbrot::MAX_ITERATIONS) {
                double hue = 0.;
                for (int i=0; i<=iters; i++) {
                    hue += ((double)histogram[i])/total;
                }

                green = pow(255, hue);
            }

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