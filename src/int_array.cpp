#include "int_array.hpp"

IntArray::~IntArray() {
    delete[] m_data;
}

void IntArray::push_back(int value) {
    if (m_size == m_capacity) {
        const std::size_t new_capacity = m_capacity == 0 ? 1 : 2 * m_capacity;
        int* new_block = new int[new_capacity];

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

std::size_t IntArray::size() const {
    return m_size;
}

std::size_t IntArray::capacity() const {
    return m_capacity;
}

bool IntArray::empty() const {
    return m_size == 0;
}

int& IntArray::operator[](std::size_t i) {
    return m_data[i];
}

const int& IntArray::operator[](std::size_t i) const {
    return m_data[i];
}
