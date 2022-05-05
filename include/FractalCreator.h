#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include "ZoomList.h"
#include "Mandelbrot.h"
#include "Bitmap.h"

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

private:
    void calculateIterations();
    void calculateTotalIterations();
    void drawFractal();
    void writeBitmap(std::string name);

public:
    FractalCreator(int width, int height);
    virtual ~FractalCreator();
    void addZoom(const Zoom& zoom);
    void run(std::string name);
};

}

#endif