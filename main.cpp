#include <iostream>
#include "Bitmap.h"
using namespace std;
using namespace fgias;

int main() {

    Bitmap bitmap(800,600);
    bitmap.write("test.bmp");

    cout << "Finished." << endl;

    return 0;
}


/* 

clear; 
g++ -std=c++11 main.cpp Bitmap.cpp -o exec; 
./exec

*/