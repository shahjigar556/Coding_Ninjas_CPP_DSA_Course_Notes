#include <iostream>
#include <queue>
#include <vector>
#include "BinaryTreeNode.h"
using namespace std;

// 1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 8 -1 -1 -1
BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return nullptr;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

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

// take input level wise
BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return nullptr;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

// print level wise
void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        cout << pendingNodes.front()->data << ":";
        if (pendingNodes.front()->left == nullptr)
        {
            cout << "L:" << -1 << ",";
        }
        else
        {
            cout << "L:" << pendingNodes.front()->left->data << ",";
            pendingNodes.push(pendingNodes.front()->left);
        }
        if (pendingNodes.front()->right == nullptr)
        {
            cout << "R:" << -1;
        }
        else
        {
            cout << "R:" << pendingNodes.front()->right->data;
            pendingNodes.push(pendingNodes.front()->right);
        }
        cout << endl;
        pendingNodes.pop();
    }
}

// count number of nodes
int numNodes(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + numNodes(root->left) + numNodes(root->right);
}

// Find a node is present or not
bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    bool present = false;
    if (root->left != nullptr)
    {
        present = isNodePresent(root->left, x);
        if (present)
        {
            return present;
        }
    }
    if (root->right != nullptr)
    {
        present = isNodePresent(root->right, x);
        if (present)
        {
            return present;
        }
    }
    return present;
}

// Height of a Binary Tree
int height(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int h = 1;
    int h1 = height(root->left);
    int h2 = height(root->right);
    h += h1 > h2 ? h1 : h2;
    return h;
}

// Mirror a given Binary Tree
void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    BinaryTreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}

// Binary Tree Traversal
// Inorder Traversal
void inorder(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal
void preOrder(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Postorder Traversal
void postOrder(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// Construct a tree from inorder and preorder
BinaryTreeNode<int> *buildTreeHelper(int *in, int *pre, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }

    int rootData = pre[preS];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;
    int rPreS = lPreE + 1;
    int rPreE = preE;
    int rInS = rootIndex + 1;
    int rInE = inE;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
    return root;
}

BinaryTreeNode<int> *buildTree(int *preorder, int preLength, int *inorder, int inLength)
{
    return buildTreeHelper(inorder, preorder, 0, inLength - 1, 0, preLength - 1);
}

// Construct a tree from inorder and postorder
BinaryTreeNode<int> *treeBuilderHelper(int *in, int *post, int inS, int inE, int postS, int postE)
{
    if (inS > inE || postS > postE)
    {
        return nullptr;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(post[postE]);
    int rootIndex;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == post[postE])
        {
            rootIndex = i;
            break;
        }
    }

    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPostS = postS;
    int lPostE = lPostS + lInE - lInS;
    int rPostS = lPostE + 1;
    int rPostE = postE - 1;
    int rInS = rootIndex + 1;
    int rInE = inE;

    root->left = treeBuilderHelper(in, post, lInS, lInE, lPostS, lPostE);
    root->right = treeBuilderHelper(in, post, rInS, rInE, rPostS, rPostE);
    return root;
}

BinaryTreeNode<int> *getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength)
{
    return treeBuilderHelper(inorder, postorder, 0, inLength - 1, 0, postLength - 1);
}

// Diameter of Binary Tree
// Time complexity = O(n * h); h -> height of the tree. So, time complexity of diameter depends on height.
int diameter(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int option1 = height(root->left) + height(root->right); // height function is defined above
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1, max(option2, option3));
}

// Diameter of Binary Tree with better Time Complexity
// It's time complexity is O(n)
// use inbuilt pair class
pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    pair<int, int> p;
    if (root == nullptr)
    {
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    p.first = height;
    p.second = diameter;
    return p;
}

// Min and Max of Binary Tree
pair<int, int> minMax(BinaryTreeNode<int> *root)
{
    pair<int, int> p;
    if (root == nullptr)
    {
        p.first = 99999;
        p.second = 0;
        return p;
    }
    pair<int, int> pl = minMax(root->left);
    pair<int, int> pr = minMax(root->right);
    p.second = max(root->data, max(pl.second, pr.second));
    p.first = min(root->data, min(pl.first, pr.first));
    return p;
}

// Root to Node Path in Binary Tree
vector<int> *getRootToNodePath(BinaryTreeNode<int> *root, int data)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> *leftOutput = getRootToNodePath(root->left, data);
    if (leftOutput != nullptr)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int> *rightOutput = getRootToNodePath(root->right, data);
    if (rightOutput != nullptr)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    return nullptr;
}

// Lowest Common Ancestor
vector<int> helper(BinaryTreeNode<int> *root, int val, vector<int> v)
{
    if (root == nullptr)
    {
        return v;
    }
    if (root->data == val)
    {
        v.push_back(root->data);
        return v;
    }
    vector<int> returnedV = helper(root->left, val, v);
    if (returnedV.size() == 0)
    {
        returnedV = helper(root->right, val, returnedV);
    }
    if (returnedV.size() != 0)
    {
        returnedV.push_back(root->data);
        return returnedV;
    }
    return returnedV;
}

int lcaBinaryTree(BinaryTreeNode<int> *root, int val1, int val2)
{
    // Write your code here
    vector<int> v1;
    vector<int> v2;
    vector<int> output1 = helper(root, val1, v1);
    vector<int> output2 = helper(root, val2, v2);
    if (output1.size() == 0 && output2.size() == 0)
    {
        return -1;
    }
    if (output1.size() == 0 && output2.size() != 0)
    {
        return val2;
    }
    if (output1.size() != 0 && output2.size() == 0)
    {
        return val1;
    }
    for (int i = 0; i < output1.size(); i++)
    {
        for (int j = 0; j < output2.size(); j++)
        {
            if (output1[i] == output2[j])
            {
                return output1[i];
            }
        }
    }
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
    /*
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    root->left = node1;
    root->right = node2;
    */

    // BinaryTreeNode<int> *root = takeInput();

    BinaryTreeNode<int> *root = takeInputLevelWise();

    printTree(root);
    cout << "Num: " << numNodes(root) << endl;
    inorder(root);
    cout << endl;
    pair<int, int> p = heightDiameter(root);
    cout << "Height: " << p.first << endl;
    cout << "Diameter: " << p.second << endl;
    vector<int> *output = getRootToNodePath(root, 8);
    for (int i = 0; i < output->size(); i++)
    {
        cout << output->at(i) << " ";
    }
    cout << endl;
    delete output; // as output vector is dynamically allocated
    delete root;
}