#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include <vector>
#include "ZoomList.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "RGB.h"

namespace fgias {

class FractalCreator {
private:
    int _width;
    int _height;
    std::unique_ptr<int[]> _histogram;
    int _total;
    std::unique_ptr<int[]> _fractal;
    Bitmap _bitmap;
    ZoomList _zoomList;

    vector<int> _ranges;
    vector<RGB> _colors;
    vector<int> _rangeTotals;

    bool _bGotFirstRange{false};
    
private:
    void calculateIterations();
    void calculateTotalIterations();
    void calculateRangeTotals();
    void drawFractal();
    void writeBitmap(std::string name);
    int getRange(int iterations) const;

public:
    FractalCreator(int width, int height);
    virtual ~FractalCreator();
    void addZoom(const Zoom& zoom);
    void run(string name);
    void addRange(double rangeEnd, const RGB& rgb);
};

}

#endif