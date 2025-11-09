#include "../include/three.hpp"
#include <stdexcept>
#include <algorithm>

Three::Three() : data_() {}

Three::Three(const size_t& n, unsigned char t) : data_(n, t) {
    if (!isValidTernaryDigit(t)) {
        throw std::invalid_argument("Ternary digit must be '0', '1' or '2'");
    }
}

Three::Three(const std::initializer_list<unsigned char>& t) : data_(t) {
    for (auto digit : t) {
        if (!isValidTernaryDigit(digit)) {
            throw std::invalid_argument("Ternary digit must be '0', '1' or '2'");
        }
    }
}

Three::Three(const std::string& t) : data_(t) {
    for (char c : t) {
        if (!isValidTernaryDigit(c)) {
            throw std::invalid_argument("String must contain only ternary digits (0, 1, 2)");
        }
    }
}

Three::Three(const std::vector<unsigned char>& digits) {
    for (auto digit : digits) {
        if (!isValidTernaryDigit(digit)) {
            throw std::invalid_argument("Ternary digit must be '0', '1' or '2'");
        }
    }
    
    std::string str;
    for (auto digit : digits) {
        str += digit;
    }
    data_ = Array(str);
}

Three::Three(const Three& other) : data_(other.data_) {}

Three::Three(Three&& other) noexcept : data_(std::move(other.data_)) {}

bool Three::isValidTernaryDigit(unsigned char digit) {
    return digit == '0' || digit == '1' || digit == '2';
}

std::vector<unsigned char> Three::createAlignedVector(const Array& source, size_t target_size, unsigned char fill_char) {
    std::vector<unsigned char> result(target_size, fill_char);
    size_t source_size = source.getSize();
    size_t offset = target_size - source_size;
    
    for (size_t i = 0; i < source_size; ++i) {
        result[offset + i] = source.getAt(i);
    }
    
    return result;
}

std::vector<unsigned char> Three::removeLeadingZeros(const std::vector<unsigned char>& digits) {
    if (digits.empty()) {
        return {'0'};
    }
    
    size_t start_index = 0;
    size_t size = digits.size();
    while (start_index < size - 1 && digits[start_index] == '0') {
        start_index++;
    }
    
    if (start_index == size - 1 && digits[start_index] == '0') {
        return {'0'};
    }
    
    return std::vector<unsigned char>(digits.begin() + start_index, digits.end());
}

Three Three::add(const Three& other) const {
    size_t a_size = data_.getSize();
    size_t b_size = other.data_.getSize();
    size_t max_size = std::max(a_size, b_size);
    
    std::vector<unsigned char> a_aligned = createAlignedVector(data_, max_size, '0');
    std::vector<unsigned char> b_aligned = createAlignedVector(other.data_, max_size, '0');
    std::vector<unsigned char> temp_result(max_size, '0');
    unsigned char carry = 0;
    
    for (int i = max_size - 1; i >= 0; --i) {
        unsigned char a_digit = a_aligned[i] - '0';
        unsigned char b_digit = b_aligned[i] - '0';
        unsigned char sum = a_digit + b_digit + carry;
        
        temp_result[i] = (sum % 3) + '0';
        carry = sum / 3;
    }
    
    if (carry) {
        std::vector<unsigned char> new_result;
        new_result.push_back(carry + '0');
        new_result.insert(new_result.end(), temp_result.begin(), temp_result.end());
        temp_result = new_result;
    }
    
    temp_result = removeLeadingZeros(temp_result);
    
    return Three(temp_result);
}

Three Three::subtract(const Three& other) const {
    if (this->lessThan(other)) {
        throw std::invalid_argument("Cannot subtract larger ternary from smaller");
    }
    
    size_t a_size = data_.getSize();
    size_t b_size = other.data_.getSize();
    size_t max_size = std::max(a_size, b_size);
    
    std::vector<unsigned char> a_aligned = createAlignedVector(data_, max_size, '0');
    std::vector<unsigned char> b_aligned = createAlignedVector(other.data_, max_size, '0');
    
    std::vector<unsigned char> temp_result(max_size, '0');
    int borrow = 0;
    
    for (int i = max_size - 1; i >= 0; --i) {
        int a_digit = a_aligned[i] - '0';
        int b_digit = b_aligned[i] - '0';
        int diff = a_digit - b_digit - borrow;
        
        if (diff < 0) {
            diff += 3;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        temp_result[i] = diff + '0';
    }
    
    temp_result = removeLeadingZeros(temp_result);
    
    return Three(temp_result);
}

Three Three::copy() const {
    return Three(*this);
}

Three& Three::addAndAssign(const Three& other) {
    Three result = this->add(other);
    this->data_ = result.data_;
    return *this;
}

Three& Three::subtractAndAssign(const Three& other) {
    Three result = this->subtract(other);
    this->data_ = result.data_;
    return *this;
}

bool Three::greaterThan(const Three& other) const {
    return data_.greaterThan(other.data_);
}

bool Three::lessThan(const Three& other) const {
    return data_.lessThan(other.data_);
}

bool Three::equals(const Three& other) const {
    return data_.equals(other.data_);
}

std::string Three::toString() const {
    std::string result;
    for (size_t i = 0; i < data_.getSize(); ++i) {
        result += data_.getAt(i);
    }
    return result;
}