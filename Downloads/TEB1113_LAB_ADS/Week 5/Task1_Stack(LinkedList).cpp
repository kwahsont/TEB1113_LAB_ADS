#include <iostream>
#include <string>

using namespace std;

class Stack {
    private:
        struct Node { 
            string name;            // node is a blueprint. each node stores name and a pointer to node below it
            Node* next = NULL;      
        };
        
        Node* top = NULL;           // top tracks topmost. starts at null cuz its empty

    public:
        void push(string name) {
            Node* newNode = new Node();     // creates a new empty node
            newNode->name = name;           // fill name
            newNode->next = top;            // point to top
            top = newNode;                  // declare new node as top
        }

        void pop() {
            if (top == NULL) {
                cout << "Stack is empty" << endl;
                return;
            }
            top = top->next;                // move top down to the next node
        }

        void peek() {
            if (top == NULL) {
                cout << "Stack is empty" << endl;
                return;
            }
            cout << "Top: " << top->name << endl;
        }

        void display() {
            if (top == NULL) {
                cout << "Stack is empty" << endl;
                return;
            }
            Node* current = top;
            while (current != NULL) {
                cout << current->name << endl;
                current = current->next;
            }
        }
};

int main() {
    Stack stack;

    stack.push("Aimar");
    stack.push("Ahmad");
    stack.push("Anajana");
    stack.push("Jessy");

    cout << "--- Display ---" << endl;
    stack.display();

    cout << "--- Peek ---" << endl;
    stack.peek();

    cout << "--- Pop ---" << endl;
    stack.pop();
    stack.display();

    return 0;
}