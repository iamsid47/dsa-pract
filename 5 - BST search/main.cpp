#include <iostream>

// Node class representing a node in the binary search tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the binary search tree
void insertNode(Node*& root, int value) {
    if (root == nullptr) {
        root = new Node(value);
        return;
    }

    if (value < root->data) {
        insertNode(root->left, value);
    } else {
        insertNode(root->right, value);
    }
}

// Function to swap the left and right pointers at every node in the tree while maintaining the binary search tree property
void swapPointers(Node* root) {
    if (root == nullptr) {
        return;
    }

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    swapPointers(root->left);
    swapPointers(root->right);
}

// Function to search for a value in the binary search tree
bool searchValue(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return searchValue(root->left, value);
    } else {
        return searchValue(root->right, value);
    }
}

int main() {
    Node* root = nullptr;

    // Construct the binary search tree by inserting values
    int values[] = {5, 2, 8, 1, 4, 7, 9};
    int numValues = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < numValues; ++i) {
        insertNode(root, values[i]);
    }

    // Insert a new node with value 3
    insertNode(root, 3);

    // Swap the left and right pointers at every node while maintaining the binary search tree property
    swapPointers(root);

    // Search for a value
    int searchVal = 4;
    bool found = searchValue(root, searchVal);
    if (found) {
        std::cout << "Value " << searchVal << " found in the tree." << std::endl;
    } else {
        std::cout << "Value " << searchVal << " not found in the tree." << std::endl;
    }

    // Cleanup memory (optional)
    // TODO: Implement a function to delete the nodes of the tree

    return 0;
}

