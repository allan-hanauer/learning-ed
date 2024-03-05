#include <iostream>
#include <vector>
#include <typeinfo> // Para RTTI

class Shape {
public:
    virtual double area() const = 0; // Função virtual pura para calcular a área
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius; // Área do círculo: π * raio^2
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {}

    double area() const override {
        return side * side; // Área do quadrado: lado^2
    }
};

int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(3.0)); // Adicionando um círculo à lista
    shapes.push_back(new Square(4.0)); // Adicionando um quadrado à lista

    // Iterando sobre a lista de formas e calculando a área de cada uma
    for (Shape* shape : shapes) {
        if (Circle* circle = dynamic_cast<Circle*>(shape)) {
            std::cout << "Area do circulo: " << circle->area() << std::endl;
        } else if (Square* square = dynamic_cast<Square*>(shape)) {
            std::cout << "Area do quadrado: " << square->area() << std::endl;
        }
    }

    // Liberando a memória alocada
    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
