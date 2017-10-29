#include <iostream>

class  A{
public:
    virtual int asd() = 0;
};

class B : public A{
public:
    int asd(){ return 3;}
    // int asd(){
    //     return 3;
    // }
    int bsd(){
        return 4;
    }
};
class E


template<class A>
class D{
    A a;
public:
    int dsd(){
        return a.asd();
    }
};

class C : A{
public:
    int asd(){return 4;}

};


int main(){
    //B b;
    D<B> b;
    D<C> c;


    std::cout << b.dsd();
    std::cout << c.dsd();
}