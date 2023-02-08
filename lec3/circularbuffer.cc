#include <iostream>
using namespace std;
class CircularBuffer{
private:
    int* buffer;
    int capacity;
    void grow() {}
    uint32_t head, tail;
public:
    CircularBuffer(int capacity) : buffer(new int[capacity]), capacity(capacity){
        head = tail = 0;
    }
    void enqueue(int v){
        buffer[tail++] = v;
        //if tail goes beyond end, start at 0 again
        //if tail becomes = head, then you are FULL which means to grow.
    }
    int dequeue() {

    }
    bool isEmpty() {}
};