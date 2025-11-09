#include "../include/array.hpp"
#include <stdexcept>
#include <cstring>

Array::Array() : size_(0), data_(nullptr) {}

Array::Array(const size_t& n, unsigned char t) : size_(n), data_(new unsigned char[n]) {
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = t;
    }
}

Array::Array(const std::initializer_list<unsigned char>& t) 
    : size_(t.size()), data_(new unsigned char[t.size()]) {
    size_t i = 0;
    for (auto it = t.begin(); it != t.end(); ++it, ++i) {
        data_[i] = *it;
    }
}

Array::Array(const std::string& t) : size_(t.length()), data_(new unsigned char[t.length()]) {
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = t[i];
    }
}

Array::Array(const Array& other) : size_(other.size_), data_(new unsigned char[other.size_]) {
    std::memcpy(data_, other.data_, size_);
}

Array::Array(Array&& other) noexcept : size_(other.size_), data_(other.data_) {
    other.size_ = 0;
    other.data_ = nullptr;
}

Array::~Array() noexcept {
    delete[] data_;
}

size_t Array::getSize() const {
    return size_;
}

unsigned char Array::getAt(size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

Array Array::copy() const {
    return Array(*this);
}

bool Array::greaterThan(const Array& other) const {
    if (size_ != other.size_) {
        return size_ > other.size_;
    }

    for (size_t i = 0; i < size_; ++i) {
        if (data_[i] != other.data_[i]) {
            return data_[i] > other.data_[i];
        }
    }
    return false;
}

bool Array::lessThan(const Array& other) const {
    if (size_ != other.size_) {
        return size_ < other.size_;
    }

    for (size_t i = 0; i < size_; ++i) {
        if (data_[i] != other.data_[i]) {
            return data_[i] < other.data_[i];
        }
    }
    return false;
}

bool Array::equals(const Array& other) const {
    if (size_ != other.size_) {
        return false;
    }

    for (size_t i = 0; i < size_; ++i) {
        if (data_[i] != other.data_[i]) {
            return false;
        }
    }
    return true;
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        data_ = new unsigned char[size_];
        std::memcpy(data_, other.data_, size_);
    }
    return *this;
}

Array& Array::operator=(Array&& other) noexcept {
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        data_ = other.data_;
        other.size_ = 0;
        other.data_ = nullptr;
    }
    return *this;
}