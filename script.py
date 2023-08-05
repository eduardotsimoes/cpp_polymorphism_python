# Python code
import CppInterface

d1 = CppInterface.createDerived1()
d2 = CppInterface.createDerived2()

CppInterface.doSomething(d1, 0) # Note: 0 corresponds to Mode1
CppInterface.doSomething(d2, 1) # Note: 1 corresponds to Mode2

CppInterface.destroy(d1)
CppInterface.destroy(d2)

