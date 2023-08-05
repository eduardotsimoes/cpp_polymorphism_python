import CppInterface  # Assuming this is your C extension module name

class PyDerived1:
    def __init__(self):
        self.obj = CppInterface.createDerived1()

    def __del__(self):
        CppInterface.destroyDerived(self.obj)

    def doSomething(self, mode):
        return CppInterface.doSomething(self.obj, mode)

