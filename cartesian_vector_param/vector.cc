#include "vector.hh"

Vector::Vector() : data{0} {}

Vector::Vector(std::initializer_list<value> vals)
{
    size_t i = 0;
    for(const value& val : vals)
    {
        data[i++] = val;
    }
}

Vector &Vector::operator+=(const Vector& rhs)
{
    for (size_t i = 0; i < NDIM; i++)
        data[i] += rhs[i];
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{
    for (size_t i = 0; i < NDIM; i++)
        data[i] -= rhs[i];
    return *this;
}

Vector& Vector::operator+=(const value& rhs)
{
    for (size_t i = 0; i < NDIM; i++)
        data[i] += rhs;
    return *this;
}

Vector& Vector::operator*=(const value& rhs)
{
    for (size_t i = 0; i < NDIM; i++)
        data[i] *= rhs;
    return *this;
}

std::ostream& operator<<(std::ostream &stream, const Vector &vec)
{
    stream << '{';
    for (size_t i = 0; i < NDIM; i++) {
        stream << vec[i];
        if (i < NDIM - 1)
            stream << ',';
    }
    return stream << '}';
}

//Vector add to another one
Vector operator+(const Vector& vec1, const Vector& vec2)
{
    Vector res;
    for (size_t i = 0; i < NDIM; i++)
        res[i] = vec1[i] + vec2[i];
    return res;
}

//vector time a number
Vector operator*(const Vector& vec1, const value& vec2)
{
    Vector res;
    for (size_t i = 0; i < NDIM; i++)
        res[i] = vec1[i] * vec2;
    return res;
}

//number time a vector (other order of the one above)
Vector operator*(const value& vec1, const Vector& vec2)
{
    return vec2 * vec1;
}

//dot product
value operator*(const Vector& vec1, const Vector& vec2)
{
    value result = (value)0;
    for (size_t i = 0; i < NDIM; i++)
        result += vec1[i] * vec2[i];
    return result;
}

value Vector::operator[](size_t idx) const{
    return v[idx];
}

value& Vector::operator[](size_t idx){
    return v[idx];
}