#ifndef ZOOM_H_
#define ZOOM_H_

namespace fgias {

struct Zoom {
    int _x{0};
    int _y{0};
    double _scale{0.0};
    Zoom(int x, int y, double scale): _x(x), _y(y), _scale(scale) {};
};

}

#endif