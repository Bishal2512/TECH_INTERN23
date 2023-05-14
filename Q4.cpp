#include <iostream>
#include <queue>

// Structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new BST node
Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        std::cout << "Memory error\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node in BST
Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        root = createNode(data);
        return root;
    }
    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    return root;
}

// Function to find the maximum width of a BST
int maxWidth(Node* root) {
    if (root == nullptr)
        return 0;
    
    int maxWidth = 0;
    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        maxWidth = std::max(maxWidth, size);

        for (int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }

    return maxWidth;
}

// Driver code
int main() {
    Node* root = nullptr;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 3);
    root = insertNode(root, 8);
    root = insertNode(root, 12);
    root = insertNode(root, 17);
    root = insertNode(root, 20);
    root = insertNode(root, 25);
    root = insertNode(root, 28);
    root = insertNode(root, 2);

    int width = maxWidth(root);
    std::cout << "Maximum width of the tree: " << width << "\n";

    return 0;
}
