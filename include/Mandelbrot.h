#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace fgias {

class Mandelbrot {
public:
    static const int MAX_ITERATIONS = 100;

public:
    Mandelbrot();
    virtual ~Mandelbrot();

    static int getIterations(double x, double y);
};

}

#endif