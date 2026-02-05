// ./resize.exe horses.ppm horses_400x250.ppm 400 250
#include "processing.hpp"
#include "Matrix.hpp"
#include "Image.hpp"
#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
    if(!(argc == 4 || argc == 5)){
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
     << "WIDTH and HEIGHT must be less than or equal to original" << endl;
     return 1;
    }
    
    Image img;
    ifstream is(argv[1]);

    if (!is.is_open()) {
        cout << "Error opening file: " << argv[1] << endl;
    return 1;
    }

    Image_init(&img, is);

    //void Image_init(Image* img, std::istream& is) {
    if(!(atoi(argv[4]) > 0) || !(atoi(argv[4]) <= Image_width(&img))){
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
     << "WIDTH and HEIGHT must be less than or equal to original" << endl;
     return 1;
    }
    if(!(atoi(argv[5]) > 0) || !(atoi(argv[4]) <= Image_height(&img))){
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
     << "WIDTH and HEIGHT must be less than or equal to original" << endl;
     return 1;
    }

    seam_carve(&img,atoi(argv[4]), atoi(argv[5]));
}