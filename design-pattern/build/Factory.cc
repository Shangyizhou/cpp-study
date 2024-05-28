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

class CircleButton : public Product {
public:
    CircleButton() {
        cout << "Create CircleButton" << endl;
    }    

    void Use() override {
        cout << "Use CircleButton" << endl;
    }
};

class SquareButton : public Product {
public:
    SquareButton() {
        cout << "Create SquareButton" << endl;
    }

    void Use() override {
        cout << "Use SquareButton" << endl;
    }
};

class Factory {
public:
    virtual Product* CreateButton() = 0;
};

class CircleFactory : public Factory {
public: 
    CircleFactory() = default;
    Product* CreateButton() {
        return new CircleButton;
    }
};

class SquareFactory : public Factory {
public: 
    SquareFactory() = default;
    Product* CreateButton() {
        return new SquareButton;
    }
};

int main()
{
    unique_ptr<Factory> circle_factory(new CircleFactory);
    unique_ptr<Factory> square_factory(new SquareFactory);
    unique_ptr<Product> circle_button(circle_factory->CreateButton());
    unique_ptr<Product> square_button(square_factory->CreateButton());
    circle_button->Use();
    square_button->Use();

    return 0;
}