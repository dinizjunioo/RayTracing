#ifndef _VECTOR3_H_
#define _VECTOR3_H_

#include <iostream>

class Vector3{

    public:

    double e[3];

    Vector3(): e{0,0,0} { /* --- */ std::cout << "criei meu vetor zerado" << std::endl; }
    Vector3(double x, double y, double z) : e{x, y, z} { /* --- */ std::cout << "criei meu vetor" << std::endl; }

    inline int X()const{ return e[0]; }
    inline int Y()const{ return e[1]; }
    inline int Z()const{ return e[2]; }


    inline friend std::ostream& operator<<(std::ostream& os, const Vector3 vec)
    {
        return os << "[" << vec.X() << "," <<  vec.Y() << "," << vec.Z() << "]";
    }

};
#endif