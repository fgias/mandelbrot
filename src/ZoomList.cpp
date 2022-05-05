#include "ZoomList.h"

namespace fgias {

ZoomList::ZoomList(int width, int height): _width(width), _height(height) {
    
}

void ZoomList::add(const Zoom& zoom) {
    zooms.push_back(zoom);

    _xCenter += (zoom._x - _width/2) * _scale;
    _yCenter += -(zoom._y - _height/2) * _scale;

    _scale *= zoom._scale;
};

std::pair<double, double> ZoomList::doZoom(int x, int y) {
    double xFractal = (x - _width/2) * _scale + _xCenter;
    double yFractal = (y - _height/2) * _scale + _yCenter;

    return std::pair<double,double>(xFractal, yFractal);
}

}