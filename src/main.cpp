#include <iostream>
#include <SDL.h>
#include "FractalCreator.h"
using namespace std;
using namespace fgias;

int main() {

    srand(time(NULL));

    Screen screen;

    if (screen.init() == false) {
        cout << "Error initializing SDL." << endl;
    }

    int height=600;

    FractalCreator fractalCreator(Screen::SCREEN_WIDTH, Screen::SCREEN_HEIGHT);

    // fractalCreator.addZoom(Zoom(295, height - 202, 0.1));
    // fractalCreator.addZoom(Zoom(312, height - 304, 0.1));

    fractalCreator.run("test.bmp");

    fractalCreator.drawFractalScreen(screen);

    screen.update();

    while (true) {
        // check for events
        if (screen.processEvents() == false) {
            break;
        }
    };  

    screen.close();

    cout << "Finished." << endl;

    return 0;
}