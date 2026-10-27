#pragma once

#include <cstddef>
#include <utility>

template <typename T>
class DynamicArray {
public:
    DynamicArray() = default;
    ~DynamicArray() {
        delete[] m_data;
    }

    DynamicArray(const DynamicArray& other)
        : m_data{other.m_size == 0 ? nullptr : new T[other.m_size]},
          m_size{other.m_size},
          m_capacity{other.m_size} {
        for (std::size_t i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }

    DynamicArray& operator=(const DynamicArray& other) {
        DynamicArray copy{other};
        swap(copy);
        return *this;
    }

    void swap(DynamicArray& other) noexcept {
        std::swap(other.m_data, m_data);
        std::swap(other.m_size, m_size);
        std::swap(other.m_capacity, m_capacity);
    }

    void push_back(const T& value) {
        if (m_size == m_capacity) {
            const std::size_t new_capacity = m_capacity == 0 ? 1 : 2 * m_capacity;
            T* new_block = new T[new_capacity];

            for (std::size_t i = 0; i < m_size; ++i) {
                new_block[i] = m_data[i];
            }

            delete[] m_data;
            m_data = new_block;
            m_capacity = new_capacity;
        }

        m_data[m_size] = value;
        ++m_size;
    }

    [[nodiscard]] std::size_t size() const {
        return m_size;
    }

    [[nodiscard]] std::size_t capacity() const {
        return m_capacity;
    }

    [[nodiscard]] bool empty() const {
        return m_size == 0;
    }

    T& operator[](std::size_t i) {
        return m_data[i];
    }

    const T& operator[](std::size_t i) const {
        return m_data[i];
    }

private:
    // Invariants:
    //   1. m_size <= m_capacity
    //   2. m_data == nullptr exactly when m_capacity == 0
    //   3. m_data[0] .. m_data[m_size - 1] hold real elements
    T* m_data = nullptr;
    std::size_t m_size = 0;
    std::size_t m_capacity = 0;
};
