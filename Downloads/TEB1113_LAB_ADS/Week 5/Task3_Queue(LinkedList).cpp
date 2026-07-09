#include <iostream>
#include <string>

using namespace std;

class Queue{
    private:
        struct Node{
            string name;            // each node stores name and a pointer to next
            Node* next = NULL;
        };
        
        Node* front = NULL;         // queue has two pointers, front(first person in line) and rear(last person in line).
        Node* rear = NULL;
    
    public:
        void enqueue(string name){
            Node* newNode = new Node();
            newNode->name = name;

            if (rear == NULL){
                front = newNode;
                rear = newNode;
                return;
            }

            rear->next = newNode;   // rear's next pointer points to newNode
            rear = newNode;         // declare newNode as rear
        }

        void dequeue(){
            if (front == NULL){
                cout << "Queue is empty" << endl;
                return;
            }
            front = front->next;    // basically shifting front to the next node

            if (front == NULL){
                rear = NULL;
            }
        }

        void display(){
            if (front == NULL){
                cout << "Queue is empty" << endl;
                return;
            }
            Node* current = front;
            while (current != NULL){
                cout << current->name << endl;
                current = current->next;
            }
        }
};

int main(){
    Queue q;

    q.enqueue("Ahmad");
    cout << "Enqueue Ahmad:" << endl;
    q.display(); cout << endl;

    q.enqueue("Ammir");
    cout << "Enqueue Ammir:" << endl;
    q.display(); cout << endl;

    q.enqueue("Harees");
    cout << "Enqueue Harees:" << endl;
    q.display(); cout << endl;

    q.enqueue("Azimi");
    cout << "Enqueue Azimi:" << endl;
    q.display(); cout << endl;

    cout << "- Display full queue -" << endl;
    q.display();
    cout << endl;

    cout << "- Dequeue -" << endl;
    q.dequeue();
    q.display();

    return 0;
}