#include <iostream>

template <class Type>
class SmartPointer {
private:
    Type *pointer;
    bool created = false;
public:
    SmartPointer(Type* p): pointer(p) {};
    operator Type*() {
        if (!pointer) {
            pointer = new Type();
            created = true;
            std::cerr << "Bad pointer!" << std::endl;
        }
        return pointer; 
    };
    Type *operator->()  {
        if (!pointer) {
            pointer = new Type();
            created = true;
            std::cerr << "Bad pointer!" << std::endl;
        }
        return pointer; 
    };
    std::ptrdiff_t operator-(SmartPointer<Type> p) {
        return pointer - p;
    }
    std::ptrdiff_t operator-(Type* /* void*? */ p) {
        return pointer - p;
    }
    ~SmartPointer() { if (created) delete pointer; }
};

class Foo {
private:
    int a, b;
public:
    Foo(): a(0), b(0) {};
    Foo(int a, int b): a(a), b(b) {};
    int Sum() { return a + b; };
};

int main(int argc, char *argv[])
{
    SmartPointer<Foo> sp1(new Foo(2,2));
    SmartPointer<Foo> sp2(NULL);
    std::cout << sp1->Sum() << std::endl; 
     std::cout << sp2->Sum() << std::endl; 
   return 0;
}

