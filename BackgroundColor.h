#ifndef _BACKGROUND_COLOR_H_
#define _BACKGROUND_COLOR_H_


#include <bits/stdc++.h>

using byte = unsigned char;
using real_type = float;

struct RGBColor{
        byte r = 0;
        byte g = 0;
        byte b = 0;
    }; 

class BackgroundColor {

  private:
    /// Cada canto tem uma cor associada.
    RGBColor corners[4]={{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
    /// Corner indices.
    enum Corners_e {
      bl=0, //!< Bottom left corner   --- canto inferior esquerdo
      tl,   //!< Top left corner      --- canto superior esquerdo
      tr,   //!< Top right corner     --- canto superior direito
      br    //!< Bottom right corner  --- canto inferior direito
    };

    /// retornar a cor interpolada linearmente em [A;B], baseada no parametro t onde t \in [0,1] intervalo real
    RGBColor lerp( const RGBColor &A, const RGBColor &B, real_type t ) const;

  public:
    
    BackgroundColor();
    /// recebe uma lista de quatro cores, para cada canto.
    BackgroundColor( const std::vector< RGBColor >& colors );
    /// destrutor
    ~BackgroundColor() { };
    /// Amostra e retorna uma cor, com base na coordenada raster.
    RGBColor sampleUV( real_type u, real_type v ) const;
};

#endif