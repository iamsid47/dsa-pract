#include <iostream>
using namespace std;
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

// Function to find the number of nodes in the longest path from the root
int findLongestPath(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftDepth = findLongestPath(root->left);
    int rightDepth = findLongestPath(root->right);

    return max(leftDepth, rightDepth) + 1;
}

// Function to find the minimum data value in the binary search tree
int findMinimumValue(Node* root) {
    if (root->left == nullptr) {
        return root->data;
    }

    return findMinimumValue(root->left);
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

    // Find the number of nodes in the longest path from the root
    int longestPath = findLongestPath(root);
    cout << "Number of nodes in the longest path from the root: " << longestPath << endl;

    // Find the minimum data value in the tree
    int minValue = findMinimumValue(root);
    cout << "Minimum data value found in the tree: " << minValue << endl;

    return 0;
}
