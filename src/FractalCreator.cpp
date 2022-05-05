#include "FractalCreator.h"
#include <assert.h>

namespace fgias {

void FractalCreator::addRange(double rangeEnd, const RGB& rgb) {
    _ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
    _colors.push_back(rgb);

    if (_bGotFirstRange) {
        _rangeTotals.push_back(0);
    }
    _bGotFirstRange = true;
}

int FractalCreator::getRange(int iterations) const {
	int range = 0;

	for(int i=1; i < _ranges.size(); i++) {

		range = i;

		if(_ranges[i] > iterations) {
			break;
		}

	}

	range--;

	assert(range > -1);
	assert(range < _ranges.size());

	return range;
}

void FractalCreator::addZoom(const Zoom& zoom) {
    _zoomList.add(zoom);
}

void FractalCreator::run(std::string name) {
    calculateIterations();
    calculateTotalIterations();
    calculateRangeTotals();
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
        _zoomList.add(Zoom(_width/2, _height/2, 4.0/_width));
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

void FractalCreator::calculateRangeTotals() {

    int rangeIndex = 0;

    for (int i=0; i<Mandelbrot::MAX_ITERATIONS; i++) {
        int pixels = _histogram[i];

        if (i >= _ranges[rangeIndex+1]) {
            rangeIndex++;
        }

        _rangeTotals[rangeIndex] += pixels;
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

            int iters = _fractal[y*_width + x];
            int range = getRange(iters); 
            int rangeTotal = _rangeTotals[range];
            int rangeStart = _ranges[range];

            RGB& startColor = _colors[range];
            RGB& endColor = _colors[range+1];
            RGB colorDiff = endColor - startColor;

            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            if (iters != Mandelbrot::MAX_ITERATIONS) {
                int totalPixels = 0;
                for (int i=rangeStart; i<=iters; i++) {
                    totalPixels += _histogram[i];
                }

                red = startColor._r + colorDiff._r * (double)totalPixels/rangeTotal;
                green = startColor._g + colorDiff._g * (double)totalPixels/rangeTotal;
                blue = startColor._b + colorDiff._b * (double)totalPixels/rangeTotal;

            }

            _bitmap.setPixel(x, y, red, green, blue);
        }
    }
}

void FractalCreator::writeBitmap(std::string name) {
    _bitmap.write(name);
}

}