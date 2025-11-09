#ifndef THREE_HPP
#define THREE_HPP

#include "array.hpp"
#include <string>
#include <vector>
#include <stdexcept>

class Three {
private:
    Array data_;

    static bool isValidTernaryDigit(unsigned char digit);
    static std::vector<unsigned char> createAlignedVector(const Array& source, size_t target_size, unsigned char fill_char);
    static std::vector<unsigned char> removeLeadingZeros(const std::vector<unsigned char>& digits);

public:
    Three();
    Three(const size_t& n, unsigned char t = '0');
    Three(const std::initializer_list<unsigned char>& t);
    Three(const std::string& t);
    Three(const std::vector<unsigned char>& digits);
    
    Three(const Three& other);
    Three(Three&& other) noexcept;
    ~Three() = default;

    Three add(const Three& other) const;
    Three subtract(const Three& other) const;
    Three copy() const;
    Three& addAndAssign(const Three& other);
    Three& subtractAndAssign(const Three& other);

    bool greaterThan(const Three& other) const;
    bool lessThan(const Three& other) const;
    bool equals(const Three& other) const;

    std::string toString() const;
};

#endif