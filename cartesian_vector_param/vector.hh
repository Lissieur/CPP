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
    Vector()
    {
        for (size_t i = 0; i < NDIM; ++i)
            v[i] = 0;
    }

    Vector(std::initializer_list<value> l)
    {
        size_t i = 0;
        for (auto it = l.begin(); it != l.end(); ++it)
        {
            v[i] = *it;
            ++i;
        }
    }
    // possibly more

// Public Member functions here
    value operator[](size_t idx) const;
    value& operator[](size_t idx);

    Vector& operator+=(const Vector& rhs);
    Vector operator+(const Vector& rhs);

    Vector& operator-=(const Vector& rhs);
    Vector operator-(const Vector& rhs);

    value operator*(const Vector& rhs);
    // More to go

private:
// Private Member functions here
    value v[NDIM];
// Member variables are ALWAYS private, and they go here
};

// Nonmember function operators go here
std::ostream& operator<<(std::ostream& os, const Vector& v);
Vector operator*(Vector& rhs, const value number);
Vector operator*=(Vector& rhs, const value number);
Vector operator+=(Vector& rhs, const value number);


