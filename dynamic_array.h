#ifndef DYN_ARR_H
#define DYN_ARR_H

#include <cstdlib>
#include <exception>
#include <iostream>
#include <cstdint>
#include <stdexcept>

template<typename T>
class DynamicArray {
private:
  T* data;
  std::int64_t size = -1;
  std::int64_t capacity;

  bool isEmpty() {
    return size == -1;
  }

public:

DynamicArray(std::int64_t x) {
  this->capacity = x;
  this->data = new T[this->capacity];
}
~DynamicArray() {
  if (this->data) {
    delete[] this->data;
  }
}
void push_back(T x) {
  if (size + 1 >= capacity) {
    std::int64_t newCapacity = capacity * 2;
    T* tempArray = new T[newCapacity];
    for (int i = 0; i < capacity; ++i) {
      tempArray[i] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
  }
  data[++size] = x;
}


//---added with lab-------------------------------------
void push(T x){
        if (size + 1>= capacity){
            throw std::overflow_error("stack overflow");
        }
        data[++size] = x;
    }

bool Empty() {
    return size == -1;
  }

//---added with dz---------------------------------------

void push_front(T x){
  if (size + 1 >= capacity) {
    std::int64_t newCapacity = capacity * 2;
    T* tempArray = new T[newCapacity];
    for (int i = 0; i < capacity; ++i) {
      tempArray[i] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
  }
  ++size;
  for( int i = size; i > 0; i--){
    data[i] = data[i-1];
  }
  data[0] = x;
}

T delete_last_item(){
  T x = data[size];
  --size;
  return x;
}

T front(){
  return data[0];
}

T back(){
  return data[size];
}

void insert(std::int64_t idx, T x){
  if( idx > size){
    throw std::invalid_argument("incorrect idx value in insert");
  }
  if (size + 1 >= capacity) {
    std::int64_t newCapacity = capacity * 2;
    T* tempArray = new T[newCapacity];
    for (int i = 0; i < capacity; ++i) {
      tempArray[i] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
  }
  ++size;
  for( int i = size; i > idx; i-- ){
    data[i] = data[i-1];
  }
  data[idx] = x;
}

void remove(std::int64_t idx){
  if( idx > size){
    throw std::invalid_argument("incorrect idx value in remove");
  }
  for( int i = idx; i < size; ++i ){
    data[i] = data [i+1];
  }
  --size;
}

void erase_after(std::int64_t idx){
  if( idx >= size){
    throw std::invalid_argument("incorrect idx value in erase_after");
  }
  size=idx;
}

void increase_capacity(std::int64_t newCapacity){
  if( newCapacity <= capacity){
    throw std::invalid_argument("incorrect capacity value in increase_capacity");
  }
  capacity = newCapacity;
}

void decrease_capacity(std::int64_t newCapacity){
  if( newCapacity >= capacity){
    throw std::invalid_argument("incorrect capacity value in decrease_capacity");
  }
  capacity = newCapacity;
  if( size > capacity){
    size = capacity;
  }
}

//---dz---------------------------------------

T operator[](std::int64_t idx) {
  if (isEmpty() || idx < 0 || idx > size) {
    throw std::invalid_argument("Out of range");
  }
  return data[size - idx];
}

T operator()() {
  if (isEmpty()) {
    return 0;
  }
  float sum = 0;
  for (int i = 0; i <= size; ++i) {
    sum += data[i];
  }
  return sum;
}

void clear() {
  if (this->data) {
    delete[] this->data;
    this->data = nullptr;
  }
  size = -1;
  capacity = 8;
}

void reinitialize() {
  clear();
  data = new T[capacity]();
}

void printData() {
  if (isEmpty()) {
    return;
  }
  for (int i = 0; i <= size; ++i) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
}

T add(std::int64_t idx1, std::int64_t idx2) {
  if (idx1 > size || idx2 > size || idx1 < 0 || idx2 < 0) {
    throw std::invalid_argument("idx1 or idx2 out of range");
  }
  return data[idx1] + data[idx2];
}

T max() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  float currentMax = -1e+38;
  for (int i = 0; i <= size; ++i) {
    if (data[i] >= currentMax) {
      currentMax = data[i];
    }
  }
  return currentMax;
}

T min() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  float currentMin = 1e+38;
  for (int i = 0; i <= size; ++i) {
    if (data[i] <= currentMin) {
      currentMin = data[i];
    }
  }
  return currentMin;
}


};

#endif 
