#include "int_array.hpp"

#include <cstddef>
#include <print>

int main() {
    IntArray numbers{};

    std::size_t last_capacity = numbers.capacity();
    for (int i = 0; i < 100; ++i) {
        numbers.push_back(i);
        if (numbers.capacity() != last_capacity) {
            std::println("size {} capacity {}", numbers.size(), numbers.capacity());
            last_capacity = numbers.capacity();
        }
    }

    int sum = 0;
    for (std::size_t i = 0; i < numbers.size(); ++i) {
        sum += numbers[i];
    }

    std::println("sum {}", sum);
    return 0;
}
