// CppInterfaceWrapper.cpp
#include <Python.h>
#include "CppInterface.h"
#include <stdio.h>

static PyObject* py_createDerived1(PyObject* self) {
    Obj o = createDerived1();
    printf("Pointer address inside py_createDerived1: %p\n", o.ptr);
    return PyCapsule_New(o.ptr, "Derived", NULL); ;
}

static PyObject* py_createDerived2(PyObject* self) {
    Obj o = createDerived2();
    printf("Pointer address inside py_createDerived2: %p\n", o.ptr);
    return PyCapsule_New(o.ptr, "Derived", NULL); ;
}

static PyObject* py_doSomething(PyObject* self, PyObject* args) {
    void* ptr;
    int mode;

    PyObject* pyObj;  // the Python object, to be filled in by PyArg_ParseTuple
    if (!PyArg_ParseTuple(args, "Oi", &pyObj, &mode)) {
	    return nullptr;
    }

    ptr = PyCapsule_GetPointer(pyObj, "Derived");
    if (ptr == NULL) {
	    return nullptr;
    }


    printf("Pointer address inside py_doSomething: %p\n", ptr);
    doSomething((Obj){.ptr = ptr}, mode);
    Py_RETURN_NONE;
}

static PyObject* py_destroy(PyObject* self, PyObject* args) {
    void* ptr;
    PyObject* pyObj;  // the Python object, to be filled in by PyArg_ParseTuple
    if (!PyArg_ParseTuple(args, "O", &pyObj)) {
	    return nullptr;
    }

    ptr = PyCapsule_GetPointer(pyObj, "Derived");
    if (ptr == NULL) {
	    return nullptr;
    }
   
    destroy((Obj){.ptr = ptr});
    Py_RETURN_NONE;
}

static PyMethodDef CppInterfaceMethods[] = {
    {"createDerived1", (PyCFunction)py_createDerived1, METH_NOARGS, nullptr},
    {"createDerived2", (PyCFunction)py_createDerived2, METH_NOARGS, nullptr},
    {"doSomething", (PyCFunction)py_doSomething, METH_VARARGS, nullptr},
    {"destroy", (PyCFunction)py_destroy, METH_VARARGS, nullptr},
    {nullptr, nullptr, 0, nullptr}
};

static struct PyModuleDef CppInterfaceModule = {
    PyModuleDef_HEAD_INIT, "CppInterface", nullptr, -1, CppInterfaceMethods,
    nullptr, nullptr, nullptr, nullptr
};

PyMODINIT_FUNC PyInit_CppInterface(void) {
    return PyModule_Create(&CppInterfaceModule);
}








