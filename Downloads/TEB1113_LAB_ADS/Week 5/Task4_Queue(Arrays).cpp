#include <iostream>
#include <string>

using namespace std;

class Queue{
    private:
        string arr[100];
        int front = -1;
        int rear = -1;

    public:
        void enqueue(string name){
            if (rear >= 99){
                cout << "Queue is full" << endl;
                return;
            }

            if (front == -1){
                front = 0;
            }

            arr[++rear] = name;
        }

        void dequeue(){
            if (front == -1){
                cout << "Queue is empty" << endl;
                return;
            }

            front++;

            if (front > rear){
                front = -1;
                rear = -1;
            }
        }

        void display(){
            if (front == -1){
                cout << "Queue is empty" << endl;
                return;
            }
            for (int i = front; i <= rear; i++){
                cout << arr[i] << endl;
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