#include <iostream>
#include <vector>
#include <map>

struct A {
    alignas(8) int x;

    A() {
        x = 0;
        std::cout << "build A" << std::endl;
    }

    A(int v) {
        x = v;
        std::cout << "build A" << std::endl;
    }

    ~A() {
        x = 0;
        std::cout << "A dtor" << std::endl;
    }
};

void testPlacement() {
    char* buff = new char[16*1024];
    int cptSize = sizeof(A);
    A* a = new(buff+0*cptSize) A();
    a->x = 12;
    A* b = new(buff+1*cptSize) A();
    b->x = 2048;
    A* c = new(buff+2*cptSize) A();
    c->x = 256;
    std::cout << "a.x=" << a->x << std::endl;
    std::cout << "b.x=" << b->x << std::endl;
    std::cout << "c.x=" << c->x << std::endl;
    b->~A();
    //operator delete(b, buff+1*cptSize);
    //std::cout << "after delete b, b.x=" << b->x << std::endl;
    A* d = new(buff + 1 * cptSize) A();
    d->x = 222;
    std::cout << "d has same address as b, d.x=" << d->x<<", when b.x="<<b->x << std::endl;
    a->~A(); b->~A(); c->~A(); d->~A();
    delete[] buff;
    std::cout << "after delete all buff, d.x=" << d->x << std::endl;
}

void testLua() {

}

void testContainers() {
    std::vector<A*> aList;
    aList.push_back(new A(2));
    std::cout << "aList[0]->x=" << aList[0]->x << std::endl;
    int x = 1;
    
    
}

int main(){
    testLua();
    //testContainers();
    return 0;
}