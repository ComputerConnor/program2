#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include <iostream>

using namespace std;

template <typename T>
class SmartPointer {
private:
    T* ptr;

public:
    SmartPointer(T* p = nullptr) : ptr(p) {}
    ~SmartPointer() { delete ptr; }

    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }

    SmartPointer& operator=(T* p) {
        if (ptr != p) {
            delete ptr;
            ptr = p;
        }
        return *this;
    }

    bool operator==(const SmartPointer& other) const { return ptr == other.ptr; }
    bool isNull() const { return ptr == nullptr; }
};

#endif
