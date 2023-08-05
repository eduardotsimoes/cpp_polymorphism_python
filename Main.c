#include "CppInterface.h"

//  code
int main() {
    Obj d1 = createDerived1();
    Obj d2 = createDerived2();

    doSomething(d1, 0); // Note: 0 corresponds to Mode1
    doSomething(d2, 1); // Note: 1 corresponds to Mode2

    destroy(d1);
    destroy(d2);

    return 0;
}
