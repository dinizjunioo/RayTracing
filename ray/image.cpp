#include <bits/stdc++.h>
#include "BackgroundColor.h"

using byte = unsigned char;
using real_type = float;
using std::cout;
using std::endl;

/**
 * @brief 
 *  Linear interpolation 
 * @param v0 -> ponto A, origem.  
 * @param v1 -> ponto B
 * @param t -> nosso escalar que vai ficar sendo alterada
 * dentro de um intervalo (no nosso caso, RGB => [0,255]) 
 * @return byte 
 */

byte lerp (byte v0, byte v1, real_type t)
{
    // f(t) = A + t(B - A) => A + tB - tA => tB + (1-t)A
    return (1-t) * v0 + t * v1; 
}


int main(int argc, char **argv){

    int largura = 400;
    int altura = 200;

    std::cout << "P3\n" << largura << ' ' << altura << "\n255\n";

    // for (int i = altura-1; i >= 0; --i)
    // {
    //     //real_type v = static_cast<real_type>(255.999 * i / (altura - 1));
    //     real_type v = (real_type)(i) / (real_type)(altura - 1);
    //     for (int j = 0; j < largura; ++j)
    //     {
    //         real_type u = (real_type)(j) / (largura - 1);


    //         RGBColor pixel;
    //         pixel.r = lerp(0, 255, u); // Interpola de vermelho (255) para preto (0) em direção a j
    //         pixel.g = lerp(0, 255, u); // Interpola de preto (0) para verde (255) em direção a i
    //         pixel.b = lerp(0, 0, v);   // Não há variação de azul

    //         std::cout << static_cast<int>(pixel.r) << ' '
    //                   << static_cast<int>(pixel.g) << ' '
    //                   << static_cast<int>(pixel.b) << '\n';
    //     }
    // }


    RGBColor bl = {255, 0, 0}; // Vermelho
    RGBColor tl = {0, 255, 0}; // Verde
    RGBColor tr = {0, 0, 255}; // Azul
    RGBColor br = {255, 255, 0}; // Amarelo

    // Criando um vetor com as cores dos cantos
    std::vector<RGBColor> colors = {bl, tl, tr, br};

    // Criando um objeto BackgroundColor com as cores dos cantos
    BackgroundColor bgColor (colors);


    // Iterando sobre as coordenadas do raster e amostrando cores
    for (int i = 0; i <= 10; ++i) {
        for (int j = 0; j <= 10; ++j) {
            // Calculando as coordenadas UV normalizadas
            real_type u = static_cast<real_type>(j) / 10.0f;
            real_type v = static_cast<real_type>(i) / 10.0f;

            // Amostrando a cor para as coordenadas UV e imprimindo-a
            RGBColor sampledColor = bgColor.sampleUV(u, v);

             std::cout << static_cast<int>(sampledColor.r) << ' '
                       << static_cast<int>(sampledColor.g) << ' '
                       << static_cast<int>(sampledColor.b) << '\n';
        }
    }


    return 0;
}