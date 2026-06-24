#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string n) {
        name = n;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // ===== INSERT =====
    void insertFront(string name) {
        Node* newNode = new Node(name);
        newNode->next = head;
        head = newNode;
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
    }

    void insertAfter(string afterName, string newName) {
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
        current->next = newNode;
    }

    void insertBefore(string beforeName, string newName) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->name == beforeName) {
            insertFront(newName);
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->name != beforeName) {
            current = current->next;
        }
        if (current->next == nullptr) {
            cout << beforeName << " not found." << endl;
            return;
        }
        Node* newNode = new Node(newName);
        newNode->next = current->next;
        current->next = newNode;
    }

    void insertAtPosition(int pos, string name) {
        if (pos == 1) {
            insertFront(name);
            return;
        }
        Node* current = head;
        for (int i = 1; i < pos - 1; i++) {
            if (current == nullptr) {
                cout << "Position out of range." << endl;
                return;
            }
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Position out of range." << endl;
            return;
        }
        Node* newNode = new Node(name);
        newNode->next = current->next;
        current->next = newNode;
    }

    // ===== DELETE =====
    void deleteFront() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    void deleteByName(string name) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->name == name) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->name != name) {
            current = current->next;
        }
        if (current->next == nullptr) {
            cout << name << " not found." << endl;
            return;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    void deleteByPosition(int pos) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (pos == 1) {
            deleteFront();
            return;
        }
        Node* current = head;
        for (int i = 1; i < pos - 1; i++) {
            if (current->next == nullptr) {
                cout << "Position out of range." << endl;
                return;
            }
            current = current->next;
        }
        if (current->next == nullptr) {
            cout << "Position out of range." << endl;
            return;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    void deleteAll() {
        while (head != nullptr) {
            deleteFront();
        }
        cout << "All nodes deleted." << endl;
    }

    // ===== DISPLAY =====
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
};

int main() {
    LinkedList list;

    list.insertEnd("Aimar");
    list.insertEnd("Ahmad");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

    cout << "Initial list:" << endl;
    list.display();

    list.insertFront("Zara");
    cout << "\nAfter insertFront (Zara):" << endl;
    list.display();

    list.insertEnd("Bobby");
    cout << "\nAfter insertEnd (Bobby):" << endl;
    list.display();

    list.insertAfter("Anjana", "Ali");
    cout << "\nAfter insertAfter (Ali after Anjana):" << endl;
    list.display();

    list.insertBefore("Ahmad", "Cathy");
    cout << "\nAfter insertBefore (Cathy before Ahmad):" << endl;
    list.display();

    list.insertAtPosition(3, "Danny");
    cout << "\nAfter insertAtPosition (Danny at position 3):" << endl;
    list.display();

    list.deleteFront();
    cout << "\nAfter deleteFront:" << endl;
    list.display();

    list.deleteEnd();
    cout << "\nAfter deleteEnd:" << endl;
    list.display();

    list.deleteByName("Anjana");
    cout << "\nAfter deleteByName (Anjana):" << endl;
    list.display();

    list.deleteByPosition(2);
    cout << "\nAfter deleteByPosition (2):" << endl;
    list.display();

    list.deleteAll();
    cout << "\nAfter deleteAll:" << endl;
    list.display();

    return 0;
}