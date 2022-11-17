#include "vector.hh"

Vector::Vector(const Vector&v)
{
   content_ = std::make_unique<value[]>(v.size());
   for (size_t i = 0; i < v.size(); i++)
   {
    content_[i] = v[i];
   }
   size_ = v.size();
}

Vector& Vector::operator=(const Vector&v)
{
    content_ = std::make_unique<value[]>(v.size());
    for (size_t i = 0; i < v.size(); i++)
    {
        content_[i] = v[i];
    }
    size_ = v.size();
    return *this;
}

Vector::Vector(size_t N)
{
    content_ = std::make_unique<value[]>(N);
    for (size_t i = 0; i < N; i++)
    {
        content_[i] = 0;
    }
    
    size_ = N;
}

Vector::Vector(std::initializer_list<value> l)
{
    content_ = std::make_unique<value[]>(l.size());
    size_ = l.size();
    size_t count = 0;
    for (auto it = l.begin(); it != l.end(); ++it)
    {
        content_[count] = *it;
        ++count;
    }
}

size_t Vector::size() const
{
    return size_;
}

Vector& Vector::operator+=(const Vector& rhs)
{
    if (rhs.size() != size_)
        throw std::runtime_error("Incompatible size");
    
    for (size_t i = 0; i < size_; ++i)
    {
        content_[i] += rhs[i];
    }
    return *this; 
}

Vector& Vector::operator-=(const Vector& rhs)
{
    if (rhs.size() != size_)
        throw std::runtime_error("Incompatible size");
    
    for (size_t i = 0; i < size_; ++i)
    {
        content_[i] -= rhs[i];
    }
    return *this;
}

Vector& Vector::operator+=(value v)
{
    for (size_t i = 0; i < size_; i++)
    {
        content_[i] += v;
    }
    return *this;
}

// Vector& Vector::operator-=(value v)
// {
//     for (size_t i = 0; i < size_; i++)
//     {
//         content_[i] -= v;
//     }
//     return *this;
// }

Vector& Vector::operator*=(value v)
{
    for (size_t i = 0; i < size_; i++)
    {
        content_[i] *= v;
    }
    return *this;
}

Vector Vector::operator+(const Vector& rhs) const
{
    if (rhs.size() != size_)
        throw std::runtime_error("Incompatible size");
    
    auto res = Vector(size_);
    for (size_t i = 0; i < size_; i++)
    {
        res[i] = content_[i] + rhs[i];
    }
    return std::move(res);
}

Vector Vector::operator+(value v) const
{
    auto res = Vector(size_);
    for (size_t i = 0; i < size_; i++)
    {
        res[i] = content_[i] + v;
    }
    return std::move(res);
}

value Vector::operator*(const Vector& rhs) const
{
    if (rhs.size() != size_)
        throw std::runtime_error("Incompatible size");
    value res = 0;
    for (size_t i = 0; i < size_; i++)
    {
        res += content_[i] * rhs[i];
    }
    return res;
}

Vector Vector::operator*(value v) const
{
    auto res = Vector(size_);
    for (size_t i = 0; i < size_; i++)
    {
        res[i] = content_[i] * v;
    }
    return std::move(res);
}

value& Vector::operator[](size_t idx)
{
    return content_[idx];
}

value Vector::operator[](size_t idx) const
{
    return content_[idx];
}

Vector operator*(const value& s, const Vector& v)
{
    auto res = Vector(v.size());
    for (size_t i = 0; i < v.size(); i++)
    {
        res[i] = v[i] * s;
    }
    return std::move(res);
}

Vector operator+(const value& s, const Vector& v)
{
    auto res = Vector(v.size());
    for (size_t i = 0; i < v.size(); i++)
    {
        res[i] = v[i] + s;
    }
    return std::move(res);
}

std::ostream& operator<<(std::ostream& o, const Vector& v)
{
    o << "{";
    for (size_t i = 0; i < v.size(); ++i)
    {
        o << v[i];
        if (i != v.size() - 1)
            o << ",";
    }
    o << "}";
    return o;
}

Vector::Vector(Vector&& other)
{
    std::swap(content_, other.content_);
    std::swap(size_, other.size_);
}

Vector& Vector::operator=(Vector&& other)
{
    std::swap(content_, other.content_);
    std::swap(size_, other.size_);
    return *this;
}