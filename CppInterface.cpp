// CppInterface.cpp
#include "CppInterface.h"
#include <iostream>

enum class Mode { Mode1, Mode2 };

class Base {
public:
    virtual void doSomething(Mode mode) = 0;
};

class Derived1 : public Base {
public:
    void doSomething(Mode mode) override {
        if (mode == Mode::Mode1)
            std::cout << "Derived1 is operating in Mode1\n";
        else
            std::cout << "Derived1 is operating in Mode2\n";
    }
};

class Derived2 : public Base {
public:
    void doSomething(Mode mode) override {
        if (mode == Mode::Mode1)
            std::cout << "Derived2 is operating in Mode1\n";
        else
            std::cout << "Derived2 is operating in Mode2\n";
    }
};

extern "C" {
    Obj createDerived1() {
        Obj o;
        o.ptr = new Derived1;
        return o;
    }

    Obj createDerived2() {
        Obj o;
        o.ptr = new Derived2;
        return o;
    }

    void doSomething(Obj obj, int mode) {
        static_cast<Base*>(obj.ptr)->doSomething(static_cast<Mode>(mode));
    }

    void destroy(Obj obj) {
        delete static_cast<Base*>(obj.ptr);
    }
}

