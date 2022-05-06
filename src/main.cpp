#include <iostream>
#include <SDL.h>
#include "FractalCreator.h"
using namespace std;
using namespace fgias;

int main() {

    int t = time(NULL);

    Screen screen;
    if (screen.init() == false) {
        cout << "Error initializing SDL." << endl;
    }

    FractalCreator fractalCreator(Screen::SCREEN_WIDTH, Screen::SCREEN_HEIGHT);

    fractalCreator.addZoom(Zoom(119, 366, 0.1));
    fractalCreator.run(screen);

    while (true) {
        // check for events
        if (screen.processEvents() == false) {
            break;
        }

        if (time(NULL) > t + 4) { // test
            fractalCreator.addZoom(Zoom(312, 304, 0.5));
            fractalCreator.run(screen);
        }

    };  

    screen.close();

    return 0;
}