#include <iostream>
#include "Bitmap.h"
using namespace std;
using namespace fgias;

int main() {

    int const WIDTH = 800;
    int const HEIGHT = 600;

    Bitmap bitmap(WIDTH, HEIGHT);

    bitmap.setPixel(WIDTH/5, HEIGHT/5, 255, 255, 255);
    for (int i=0; i<WIDTH; i++) {
        for (int j=0; j<HEIGHT; j++) {
            bitmap.setPixel(i, j, 255, 0, 0);
        }
    }

    bitmap.write("test.bmp");

    cout << "Finished." << endl;

    return 0;
}


/* 

clear; 
g++ -std=c++11 main.cpp Bitmap.cpp -o exec; 
./exec

*/