#include <iostream>

class Array {
private:
    int* data;
    int size;

public:
    // Конструктор для ініціалізації масиву заданого розміру
    Array(int s) : size(s) {
        data = new int[size];
    }

    // Перевантаження оператора [] для доступу до елементів масиву по індексу
    int& operator[](int index) {
        if (index >= 0 && index < size) {
            return data[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    // Деструктор
    ~Array() {
        delete[] data;
    }
};

int main() {
    Array arr(5);

    // Заповнення масиву
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }

    // Виведення елементів масиву
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";  // Виведе 0 10 20 30 40
    }
    std::cout << std::endl;

    return 0;
}
