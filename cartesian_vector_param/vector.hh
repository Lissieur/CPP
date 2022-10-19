#pragma once

#include <ostream>

#include "config.h"

class Vector
{
public:
// DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
//

// Add suitable constructors
    Vector();
    Vector(std::initializer_list<int>);//on doit en avoir au moins un qui accepte les std::initializer_list
    // possibly more

// Public Member functions here
    Vector& operator += (const Vector& rhs);
    Vector& operator +=(const value& rhs);

    Vector& operator -= (const Vector& rhs);
    Vector& operator *=(const value& rhs);

    inline value& operator[](size_t n)  {
#ifdef CHECKS
    if (n > NDIM) throw std::out_of_range("Not a valid index : " + std::to_string(n));
#endif
    return data[n];
}
    inline const value& operator[](size_t n) const {
#ifdef CHECKS
    if (n > NDIM) throw std::out_of_range("Not a valid index : " + std::to_string(n));
#endif
    return data[n];
}
private:
    value data[NDIM];
};
std::ostream& operator<<(std::ostream &stream, const Vector& vec);
Vector operator + (const Vector& vec1, const Vector& vec2);
Vector operator*(const Vector& vec1, const value& vec2);
Vector operator*(const value& vec1, const Vector& v2);
value operator*(const Vector& vec1, const Vector& vec2);