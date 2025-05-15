#include <iostream>
#include <stdexcept>

int main() {
    const int size = 5;
    int arr[size] = {1, 2, 3, 4, 5};
    int index;

    std::cout << "Enter the index to access: ";
    std::cin >> index;

    try {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Array index out of bounds.");
        }
        std::cout << "Element at index " << index << ": " << arr[index] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
