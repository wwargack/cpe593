#include "LinkedList.cc"

class Stack{
private:
    LinkedList impl;
public:
    Stack() : impl() {} //O(1)
    void push(int v) { //O(1)
        impl.addStart(v);
    }
    int pop() { //O(1)
        return impl.removeStart(); //need to rewrite remove start to return value after removing
    }
    bool isEmpty() const{ //O(1)
        return impl.isEmpty();
    }
};

class Stack2{
private:
    DynamicArray impl;
public:
    Stack2(int capacity) : impl(capacity) {} //O(1)
    void push(int v) { //O(1)
        impl.addEnd(v);
    }
    int pop() { //O(1)
        return impl.removeEnd(); //need to rewrite remove end to return value after removing
    }
    bool isEmpty() const{ //O(1)
        return impl.isEmpty();
    }
};