#include "LinkedList.cc"

class Queue{
private:
    LinkedList impl; //only head pointer
public:
    Queue() : impl() {} //O(1)
    void enqueue(int v) { //O(1)
        impl.addStart(v);
    }
    int dequeue() { //O(n)
        return impl.removeEnd(); //need to rewrite remove end to return value after removing
    }
    bool isEmpty() const{ //O(1)
        return impl.isEmpty();
    }
};

class Queue2{
private:
    LinkedList2 impl; //with head and tail
public:
    Queue2(int capacity) : impl(capacity) {} //O(1)
    void enqueue(int v) { //O(1)
        impl.addEnd(v);
    }
    int dequeue() { //O(1)
        return impl.removeStart(); //need to rewrite remove start to return value after removing
    }
    bool isEmpty() const{ //O(1)
        return impl.isEmpty();
    }
};

class Queue3{
private:
    DynamicArray impl; //with head and tail
public:
    Queue3(int capacity) : impl(capacity) {} //O(1)
    void enqueue(int v) { //O(n)
        impl.addStart(v);
    }
    int dequeue() { //O(1)
        return impl.removeEnd(); //need to rewrite remove end to return value after removing
    }
    bool isEmpty() const{ //O(1)
        return impl.isEmpty();
    }
};