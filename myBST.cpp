#include <iostream>

using namespace std;

class BST {
    struct Node {
        int data;
        Node* left;
        Node* right;
    };
    
    Node* root;
    
    Node* GetNewNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        
        return newNode;
    }
    
    Node* Insert(Node* root, int data) {
        if(root == NULL) root = GetNewNode(data);
        else if(data <= root->data) root->left = Insert(root->left, data);
        else root->right = Insert(root->right, data);
        
        return root;
    }
    
    bool Search(Node* root, int data) {
        if(root == NULL) return false;
        if(root->data == data) return true;
        else if(data <= root->data) return Search(root->left, data);
        else return Search(root->right, data);
    }
    
    Node* findMin(Node* root) {
        if(root == NULL) return NULL;
        else if(root->left == NULL) return root;
        else return findMin(root->left);
    }
    
    Node* findMax(Node* root) {
        if(root == NULL) return NULL;
        else if(root->right == NULL) return root;
        else return findMax(root->right);
    }
    
    Node* Remove(Node* root, int data) {
        if(root == NULL) return NULL;
        else if(root->data < data) root->right = Remove(root->right,  data);
        else if(root->data > data) root->left = Remove(root->left,  data);
        
        else //When I found the data I wanna remove. 
        {   
            // Case 1: No child
            if(root->left == NULL && root->right == NULL) {
                delete root; // root is a dangling pointer so it still has an address.
                root = NULL; 
                return root;
            } 
            // Case 2: One child
            else if(root->left == NULL) { 
                Node* temp = root;
                root = root->right; // Move the pointer to the right child
                delete temp; 
            }
            else if(root->right == NULL) {
                Node* temp = root;
                root = root->left;
                delete temp;
            }
            // Case 3: 2 children
            else { 
                Node* temp = findMin(root->right);
                root->data = temp->data;
                root->right = Remove(root->right, temp->data);
            }
        }
        return root;
    }
    
    Node* makeEmpty(Node* root) {
        if(root != NULL) {
            makeEmpty(root->left);
            makeEmpty(root->right);
            delete root;
        }
        return NULL;
    }
    
    public:
        BST() {
            root = NULL;
        }
        
        ~BST() {
           root = makeEmpty(root);
        }
        
        void Insert(int data) {
            root = Insert(root, data);
        }
        
        bool Search(int data) {
            return Search(root, data);
        }
        
        int findMin() {
            Node* minNode = findMin(root);
            return minNode->data;
        }
        
        int findMax() {
            Node* maxNode = findMax(root);
            return maxNode->data;
        }
        
        void Remove(int data) {
            root = Remove(root,data); 
        }
        
    
};

int main()
{
    BST bst;
    bst.Insert(15);
    bst.Insert(10);
    bst.Insert(20);
    bst.Insert(2);
    bst.Insert(1);
    bst.Insert(50);
    bst.Insert(3);
    bst.Insert(9);
    
    if(bst.Search(5) == true) cout << "True";
    else cout << "False" << endl;
    
    cout << bst.findMin() << endl;
    cout << bst.findMax() << endl;
    
    bst.Remove(10);
    if(bst.Search(10) == true) cout << "True";
    else cout << "False" << endl;
    cout << bst.findMin() << endl;

    

    return 0;
}
