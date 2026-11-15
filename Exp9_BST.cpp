
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

class BST
{
public:
    node *root;

    BST()
    {
        root = NULL;
    }

    node* insert(node *root, int value);
    int height(node *root);
    int minimum(node *root);
    void mirror(node *root);
    int search(node *root, int value);

    void inorder(node *root);
    void preorder(node *root);
    void postorder(node *root);
};

// Insert Node
node* BST :: insert(node *root, int value)
{
    if(root == NULL)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;

        return newnode;
    }

    if(value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if(value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        cout << "Duplicate value not allowed!" << endl;
    }

    return root;
}

// Calculate Height (Number of Nodes in Longest Path)
int BST :: height(node *root)
{
    if(root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if(leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

// Find Minimum Value
int BST :: minimum(node *root)
{
    if(root == NULL)
        return -1;

    while(root->left != NULL)
    {
        root = root->left;
    }

    return root->data;
}

// Mirror Tree
void BST :: mirror(node *root)
{
    if(root == NULL)
        return;

    node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// Search Value
int BST :: search(node *root, int value)
{
    if(root == NULL)
        return 0;

    if(root->data == value)
        return 1;

    if(value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

// Inorder Traversal
void BST :: inorder(node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Preorder Traversal
void BST :: preorder(node *root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal
void BST :: postorder(node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    BST bt;
    int ch, value;

    do
    {
        cout << "\n--- Binary Search Tree Menu ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Display Inorder\n";
        cout << "3. Display Preorder\n";
        cout << "4. Display Postorder\n";
        cout << "5. Longest Path from Root\n";
        cout << "6. Minimum Value\n";
        cout << "7. Mirror Tree\n";
        cout << "8. Search Value\n";
        cout << "9. Exit\n";

        cout << "Enter your choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                bt.root = bt.insert(bt.root, value);
                break;

            case 2:
                cout << "Inorder Traversal: ";
                bt.inorder(bt.root);
                cout << endl;
                break;

            case 3:
                cout << "Preorder Traversal: ";
                bt.preorder(bt.root);
                cout << endl;
                break;

            case 4:
                cout << "Postorder Traversal: ";
                bt.postorder(bt.root);
                cout << endl;
                break;

            case 5:
                cout << "Longest Path from Root: "
                     << bt.height(bt.root) << " nodes" << endl;
                break;

            case 6:
                if(bt.root == NULL)
                    cout << "Tree is empty!" << endl;
                else
                    cout << "Minimum Value: "
                         << bt.minimum(bt.root) << endl;
                break;

            case 7:
                bt.mirror(bt.root);
                cout << "Tree mirrored successfully!" << endl;
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> value;

                if(bt.search(bt.root, value))
                    cout << "Value found!" << endl;
                else
                    cout << "Value not found!" << endl;

                break;

            case 9:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while(ch != 9);

    return 0;
}
