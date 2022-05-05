#ifndef RGB_H_
#define RGB_H_

namespace fgias {

struct RGB {
    double _r;
    double _g;
    double _b;

    RGB(double r, double g, double b);
};

RGB operator-(const RGB& c1, const RGB& c2);

}

#endif