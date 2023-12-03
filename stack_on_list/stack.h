// Copirite 2023 Vasenkov Andrey
#ifndef _STACK_H_
#define _STACK_H_
#include <iostream>
#include "../list/list.h"


using namespace std;
template<typename T>
class stackOnList {
private:
    TList<T> data;
public:
    void push(T value) {
        data.push_front(value);
    }
    void pop() {
        if (!data.isEmpty()) {
            data.pop_front();
        }
    }
    T& top() {
        if (!data.isEmpty()) {
            return data.Head();
        }throw;
        //return -1; // or throw an exception
    }
    bool empty() {
        return data.isEmpty();
    }
    int size() {

        return data.getCount();
    };
    int getIndex(T data_) {
        return data.getIndex(data_);
    }
};
#endif // !_STACK_H_