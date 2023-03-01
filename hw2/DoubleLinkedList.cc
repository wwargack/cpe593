#include <iostream>
using namespace std;

class DoubleLinkedList {
private:
	class Node {
	public:
		Node* next;
		Node* prev;
		int val;
	};

	Node* head;
	Node* tail;
    int length;
public:
	DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
	}

    // DO NOT FORGET THE DESTRUCTOR!!!
    ~DoubleLinkedList() {
        delete [] head;
        //delete tail;
    }

    DoubleLinkedList(const DoubleLinkedList& orig);
    DoubleLinkedList& operator =(const DoubleLinkedList& orig);


	void addStart(int v) {
        length++;
        //Empty list
        if(head == nullptr){
            head = new Node();
            head->val = v;
            head->next = nullptr;
            head->prev = nullptr;
            tail = head;
            return;
        }
        //List already exists
        Node* temp = new Node();
        temp->val = v;
        temp->next = head;
        temp->prev = nullptr;
        head = temp;
	}

	void addEnd(int v) {
        length++;
        //Empty List
        if(head == nullptr){
            head = new Node();
            head->val = v;
            head->next = nullptr;
            head->prev = nullptr;
            tail = head;
            return;
        }
        //List Already Exists
        Node* temp = new Node();
        temp->val = v;
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
	}

	void removeStart() {
        //empty list
        if(head == nullptr){
            cout << "Cannot remove node from empty list.\n";
            return;
        }
        length--;
        //1 element list
        if(head->next == nullptr){
            head = nullptr;
            tail = nullptr;
            return;
        }
        //else move head up one node
        head = head->next;
        head->prev = nullptr;
	}

	void removeEnd() {
        //empty list
        if(head == nullptr){
            cout << "Cannot remove node from empty list.\n";
            return;
        }
        length--;
        //1 element list
        if(head->next == nullptr){
            head = nullptr;
            tail = nullptr;
            return;
        }
        //else move tail back one node
        tail = tail->prev;
        tail->next = nullptr;
	}

	// insert v before pos. insert(0,v) would insert at the front.
	void insert(int pos, int v) {
        if(pos > length){
            cout << "Cannot add node outside of current nodes.\n";
            return;
        }
        if(pos == 0){
            addStart(v);
            length++;
            return;
        }
        if(pos == length){
            addEnd(v);
            length++;
            return;
        }



        Node* finder = head->next;
        Node* behind = head;
        for(int i = 1; i < pos; i++){
            finder = finder->next;
            behind = behind->next;
        }
        Node* temp = new Node();
        temp->val = v;
        behind->next = temp;
        finder->prev = temp;
        temp-> next = finder;
        length++;
	}
	// implement to print out the list
	friend ostream& operator <<(ostream& s, const DoubleLinkedList& list) {
        if (list.head == nullptr) {
			cout << "Empty List. Nothing to Display." << endl;
		}
		else {
            cout << "NULL <-> ";
			Node* temp = list.head;
			while (temp != nullptr) {
				cout << temp->val << " <-> ";
				temp = temp->next;
			}
			cout << "NULL" << endl;
		}
	}
};

int main() {
	DoubleLinkedList a;
	uint32_t n;
    cout << "Enter an integer: ";
    cin >> n;
	for (int i = 0; i < n; i++)
		a.addStart(i);

	for (int i = 0; i < n; i++)
		a.addEnd(i);

	for (int i = 0; i < 3*n/2; i++)
		a.removeStart();

	for (int i = 0; i < n/2 - 5; i++)
		a.removeEnd();
        
	for (int i = 0; i < 10; i++){
		a.insert(1, i);
        cout << a << '\n';
    }
	cout << a << '\n';
}