#include <iostream>
#include <chrono>

// 基类
class Base {
public:
    virtual  void print() {
        std::cout << "Base class" << std::endl;
    }
    //virtual ~Base()= default;
};

// 派生类
class Derived : public Base {
public:
    void print() {
        std::cout << "Derived class" << std::endl;
    }
};

// CRTP基类
template <typename Derived>
class CRTPBase {
public:
    void print() {
        static_cast<Derived*>(this)->print();
    }
};

// CRTP派生类
class CRTPDerived : public CRTPBase<CRTPDerived> {
public:
    void print() {
        std::cout << "CRTPDerived class" << std::endl;
    }
};

int main() {
    Base* b = new Derived();
    CRTPBase<CRTPDerived> * crtp = new CRTPDerived();

    // 测量多态的时间
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        b->print();
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> polymorphism_time = end - start;

    // 测量CRTP的时间
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        crtp->print();
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> crtp_time = end - start;
    std::cout << "Polymorphism time: " << polymorphism_time.count() << " ms" << std::endl;
    std::cout << "CRTP time: " << crtp_time.count() << " ms" << std::endl;

    delete b;
    delete crtp;

    return 0;
}
