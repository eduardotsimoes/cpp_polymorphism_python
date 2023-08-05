// ppInterface.h
#ifdef __cplusplus
extern "C" {
#endif

typedef struct Obj {
    void* ptr;
} Obj;

Obj createDerived1();
Obj createDerived2();
void doSomething(Obj obj, int mode);
void destroy(Obj obj);

#ifdef __cplusplus
}
#endif

