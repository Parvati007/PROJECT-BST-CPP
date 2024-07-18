//BST :- BINARY SERACH TREE CODE IN CPP
//--------------------------------------

#include <iostream>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* leftChild;
    TreeNode* rightChild;

    TreeNode(int item) {
        value = item;
        leftChild = rightChild = nullptr;
    }
};

class BinarySearchTreeOperations {
public:
    TreeNode* root;

    BinarySearchTreeOperations() {
        root = nullptr;
    }

    void addValue(int value) {
        root = insertNodeRecursively(root, value);
    }

    //INSERTION OF NUMBER

    TreeNode* insertNodeRecursively(TreeNode* root, int value) {
        if (root == nullptr) {
            return new TreeNode(value);
        }

        if (value < root->value)
            root->leftChild = insertNodeRecursively(root->leftChild, value);
        else if (value > root->value)
            root->rightChild = insertNodeRecursively(root->rightChild, value);

        return root;
    }

    bool findValue(int value) {
        return searchNodeRecursively(root, value);
    }

    //SEARCHING OF NUMBER

    bool searchNodeRecursively(TreeNode* root, int value) {
        if (root == nullptr) {
            return false;
        }
        if (root->value == value) {
            return true;
        }
        if (root->value > value) {
            return searchNodeRecursively(root->leftChild, value);
        }
        return searchNodeRecursively(root->rightChild, value);
    }

    void removeValue(int value) {
        root = deleteNodeRecursively(root, value);
    }


    //DELETION OF NUMBER

    TreeNode* deleteNodeRecursively(TreeNode* root, int value) {
        if (root == nullptr) return root;

        if (value < root->value)
            root->leftChild = deleteNodeRecursively(root->leftChild, value);
        else if (value > root->value)
            root->rightChild = deleteNodeRecursively(root->rightChild, value);
        else {
            if (root->leftChild == nullptr)
                return root->rightChild;
            else if (root->rightChild == nullptr)
                return root->leftChild;

            root->value = findMinValue(root->rightChild);
            root->rightChild = deleteNodeRecursively(root->rightChild, root->value);
        }

        return root;
    }

    int findMinValue(TreeNode* root) {
        int minValue = root->value;
        while (root->leftChild != nullptr) {
            minValue = root->leftChild->value;
            root = root->leftChild;
        }
        return minValue;
    }

    //INORDER TRAVERSAL

    void inOrderTraversal(TreeNode* root) {           
        if (root != nullptr) {
            inOrderTraversal(root->leftChild);
            cout << root->value << " ";
            inOrderTraversal(root->rightChild);
        }
    }

    //PREORDER TRAVERSAL

    void preOrderTraversal(TreeNode* root) {
        if (root != nullptr) {
            cout << root->value << " ";
            preOrderTraversal(root->leftChild);
            preOrderTraversal(root->rightChild);
        }
    }

    //POSTORDER TRAVERSAL

    void postOrderTraversal(TreeNode* root) {
        if (root != nullptr) {
            postOrderTraversal(root->leftChild);
            postOrderTraversal(root->rightChild);
            cout << root->value << " ";
        }
    }
};

int main() {
    BinarySearchTreeOperations bstOperations;
    int numberOfElements;

    cout << "Enter the number of elements to insert: ";
    cin >> numberOfElements;

    cout << "Enter " << numberOfElements << " elements:\n";
    for (int i = 0; i < numberOfElements; i++) {
        int value;
        cin >> value;
        bstOperations.addValue(value);
    }

    bool running = true;

    while (running) {
        cout << "\nCurrent BST (In-Order): ";
        bstOperations.inOrderTraversal(bstOperations.root);
        cout << "\nCurrent BST (Pre-Order): ";
        bstOperations.preOrderTraversal(bstOperations.root);
        cout << "\nCurrent BST (Post-Order): ";
        bstOperations.postOrderTraversal(bstOperations.root);

        cout << "\n\nMenu:";
        cout << "\n1. Insert an element";
        cout << "\n2. Search for an element";
        cout << "\n3. Delete an element";
        cout << "\n4. Exit";
        cout << "\nChoose an option: ";
        int choice;
        cin >> choice;

        //USING SWITCH CASE BELOW

        switch (choice) {
            case 1: {
                cout << "Enter value to insert: ";
                int insertValue;
                cin >> insertValue;
                bstOperations.addValue(insertValue);
                cout << "Inserted " << insertValue << "\n";
                break;
            }

            case 2: {
                cout << "Enter value to search: ";
                int searchValue;
                bool found;
                cin >> searchValue;
                found = bstOperations.findValue(searchValue);
                if (found) {
                    cout << "Search " << searchValue << ": Found\n";
                } else {
                    cout << "Search " << searchValue << ": Not Found\n";
                }
                break;
            }

            case 3: {
                cout << "Enter value to delete: ";
                int deleteValue;
                cin >> deleteValue;
                bstOperations.removeValue(deleteValue);
                cout << "Deleted " << deleteValue << "\n";
                break;
            }

            case 4: {
                running = false;
                cout << "Exiting...\n";
                break;
            }

            default: {
                cout << "Invalid option. Please try again.\n";
                break;
            }
        }
    }

    return 0;
}
