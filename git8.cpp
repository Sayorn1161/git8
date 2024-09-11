#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // Конструктор за замовчуванням
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Перевантаження оператора + для додавання комплексних чисел
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Метод для виведення числа
    void print() const {
        std::cout << "(" << real << " + " << imag << "i)" << std::endl;
    }
};

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.5, 2.5);

    Complex c3 = c1 + c2;
    c3.print();  // Виведе (4.5 + 6.5i)

    return 0;
}
