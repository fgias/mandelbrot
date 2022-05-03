#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include "Zoom.h"

namespace fgias {

class FractalCreator {
private:
    
public:
    FractalCreator(int width, int height);
    virtual ~FractalCreator();

    void calculateIterations();
    void drawFractal();
    void addZoom(const Zoom& zoom);
    void writeBitmap(std::string name);
};

}

#endif