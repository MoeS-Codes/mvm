#pragma once

#include <cstddef>

class IntArray {
public:
    IntArray() = default;
    ~IntArray();

    IntArray(const IntArray&) = delete;
    IntArray& operator=(const IntArray&) = delete;

    void push_back(int value);

    [[nodiscard]] std::size_t size() const;
    [[nodiscard]] std::size_t capacity() const;
    [[nodiscard]] bool empty() const;

    int& operator[](std::size_t i);
    const int& operator[](std::size_t i) const;

private:
    int* m_data = nullptr;
    std::size_t m_size = 0;
    std::size_t m_capacity = 0;
};
