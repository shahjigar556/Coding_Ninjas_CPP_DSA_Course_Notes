#include "BinaryTreeNode.h"
#include <iostream>
using namespace std;
class BST
{
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root = nullptr;
    }
    ~BST()
    {
        delete root;
    }

private:
    BinaryTreeNode<int> *deleteData(int data, BinaryTreeNode<int> *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (node->data < data)
        {
            node->right = deleteData(data, node->right);
            return node;
        }
        else if (node->data > data)
        {
            node->left = deleteData(data, node->left);
            return node;
        }
        else // delete the root itself
        {
            if (node->left == nullptr) // left is a null but right is not a null
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = nullptr;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) // left is not null but right is a null
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = nullptr;
                delete node;
                return temp;
            }
            else if (node->left == nullptr && node->right == nullptr) // root is a leaf
            {
                delete node;
                return nullptr;
            }
            else // delet the root when none of the choldren are empty
            {
                // we need to find a replacement for the root that satisfies all the conditio0ns of BST
                // We have two choices,
                // 1. replace root by the smallest node (minimum -> left most leaf) in the right and delete that node from right
                // 2. replace root by the biggest node (maximum -> right most leaf) in the left and delete that node from left

                // We will be using the 1st method here
                BinaryTreeNode<int> *minNode = node->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                // int rightMin = minNode->data;
                // node->data = rightMin;
                node->data = minNode->data;
                node->right = deleteData(node->data, node->right);
                // Just to be sure that even if there was a right child of minNode, it is properly dealt with
                return node;
            }
        }
    }

public:                       // Time Complexity = O(h)
    void deleteData(int data) // delete is a reserved keyword, that's why we are using deleteData instead of delete
    {
        root = deleteData(data, root);
    }

private:
    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *node)
    {
        if (node == nullptr)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (node->data > data)
        {
            node->left = insert(data, node->left);
        }
        else
        {
            node->right = insert(data, node->right);
        }
        return node;
    }

public:
    void insert(int data) // Time Complexity = O(h)
    {
        this->root = insert(data, this->root);
    }

private:
    bool hasData(int data, BinaryTreeNode<int> *node)
    {
        if (node == nullptr)
        {
            return false;
        }
        if (node->data == data)
        {
            return true;
        }
        else if (node->data > data)
        {
            return hasData(data, node->left);
        }
        else
        {
            return hasData(data, node->right);
        }
    }

public:
    bool hasData(int data) // Time complexity = O(h)
    {
        return hasData(data, root);
    }

private:
    void printTree(BinaryTreeNode<int> *root)
    {
        if (root == nullptr)
        {
            return;
        }
        cout << root->data << ": ";
        if (root->left != nullptr)
        {
            cout << "L" << root->left->data << " ";
        }
        if (root->right != nullptr)
        {
            cout << "R" << root->right->data << " ";
        }
        cout << endl;
        printTree(root->left);
        printTree(root->right);
    }

public:
    void printTree()
    {
        printTree(root);
    }
};

/*
Balanced Tree:
For every node, |(height of node's left sub tree) - (height of node's right sub tree)| <= 1

For improved performance in a BST, the BST should be balanced

Height of a balanced BST is, h = O(logn) (approx.)
Thus means that for a balanced BST, Search, insertion and deletion, everything will be of O(logn)

Balanced BST:
1. AVL Tree* <- Important
2. Red Black Tree
3. 2 - 4 Tree
*/