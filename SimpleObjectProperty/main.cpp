#include <iostream>
#include "SimpleObjectProperty.h"

class TestClass {
public:
    TestClass(int i, char c) {
        t = new int(i);
        this->c = c;
    }

    ~TestClass() {
        delete t;
    }

    int getValue() {
        return *t;
    }

private:
    int* t;
    int i;
    char c;
};

int main()
{
    SimpleObjectProperty<TestClass>* test = new SimpleObjectProperty<TestClass>(314,'c');

    test->addListener([&](TestClass& oldV, TestClass& newV) {
        std::cout << "Property set. Old value:" << oldV.getValue() << " New value:" << newV.getValue() << std::endl;
    });
    while (true) {
        test->setValue(2,'C');
    }
}
