#include <iostream>

class Point {
private:
    int x, y;

public:
    // Конструктор
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Перевантаження оператора << для виведення координат
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int main() {
    Point p1(5, 10);
    std::cout << "Point coordinates: " << p1 << std::endl;  // Виведе (5, 10)

    return 0;
}

