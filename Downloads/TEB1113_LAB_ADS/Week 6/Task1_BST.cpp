#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string name;            // each node has left and right child pointers
    Node* left;             // left pointer points to the left child of the node
    Node* right;            // right pointer points to the right child of node

    Node(string n) {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};


class BST {
public:
    Node* root;   // like 'head' in a linked list, but it's the TOP of the tree

    BST() {
        root = nullptr;
    }

    void insert(string name) {
        Node* newNode = new Node(name);

        if (root == nullptr) {
            root = newNode;                             // empty tree, new node becomes root
            return;
        }

        Node* current = root;
        while (true) {
            if (name < current->name) {                 // name alphabetically less than current node's name, go left
                if (current->left == nullptr) {
                    current->left = newNode;            // empty left child, insert new node here
                    return;
                }
                current = current->left;                // move to the left child and continue searching
            } else {
                if (current->right == nullptr) {        // name alphabetically greater than or equal, go right
                    current->right = newNode;           // empty right child, insert new node here
                    return;
                }
                current = current->right;               // move to the right child and continue searching
            }
        }
    }

    bool search(string name) {
        Node* current = root;                       // start searching from the root
        while (current != nullptr) {                // while there are still nodes to search
            if (name == current->name) {
                return true;                        // found the name in the tree
            } else if (name < current->name) {
                current = current->left;            // name alphabetically smaller, go left
            } else {
                current = current->right;           // name alphabetically larger, go right
            }
        }
        return false;                               // name not found in the tree
    }

    Node* deleteNode(Node* node, string name) {
        if (node == nullptr) {
            cout << name << " not found." << endl;
            return nullptr;
        }

        if (name < node->name) {
            node->left = deleteNode(node->left, name);    // search left subtree
        } else if (name > node->name) {
            node->right = deleteNode(node->right, name);  // search right subtree
        } else {
            // Found the node. Three cases:

            // Case 1: no children (leaf) -> just delete it
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }

            // Case 2: one child -> child replaces this node
            if (node->left == nullptr) {
                Node* child = node->right;
                delete node;
                return child;
            }
            if (node->right == nullptr) {
                Node* child = node->left;
                delete node;
                return child;
            }

            // Case 3: two children -> find in-order successor
            // (the SMALLEST name in the RIGHT subtree)
            Node* successor = node->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            node->name = successor->name;                            // copy successor's name into this node
            node->right = deleteNode(node->right, successor->name);  // remove the duplicate successor
        }
        return node;
    }

    void deleteByName(string name) {
        root = deleteNode(root, name);
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);            // 1. visit left subtree
        cout << node->name << endl;     // 2. print current node
        inorder(node->right);           // 3. visit right subtree
    }

    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->name << endl;     // 1. print current node FIRST
        preorder(node->left);           // 2. visit left subtree
        preorder(node->right);          // 3. visit right subtree
    }

    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);          // 1. visit left subtree
        postorder(node->right);         // 2. visit right subtree
        cout << node->name << endl;     // 3. print current node LAST
    }

    void displayInorder() {
        cout << "Inorder:" << endl;
        inorder(root);
    }

    void displayPreorder() {
        cout << "Preorder:" << endl;
        preorder(root);
    }

    void displayPostorder() {
        cout << "Postorder:" << endl;
        postorder(root);
    }
};

int main() {
    BST tree;

    // Mixed insertion order so the tree actually branches
    tree.insert("Charlie");   // root
    tree.insert("Alice");     // left of Charlie
    tree.insert("Bob");       // right of Alice
    tree.insert("David");     // right of Charlie

    tree.displayInorder();
    cout << endl;

    tree.displayPreorder();
    cout << endl;

    tree.displayPostorder();
    cout << endl;

    // Demonstrate search
    cout << "Search Bob: " << (tree.search("Bob") ? "found" : "not found") << endl;
    cout << "Search Eve: " << (tree.search("Eve") ? "found" : "not found") << endl;
    cout << endl;

    // Demonstrate delete
    tree.deleteByName("Alice"); 
    cout << "After deleting Alice:" << endl;
    tree.displayInorder();

    return 0;
}