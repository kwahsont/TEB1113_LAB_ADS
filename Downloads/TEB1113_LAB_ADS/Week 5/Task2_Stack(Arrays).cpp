#include <iostream>
#include <string>

using namespace std;

class stack{
    private:
        string arr[100];
        int topIndex = -1;              // tracks which slot on top

    public:
        // push
        void push(string name) {
            arr[++topIndex] = name;     // increment of topIndex(top) and pushing name into that index
        }

        // pop
        void pop() {
            topIndex--;
        }

        // peek
        void peek() {
            cout << "Top: " << arr[topIndex] << endl;
        }

        // display
        void display() {
            for (int i = topIndex; i >= 0; i--) {
                cout << arr[i] << endl;
            }
        }
};

int main(){
    stack s;

    s.push("Ahmad");
    s.push("Ammir");
    s.push("Harees");
    s.push("Azimi");

    cout << "- Display -" << endl;
    s.display();
    cout << endl;

    cout << "- Peek -" << endl;
    s.peek();
    cout << endl;

    cout << "- Pop -" << endl;
    s.pop();
    s.display();
    cout << endl;
    
    cout << "- Peek after pop -" << endl;
    s.peek();

    return 0;
}