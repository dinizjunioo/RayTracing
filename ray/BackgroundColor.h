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
    /// Each corner has a color associated with.
    RGBColor corners[4]={{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
    /// Corner indices.
    enum Corners_e {
      bl=0, //!< Bottom left corner.
      tl,   //!< Top left corner.
      tr,   //!< Top right corner.
      br    //!< Bottom right corner.
    };

    /// Return the linearly interpolated color in [A;B], based on the parameter \f$0\leq t \leq 1.\f$
    RGBColor lerp( const RGBColor &A, const RGBColor &B, real_type t ) const;

  public:
    BackgroundColor();
    /// Ctro receives a list of four colors, for each corner.
    BackgroundColor( const std::vector< RGBColor >& colors );
    /// Dtro
    ~BackgroundColor() { };
    /// Sample and returns a color, based on the raster coordinate.
    RGBColor sampleUV( real_type u, real_type v ) const;
};

#endif