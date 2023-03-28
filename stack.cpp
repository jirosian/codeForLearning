#include <iostream>
using namespace std;

class Stack {
    
    class Node { 
        public:
            int data;
            Node* next;
    };
    
    public:
        Node* top = NULL;
        int capacity = 0;
    
    void push(int d) {
        Node* newNode = new Node();
        newNode->data = d;
        newNode->next = top;
        top = newNode;
    
        capacity++;
        
    }
    
    int peek() {
        if(!isEmpty()) 
            return top->data;
        else {
            cout << "Empty stack" << endl;
        }
    }
    
    void pop() {
        Node* temp;
        temp = top;
        
        top = top->next;
        
        capacity--;
        
        free(temp);
    }
    
    bool isEmpty() {
        return top == NULL;
    }
    
    int size() {
        return capacity;
    }
    
    
    void display() {
        for(int i =0;i<capacity;i++){
            cout << top->data <<  "->";
            top = top->next;
        }
        cout << endl;
    }
};

int main()
{
   
    Stack* stack = new Stack();
    stack->push(5);
    stack->push(8);
    stack->push(3);
    stack->pop();
    stack->pop();
    
    stack->display();
    cout << "The size of this stack is " <<  stack->size() << endl;

    return 0;
}
