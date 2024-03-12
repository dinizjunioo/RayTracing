#include <iostream>

using std::cout;
using std::endl;

#include "vector3.h"

int main(int argc, char **argv)
{

     // Image

    int image_width = 400;
    int image_height = 200;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        // lerp 
        // 0, 255, 0
        for (int i = 0; i < image_width; ++i) {

            // o r esta entre [0,1]            
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}
