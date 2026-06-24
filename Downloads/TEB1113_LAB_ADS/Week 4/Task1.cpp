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
            newNode->next = head;
            newNode->prev = head;
            return;
        }

        Node* tail = head->prev;

        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    void insertAfter(string afterName, string newName) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            if (current->name == afterName) {
                Node* newNode = new Node(newName);
                newNode->next = current->next;
                newNode->prev = current;
                current->next->prev = newNode;
                current->next = newNode;
                return;
            }
            current = current->next;
        } while (current != head);

        cout << afterName << " not found." << endl;
    }

    void deleteByName(string name) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            if (current->name == name) {
                // only one node
                if (current->next == head && current == head) {
                    delete current;
                    head = nullptr;
                    return;
                }

                // update links
                current->prev->next = current->next;
                current->next->prev = current->prev;

                // if deleting head, move head forward
                if (current == head) {
                    head = head->next;
                }

                delete current;
                return;
            }
            current = current->next;
        } while (current != head);

        cout << name << " not found." << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* current = head;
        do {
            cout << current->name << endl;
            current = current->next;
        } while (current != head);
    }

    void displayReverse() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* current = head->prev;
        do {
            cout << current->name << endl;
            current = current->prev;
        } while (current != head->prev);
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