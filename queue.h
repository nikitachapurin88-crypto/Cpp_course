#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "stack.h"
#include <cstdint>

template<typename T>

class queue{
private:
    stack<T> in;
    stack<T> out;
    int s = -1;
public:
    queue(int64_t x): in(x), out(x){}
    
    void enqueue(T x){
        in.push(x);
        ++s;
    }

    T dequeue(){
        if (out.IsEmpty()){
            while (!in.IsEmpty()){
                out.push(in.pop());
            }
        }
        --s;
        return out.pop();
    }

    bool IsEmpty(){
        if(in.IsEmpty() && out.IsEmpty()){
            return true;
        }
        return false;
    }

    int64_t size(){
        if(!(in.IsEmpty() && out.IsEmpty())){
            return s;
        }
        return 0;
    }

    void print_queue(){
        in.print_stack();
        out.print_stack();
    }


};

#endif