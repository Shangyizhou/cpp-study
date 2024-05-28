#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;

enum ProductName {
    CIRCLE = 0,
    SQUARE,
};

class Product {
public:
    virtual void Use() = 0;
};

struct CircleButton : public Product {
public:
    CircleButton() {
        std::cout << "Create CircleButton" << std::endl;
    }

    void Use() override {
        std::cout << "Use CircleButton" << std::endl;
    }
};

struct SquareButton : public Product {
public:
    SquareButton() {
        std::cout << "Create SquareButton" << std::endl;
    }

    void Use() override {
        std::cout << "Use SquareButton" << std::endl;
    }
};

class SimpleFactory {
public:
    SimpleFactory() = default;

    static Product* CreateProduct(const ProductName& name) {
        if (CIRCLE == name) {
            return new CircleButton;
        } else if (SQUARE == name) {
            return new SquareButton;
        } else {
            return nullptr;
        }
    }
};

int main()
{
    unique_ptr<Product> circle_button(SimpleFactory::CreateProduct(ProductName::CIRCLE));
    unique_ptr<Product> square_button(SimpleFactory::CreateProduct(ProductName::SQUARE));
    circle_button->Use();
    square_button->Use();

    return 0;
}

// Create CircleButton
// Create SquareButton
// Use CircleButton
// Use SquareButton