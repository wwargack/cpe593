//Walter Wargacki
#include <iostream>
using namespace std;
class GrowArray {
private:
  int* p;
  uint32_t size; // the number of elements used
  uint32_t capacity; // the amount of memory
  void checkGrow() {
    if (size < capacity)
      return;
    // if the memory needs to grow, double in size
    capacity *= 2;
  }
public:

  GrowArray(): size(0), capacity(0), p(nullptr) {}
  GrowArray(int n): size(0), capacity(n) {
    p = new int[capacity];
  }
  ~GrowArray() {
    delete[] p;
  }
  GrowArray(const GrowArray& orig);
  GrowArray& operator =(const GrowArray& orig);

  void addEnd(int v) {
    checkGrow();
    p[size] = v; //add value to end
    size++;
  }

  void addStart(int v) {
    //If array is empty, add something to the start
    if (p == nullptr) {
      p = new int[1];
      size++;
      capacity++;
      p[0] = v;
      return;
    }
    checkGrow();
    int* temp = new int[capacity + 1]; //create temporary array
    //next index in temp = current index in p
    for (int i = 0; i < size; i++)
      temp[i + 1] = p[i];
    p = temp; //point p to correct array
    p[0] = v; //add value to start
    size++;
    //delete[] temp;
  }

  void removeStart() {
    if (p == nullptr) {
      cout << "Cannot delete from an empty array.";
      return;
    }
    if (size == 1) {
      size--;
      return;
    }
    int* temp = new int[capacity]; //create temporary array
    //make index in temp = next index in p;
    for (int i = 1; i < size; i++)
      temp[i - 1] = p[i];
    p = temp; //point p to correct array
    size--;
    //delete[] temp;
  }

  void removeEnd() {
    if (p == nullptr) {
      cout << "Cannot delete from an empty array.";
      return;
    }
    size--;
  }

  void removeEvens() {
    if (p == nullptr) {
      cout << "Cannot delete from an empty array.";
      return;
    }
    int counter = 0;
    int* temp;
    temp = new int[capacity];
    for (int i = 0; i < size; i++) {
      if (p[i] % 2 == 1) {
        temp[counter] = p[i];
        counter++;
      }
    }
    p = temp;
    size = counter;
    //delete[] temp;
  }

  void printValues() {
    for (int i = 0; i < size; i++)
      cout << p[i] << " ";
    cout << "\n";
  }

  void printArray() {
    cout << "--------" << "\n";
    cout << "Current Size = " << size << "\n";
    cout << "Current Capacity = " << capacity << "\n";
    //cout << "Current p* = " << p << "\n";
    printValues();
  }
};

int main() {
  GrowArray a(500); // empty list, with 500 elements
  uint32_t n;
  cout << "Enter an integer: ";
  cin >> n;

  for (int i = 0; i < 500; i++)
    a.addEnd(i); // really fast!

  a.printArray();

  for (int i = 0; i < n; i++)
    a.addEnd(i); // every time you need to grow, double
  a.printArray();

  a.addStart(5);

  a.printArray();

  for (int i = 0; i < n / 2; i++)
    a.removeEnd();

  a.printArray();

  for (int i = 0; i < n / 2; i++)
    a.removeStart();

  a.printArray();


  a.removeEvens();

  a.printArray();


  //I have zero clue why the program can't get past a.addStart(5) if i enter a higher number than 2 for my input n.
  //I could swear that I have no mistakes but if I do it's some subtle one.
  //for example, I have the same type of logic for addStart() as is in the HW quiz, so I don't understand why my program can't get past it. 
  //I also don't know how to implement cout << a << "\n"; via operator overloading 
  //I assume this would print out the entire values of a instead of cutting it short like mine does.
}