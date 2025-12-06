#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "dynamic_array.h"
#include <cstdint>

template<typename T>
class stack {
private:
    DynamicArray<T> array;
public:
    stack(std::int64_t x): array(x){}

    void push(T x){
        array.push(x);
    }

    void print_stack(){
        array.printData();
    }

    void top(){
        T x = array.back();
        return x;
    }

    T pop(){
        T x = array.delete_last_item();
        return x;
    }

    bool IsEmpty(){
        return array.Empty();
    }
};

#endif