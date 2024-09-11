#include <iostream>

class Buffer {
private:
    int* data;
    int size;

public:
    // Конструктор для ініціалізації буфера заданого розміру
    Buffer(int s) : size(s), data(new int[s]) {
        std::cout << "Constructor called" << std::endl;
    }

    // Конструктор переносу
    Buffer(Buffer&& other) noexcept : size(other.size), data(other.data) {
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move constructor called" << std::endl;
    }

    // Оператор присвоєння переносу
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data;  // Звільняємо старі дані

            data = other.data;
            size = other.size;

            other.data = nullptr;
            other.size = 0;

            std::cout << "Move assignment operator called" << std::endl;
        }
        return *this;
    }

    // Деструктор
    ~Buffer() {
        delete[] data;
        std::cout << "Destructor called" << std::endl;
    }

    // Метод для доступу до елементів
    int& operator[](int index) {
        if (index >= 0 && index < size) {
            return data[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }
};

int main() {
    Buffer buf1(10);

    // Ініціалізація елементів буфера
    for (int i = 0; i < 10; ++i) {
        buf1[i] = i * 5;
    }

    // Виклик конструктора переносу
    Buffer buf2 = std::move(buf1);

    // Виклик оператора присвоєння переносу
    Buffer buf3(5);
    buf3 = std::move(buf2);

    return 0;
}
