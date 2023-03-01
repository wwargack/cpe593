class OrderedBinaryTree{
private:
    class Node{
        int val;
        Node* left; 
        Node* right;
        Node(int v) : val(v), left(nullptr), right(nullptr) {}
    };
public:
    Node root;
    
};