
#include "BackgroundColor.h"

// Implementação do método construtor
BackgroundColor::BackgroundColor(const std::vector<RGBColor> &colors) {
    // Verifica se foram fornecidas as quatro cores esperadas
    if (colors.size() != 4) {
        throw std::invalid_argument("Fornecidas cores inválidas. São necessárias quatro cores.");
    }

    // Copia as cores fornecidas para os cantos correspondentes
    for (size_t i = 0; i < 4; ++i) {
        corners[i] = colors[i];
    }
}

// Implementação do método de interpolação linear
RGBColor BackgroundColor::lerp(const RGBColor &A, const RGBColor &B, real_type t) const {
    // Aplica a interpolação linear nos componentes RGB de A e B
    RGBColor result;
    result.r = static_cast<unsigned char>((1 - t) * A.r + t * B.r);
    result.g = static_cast<unsigned char>((1 - t) * A.g + t * B.g);
    result.b = static_cast<unsigned char>((1 - t) * A.b + t * B.b);
    return result;
}

// Implementação do método para amostrar uma cor com base nas coordenadas raster
RGBColor BackgroundColor::sampleUV(real_type u, real_type v) const {
    // Interpolação linear horizontal entre os cantos inferiores (bl e br)
    RGBColor bottom = lerp(corners[bl], corners[br], u);

    // Interpolação linear horizontal entre os cantos superiores (tl e tr)
    RGBColor top = lerp(corners[tl], corners[tr], u);

    // Interpolação linear vertical entre as cores interpoladas horizontalmente
    return lerp(bottom, top, v);
}