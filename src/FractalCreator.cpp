#include "FractalCreator.h"

namespace fgias {

void FractalCreator::run(std::string name) {
    calculateIterations();
    calculateTotalIterations();
    drawFractal();
    writeBitmap(name);
}

FractalCreator::FractalCreator(int width, int height): 
    _width(width), _height(height),
    _histogram(new int[Mandelbrot::MAX_ITERATIONS]{}), 
    _total(0),
    _fractal(new int[_width*_height]{}),
    _bitmap(_width, _height),
    _zoomList(_width, _height) {
        _zoomList.add(Zoom(_width/2, _height/2, 3.0/_width));
}

FractalCreator::~FractalCreator() {

}

void FractalCreator::calculateIterations() {
    for (int y=0; y<_height; y++) {
        for (int x=0; x<_width; x++) {
            pair<double, double> coords = _zoomList.doZoom(x, y);

            int iters = Mandelbrot::getIterations(coords.first, coords.second);
            // cout << iters << endl;

            if (iters != Mandelbrot::MAX_ITERATIONS) {
                (_histogram)[iters]++;
            }
            _fractal[y*_width + x] = iters;
        }
    }
}

void FractalCreator::calculateTotalIterations() {
    for(int i = 0; i<Mandelbrot::MAX_ITERATIONS; i++) {
        _total += _histogram[i];
    }
}

void FractalCreator::drawFractal() {
    for (int y=0; y<_height; y++) {
        for (int x=0; x<_width; x++) {
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iters = _fractal[y*_width + x];

            if (iters != Mandelbrot::MAX_ITERATIONS) {
                double hue = 0.;
                for (int i=0; i<=iters; i++) {
                    hue += ((double)_histogram[i])/_total;
                }

                green = pow(255, hue);
            }

            _bitmap.setPixel(x, y, red, green, blue);
        }
    }
}

void FractalCreator::addZoom(const Zoom& zoom) {
    _zoomList.add(zoom);
}

void FractalCreator::writeBitmap(std::string name) {
    _bitmap.write(name);
}

}