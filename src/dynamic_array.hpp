#pragma once

#include <cstddef>

template <typename T>
class DynamicArray {
public:
    DynamicArray() = default;
    ~DynamicArray() {
        delete[] m_data;
    }

    DynamicArray(const DynamicArray&) = delete;
    DynamicArray& operator=(const DynamicArray&) = delete;

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
    T* m_data = nullptr;
    std::size_t m_size = 0;
    std::size_t m_capacity = 0;
};
