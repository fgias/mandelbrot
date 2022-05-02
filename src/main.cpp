#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
using namespace std;
using namespace fgias;

int main() {

    int const WIDTH = 800;
    int const HEIGHT = 600;

    Bitmap bitmap(WIDTH, HEIGHT);

    ZoomList zoomList(WIDTH, HEIGHT);
    zoomList.add(Zoom(WIDTH/2, HEIGHT/2, 4.0/WIDTH));
    zoomList.add(Zoom(295, HEIGHT - 202, 0.1));
    zoomList.add(Zoom(312, HEIGHT - 304, 0.1));

    unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{});
    unique_ptr<int[]> fractal(new int[WIDTH*HEIGHT]{});

    for (int y=0; y<HEIGHT; y++) {
        for (int x=0; x<WIDTH; x++) {
            pair<double, double> coords = zoomList.doZoom(x, y);
            
            int iters = Mandelbrot::getIterations(coords.first, coords.second);
            // cout << iters << endl;

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
g++ -std=c++11 src/main.cpp src/Mandelbrot.cpp src/Bitmap.cpp src/ZoomList.cpp -I include -o bin/exec; 
bin/exec

*/