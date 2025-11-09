#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <initializer_list>
#include <string>

class Array {
private:
    size_t size_;
    unsigned char* data_;

public:
    Array();
    Array(const size_t& n, unsigned char t = 0);
    Array(const std::initializer_list<unsigned char>& t);
    Array(const std::string& t);
    Array(const Array& other);
    Array(Array&& other) noexcept;
    virtual ~Array() noexcept;

    size_t getSize() const;
    unsigned char getAt(size_t index) const;

    Array copy() const;

    bool greaterThan(const Array& other) const;
    bool lessThan(const Array& other) const;
    bool equals(const Array& other) const;

    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;
};

#endif