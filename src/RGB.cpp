#include "RGB.h"

namespace fgias {

RGB::RGB(double r, double g, double b): _r(r), _g(g), _b(b) {

}

RGB operator-(const RGB& c1, const RGB& c2) {
    return RGB(c1._r - c2._r, c1._g - c2._g, c1._b - c2._b);
}

}