#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "FractalCreator.h"
using namespace std;
using namespace fgias;

int main() {

    int const _width = 800;
    int const _height = 600;

    FractalCreator fractalCreator(_width, _height);

    Bitmap _bitmap(_width, _height);

    ZoomList _zoomList(_width, _height);
    _zoomList.add(Zoom(_width/2, _height/2, 4.0/_width));
    _zoomList.add(Zoom(295, _height - 202, 0.1));
    _zoomList.add(Zoom(312, _height - 304, 0.1));

    unique_ptr<int[]> _histogram(new int[Mandelbrot::MAX_ITERATIONS]{});
    unique_ptr<int[]> _fractal(new int[_width*_height]{});

    for (int y=0; y<_height; y++) {
        for (int x=0; x<_width; x++) {
            pair<double, double> coords = _zoomList.doZoom(x, y);
            
            int iters = Mandelbrot::getIterations(coords.first, coords.second);
            // cout << iters << endl;

            if (iters != Mandelbrot::MAX_ITERATIONS) {
                _histogram[iters]++;
            }
            _fractal[y*_width + x] = iters;
        }
    }

    int total = 0;
    for(int i = 0; i<Mandelbrot::MAX_ITERATIONS; i++) {
        total += _histogram[i];
    }

    for (int y=0; y<_height; y++) {
        for (int x=0; x<_width; x++) {
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iters = _fractal[y*_width + x];

            if (iters != Mandelbrot::MAX_ITERATIONS) {
                double hue = 0.;
                for (int i=0; i<=iters; i++) {
                    hue += ((double)_histogram[i])/total;
                }

                green = pow(255, hue);
            }

            _bitmap.setPixel(x, y, red, green, blue);
        }
    }

    _bitmap.write("test.bmp");

    cout << "Finished." << endl;

    return 0;
}


/* 

clear; 
g++ -std=c++11 src/main.cpp src/Mandelbrot.cpp src/Bitmap.cpp src/ZoomList.cpp src/FractalCreator.cpp -I include -o bin/exec; 
bin/exec

*/