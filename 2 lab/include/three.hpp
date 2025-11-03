#ifndef THREE_HPP
#define THREE_HPP

#include "array.hpp"
#include <string>

class Three {
private:
    Array data_;

    static bool isValidTernaryDigit(unsigned char digit);
    static Array createAlignedArray(const Array& source, size_t target_size, unsigned char fill_char);
    static Array removeLeadingZeros(const Array& array);

public:
    Three();
    Three(const size_t& n, unsigned char t = '0');
    Three(const std::initializer_list<unsigned char>& t);
    Three(const std::string& t);
    Three(const Three& other);
    Three(Three&& other) noexcept;
    ~Three() = default;

    //арифметические операции
    Three add(const Three& other) const;
    Three subtract(const Three& other) const;
    Three copy() const;

    //операции с присваиванием
    Three& addAndAssign(const Three& other);
    Three& subtractAndAssign(const Three& other);

    //операции сравнения
    bool greaterThan(const Three& other) const;
    bool lessThan(const Three& other) const;
    bool equals(const Three& other) const;

    std::string toString() const;
};

#endif