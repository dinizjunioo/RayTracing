#include <iostream>
#include <vector>
#include "BackgroundColor.h"

using std::cout;

int main(int argc, char **argv)
{

     // Image

    int image_width = 400;
    int image_height = 200;

    // Render

    std::vector<RGBColor> colors = {{0,0,255},{0,255,0},{255,255,0},{255,0,0}};

    // for (const auto& color : colors) {
    //     std::cout << static_cast<int>(color.r) << " " 
    //               << static_cast<int>(color.g) << " " 
    //               << static_cast<int>(color.b) << " \n";
    // }
    std::unique_ptr<BackgroundColor> back_color = std::make_unique<BackgroundColor>(colors);

    
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >=0; --j) {
        for (int i = 0; i < image_width; ++i) {
            RGBColor teste = back_color->sampleUV(float(i) / (image_width   - 1), float(j) / (image_height - 1));
            teste.b = 0.0;
             std::cout << static_cast<int>(teste.r) << " " 
                  << static_cast<int>(teste.g) << " " 
                   << static_cast<int>(teste.b) << '\n';
        }
    }
}
