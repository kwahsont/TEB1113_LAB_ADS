#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;
    Node* prev;

    Node(string n) {
        name = n;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertEnd(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    void insertAfter(string afterName, string newName) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr && current->name != afterName) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << afterName << " not found." << endl;
            return;
        }

        Node* newNode = new Node(newName);
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }

    void deleteByName(string name) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->name == name) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->name == name) {
                Node* temp = current->next;
                current->next = temp->next;
                if (temp->next != nullptr) {
                    temp->next->prev = current;
                }
                delete temp;
                return;
            }
            current = current->next;
        }

        cout << name << " not found." << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->name << endl;
            current = current->next;
        }
    }

    void displayReverse() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        while (current != nullptr) {
            cout << current->name << endl;
            current = current->prev;
        }
    }
};

int main() {
    LinkedList list;

    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

    cout << "Initial list:" << endl;
    list.display();

    list.insertAfter("Anjana", "Ali");
    cout << "\nAfter insertAfter (Ali after Anjana):" << endl;
    list.display();

    list.insertEnd("Jane");
    cout << "\nAfter insertEnd (Jane):" << endl;
    list.display();

    list.deleteByName("Jessy");
    cout << "\nAfter deleteByName (Jessy):" << endl;
    list.display();

    cout << "\nReverse list:" << endl;
    list.displayReverse();

    cout << "\nFinal list:" << endl;
    list.display();

    return 0;
}