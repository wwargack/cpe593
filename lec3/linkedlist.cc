
class LinkedList {
    private:
        class Node{ //LinkedList::Node
            int val;
            Node* next; //reference to the next node
            Node(int v, Node* n) : val(v), next(n) {} //Node constructor that initializes val to v and next to n
        };
        Node* head;

    public:
        LinkedList() : head(nullptr) {} //LinkedList consturctor that initialized head to null
        ~LinkedList() {
            Node* temp;
            for (Node* p = head; p != nullptr; p = temp){
                temp = p->next;
                delete p;
            }
        }
        LinkedList(const LinkedList& orig) = delete;
        LinkedList& operator =(const LinkedList& orig) = delete;

        void addStart(int v){
            head = new Node(v, head);

            /* same as one line above
            Node* temp = new Node;
            temp->val = v;
            temp->next = head;
            head = temp;
            */
        }

        void addEnd(int v){
            if(head == nullptr){
                head = new Node(v, nullptr);
                return;
            }
            Node* p;
            for(p = head; p->next != nullptr; p = p->next){

            }
            //after loop p is pointing to last element
            p->next = new Node(v, nullptr);
        }

        //bad for linked list, good for dynamic array
        //insert after the indexth element
        void insert(int index, int val){
            Node* p = head;
            for (int i = 0; i < index && p != nullptr; i++)
                p = p->next; //p is pointing to ith node
                p->next = new Node(val, p->next);
        }

        
        class Iterator{
            private:
                Node* current;
            public:
                Iterator(LinkedList& list){ current = list.head; }
                void operator ++() { current = current->next; }
                bool operator !() const { return current != nullptr; }
                int operator *() const { return current->val; }
        };
        void insert(Iterator& i, int val){

        }

        void removeStart(){ //O(1)
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        void removeEnd(){ //O(n)
            if(head == nullptr){
                return;
            }
            Node* p = head;
            Node* q = p->next;
            if (q == nullptr){
                delete head;
                head = nullptr;
                return;
            }
            for(; q->next != nullptr; p = q, q = q->next);
            //p is pointing to 2nd to last element
            //q is pointing to last element
            delete q;
            p->next = nullptr;

        }
};