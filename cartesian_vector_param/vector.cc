#include "vector.hh"


value Vector::operator[](size_t idx) const{
    return v[idx];
}

value& Vector::operator[](size_t idx){
    return v[idx];
}

Vector& Vector::operator+=(const Vector& rhs){
    for (size_t i = 0; i < NDIM; ++i)
    {
        v[i] += rhs.v[i];
    }
    return *this;
}

Vector Vector::operator+(const Vector& rhs){
    auto res = Vector();
    for (size_t i = 0; i < NDIM; ++i)
    {
        res.v[i] = v[i] + rhs.v[i];
    }
    return res;
}

Vector& Vector::operator-=(const Vector& rhs){
    for (size_t i = 0; i < NDIM; ++i)
    {
        v[i] -= rhs.v[i];
    }
    return *this;
}

Vector Vector::operator-(const Vector& rhs){
    auto res = Vector();
    for (size_t i = 0; i < NDIM; ++i)
    {
        res.v[i] = v[i] - rhs.v[i];
    }
    return res;
    
}

value Vector::operator*(const Vector& rhs){
    value res = 0;
    for (size_t i = 0; i < NDIM; ++i)
    {
        res += v[i] * rhs[i];
    }
    return res;
}

std::ostream& operator<<(std::ostream& os, const Vector& v){
    os << "{";
    for (size_t i = 0; i < NDIM; ++i)
    {
        os << v[i];
        if (i != NDIM - 1)
            os << ",";
    }
    os << "}";
    return os;
}

Vector operator*(Vector& rhs, const value number){
    auto res = Vector();
    for (size_t i = 0; i < NDIM; ++i)
    {
        res[i] = rhs[i] * number;
    }
    return res;
}

Vector operator*=(Vector& rhs, const value number){
    for (size_t i = 0; i < NDIM; ++i)
    {
        rhs[i] *= number;
    }
    return rhs;
}

Vector operator+=(Vector& rhs, const value number){
    for (size_t i = 0; i < NDIM; ++i)
    {
        rhs[i] += number;
    }
    return rhs;
}






