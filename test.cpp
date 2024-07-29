#include <iostream>

class BST {
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }

    bool search(Node* node, int key) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == key) {
            return true;
        }
        if (key < node->data) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int key) {
        if (node == nullptr) return node;
        if (key < node->data) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->data) {
            node->right = deleteNode(node->right, key);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() : root(nullptr) {}

    void insert(int data) {
        root = insert(root, data);
    }

    bool search(int key) {
        return search(root, key);
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    void inorder() {
        inorder(root);
        std::cout << std::endl;
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    std::cout << "Inorder traversal: ";
    tree.inorder();

    std::cout << "Delete 20\n";
    tree.deleteNode(20);
    std::cout << "Inorder traversal: ";
    tree.inorder();

    return 0;
}