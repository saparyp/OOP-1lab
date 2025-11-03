#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <initializer_list>
#include <string>
#include <iterator>

class Array {
private:
    size_t size_;
    unsigned char* data_;

public:
    Array();
    Array(const size_t& n, unsigned char t = 0);
    Array(const std::initializer_list<unsigned char>& t);
    Array(const std::string& t);
    
    template<typename InputIterator>
    Array(InputIterator first, InputIterator last);
    
    Array(const Array& other);
    Array(Array&& other) noexcept;
    virtual ~Array() noexcept;

    size_t getSize() const;
    unsigned char getAt(size_t index) const;

    //арифметические операции
    Array add(const Array& other) const;
    Array subtract(const Array& other) const;
    Array copy() const;

    //операции с присваиванием
    Array& addAndAssign(const Array& other);
    Array& subtractAndAssign(const Array& other);

    //операции сравнения
    bool greaterThan(const Array& other) const;
    bool lessThan(const Array& other) const;
    bool equals(const Array& other) const;

    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;
};

template<typename InputIterator>//шаблонный конструктор
Array::Array(InputIterator first, InputIterator last) 
    : size_(std::distance(first, last)), data_(new unsigned char[size_]) {
    size_t i = 0;
    for (auto it = first; it != last; ++it, ++i) {
        data_[i] = *it;
    }
}

#endif