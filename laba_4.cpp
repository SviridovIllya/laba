#include <iostream>
#include <assert.h>
//1,3,7,13,18
using namespace std;

struct TreeNode{
    TreeNode* first_child;
    TreeNode* next;
    TreeNode* prev;
    TreeNode* parent;
    int data;

    TreeNode(int data, TreeNode* prev=nullptr,TreeNode* next=nullptr, TreeNode* parent=nullptr,TreeNode* first_child=nullptr)
    {
        this->data=data;
        this->prev=prev;
        this->next=next;
        this->parent=parent;
        this->first_child=first_child;
    }
};

struct Tree{
    TreeNode* root;
    Tree()
    {
        root= nullptr;
    }
    TreeNode *add(int data, TreeNode *parent = nullptr) {
        TreeNode *new_node = new TreeNode(data);
        if (parent == nullptr) {
            if (this->root) {
                add_child_node(root, new_node);
            } else {
                this->root = new_node;
            }
        } else {
            add_child_node(parent, new_node);
        }

        return new_node;
    }

    void add_child_node(TreeNode *parent, TreeNode *child) {
        assert(parent != nullptr);
        assert(child != nullptr);

        child->parent = parent;

        TreeNode *current = parent->first_child;
        if (!current) {
            parent->first_child = child;
            return;
        }
        while (current->next) {
            current = current->next;
        }
        current->next = child;
        child->prev = current;
    }

    void print(TreeNode* tree_to_print= nullptr)
    {
        if(!tree_to_print)
        {
            tree_to_print= this->root;
            if(!tree_to_print)
            {
                cout << "Nothing"<< endl;
            }
        }
        cout << tree_to_print->data<<"(";
        TreeNode* current = tree_to_print->first_child;
        while (current)
        {
            print(current);
            current=current->next;
            if(current)
            {
                cout << ", ";
            }
        }
        cout << ")";
    }
    Tree remove(TreeNode* node, Tree& tree)
    {
        if (tree.root == nullptr)
        {
            tree.add(node->data);
        }
        if (node->prev)
        {
            node->prev->next = node->next;
        }
        else {
            if (node->parent)
            {
                node->parent->first_child = node->next;
            }
            else {
                this->root = nullptr;
            }
        }
        if (node->next)
        {
            node->next->prev = node->prev;
        }

        TreeNode* current = node->next;

        while (current)
        {
            current->data = current->data - 1;
            current = current->next;
        }
        delete current;

        while (node->first_child)
        {
            tree.add(node->first_child->data, tree.root);
            remove(node->first_child, tree);
        }

        delete node;

        return tree;
    }
};

struct BinaryTreeNode {
    int data;
    BinaryTreeNode* right;
    BinaryTreeNode* left;
    BinaryTreeNode(int data, BinaryTreeNode* right = nullptr, BinaryTreeNode* left = nullptr) {
        this->data = data;
        this->right = right;
        this->left = left;
    }
};

struct BinaryTree {
    BinaryTreeNode* root;
    BinaryTree()
    {
        root = nullptr;
    }

    BinaryTreeNode* add(int data, BinaryTreeNode* node)
    {
        BinaryTreeNode* new_bintree = new BinaryTreeNode(data);
        if (this->root == nullptr)
        {
            this->root = new_bintree;
            node = this->root;
        }
        else if (data < node->data)
        {
            if (node->left == nullptr)
            {
                node->left = new_bintree;
            }
            else{
                add(data, node->left);
            }
        }
        else
        {
            if (node->right == nullptr)
            {
                node->right = new_bintree;
            }
            else{
                add(data, node->right);}
        }
        return node;
    }

    void print(BinaryTreeNode* node_to_print = nullptr)
    {
        if (node_to_print)
        {
            cout << node_to_print->data << "(";
            print(node_to_print->left);
            if (node_to_print->right != nullptr && node_to_print->left != nullptr)
            {
                cout << ", ";
            }
            print(node_to_print->right);
            cout << ")";
        }
    }
};
void Demonstrative()
{
    Tree tree;
    BinaryTree binary;
    Tree add;
    TreeNode* current;
    binary.add(15, binary.root);
    binary.add(12, binary.root);
    binary.add(6, binary.root);
    binary.add(10, binary.root);
    binary.add(9, binary.root);
    binary.add(66, binary.root);
    binary.add(21, binary.root);
    binary.add(8, binary.root);
    binary.add(3, binary.root);
    binary.add(17, binary.root);
    binary.add(19, binary.root);
    binary.add(18, binary.root);
    binary.add(27, binary.root);
    cout << " binary tree looks like:" << endl;
    binary.print(binary.root);
    cout << endl << "lets push more elements " << endl;
    binary.add(4, binary.root);
    binary.add(7, binary.root);
    binary.add(2, binary.root);
    binary.add(1, binary.root);
    cout << "binary tree look: ";
    binary.print(binary.root);
    cout << endl;
    tree.add(8);
    tree.add(11);
    tree.add(14);
    tree.add(7);
    tree.add(93, tree.root->first_child);
    tree.add(15, tree.root->first_child);
    tree.add(18, tree.root->first_child->next);
    tree.add(2, tree.root->first_child->next->next);
    tree.add(42, tree.root->first_child->next->next->first_child);
    cout << "Tree: ";
    tree.print();
    add = tree.remove(current, add);
    cout << "deleted subtree is: ";
    add.print();
    tree.print();
    cout << endl;
}

//for interactive
Tree tree;
BinaryTree binary;
Tree add;
TreeNode* current;
void interactive()
{
    int chose = 0;
    cout << endl;
    cout << "(0) Exit" << endl
         << "(1) Add" << endl
         << "(2) AddBinary" << endl
         << "(3) Print" << endl
         << "(4) PrintBinary" << endl
         << "(5) Remove" << endl;
    cin >> chose;
    switch (chose) {
        case 0:
            delete current;
            break;
        case 1:
            cout << "enter number" << endl;
            int number;
            cin >> number;
            tree.add(number);
            interactive();
            break;
        case 2:
            cout << "enter number" << endl;
            int number2;
            cin >> number2;
            binary.add(number2,binary.root);
            interactive();
            break;
        case 3:
            tree.print();
            interactive();
            break;
        case 4:
            binary.print(binary.root);
            interactive();
            break;
        case 5:
            tree.remove(current,add);
            tree.print();
            interactive();
            break;
    }
}
void action_menu() {
    int statemenu = 0;
    cout << "(0) Exit" << endl
         << "(1) Demonstrative" << endl
         << "(2) Interactive mode" << endl;
    cin >> statemenu;
    switch (statemenu){
        case 0:
            break;
        case 1:
            Demonstrative();
            break;
        case 2:
            interactive();
            break;
    }
}
int main(){
    action_menu();
}
