# setup.py
from distutils.core import setup, Extension

module = Extension('CppInterface',
                   sources=['CppInterfaceWrapper.cpp', 'CppInterface.cpp'],
                   extra_compile_args=['-std=c++11'])

setup(name='CppInterface',
      version='1.0',
      description='This is a demo package',
      ext_modules=[module])

