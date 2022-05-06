#include <iostream>
#include <SDL.h>
#include "FractalCreator.h"
using namespace std;
using namespace fgias;

int main() {

    Screen screen;
    if (screen.init() == false) {
        cout << "Error initializing SDL." << endl;
    }

    FractalCreator fractalCreator(Screen::SCREEN_WIDTH, Screen::SCREEN_HEIGHT);
    fractalCreator.run(screen);

    while (true) {
        // check for events
        if (fractalCreator.processEvents(screen) == false) {
            break;
        }

    };  

    screen.close();

    return 0;
}