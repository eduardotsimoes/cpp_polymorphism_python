## goal

This is a repository to explorer how to use the c++ polymorphism inside python.


The way this was achieved is by:

1- writing a C interface that transfer the methods of the c++ class (methods, constructor, destructor)
2- writing the wrapper

## the python wrapper

The Polymorphism is done by pass void pointers. Python handle this pointers inside a capsule. 

So, the capsule attach a name to the pointer. This object will be extracted inside the polymorphic function to extract the true pointer by before checking the name.



