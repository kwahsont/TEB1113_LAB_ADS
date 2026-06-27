#include <iostream>
#include <string>

using namespace std;

class Queue{
    private:
        struct Node{
            string name;
            Node* next = NULL;
        };
        
        Node* front = NULL;
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

            rear->next = newNode;
            rear = newNode;
        }

        void dequeue(){
            if (front == NULL){
                cout << "Queue is empty" << endl;
                return;
            }
            front = front->next;

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