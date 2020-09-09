#include <iostream>
#include "TreeNode.h"
#include <queue>
using namespace std;

TreeNode<int> *takeInputLevelWise()
{

    int rootData;
    cout << "Enter root data " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes; // queue of TreeNode pointers of int type
    // These pending nodes are of the same level and are waiting for child nodes
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front(); // get the TreeNode pointer at the front of the queue
        pendingNodes.pop();                          // delete the TreeNode pointer at the front of the queue
        cout << "Enter number of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            cout << "Enter " << i << "th child of " << front->data << endl;
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child); // put the newly created tree node to the pending queue of children
        }
    }
    return root;
}

void printLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        cout << q.front()->data << ":";
        int n = q.front()->children.size();
        for (int i = 0; i < n - 1; i++)
        {
            cout << q.front()->children.at(i)->data << ",";
            q.push(q.front()->children.at(i));
        }
        if (n != 0)
        {
            cout << q.front()->children.at(n - 1)->data;
            q.push(q.front()->children.at(n - 1));
        }
        cout << endl;
        q.pop();
    }
}

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data " << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter num of children of " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int> *root)
{
    // edge case
    if (root == nullptr)
    { // tree is empty
        return;
    }
    cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children.at(i)->data << ", ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children.at(i));
    }
}

int numNodes(TreeNode<int> *root) // nomber of nodes of a tree
{
    if (root == nullptr)
    {
        return 0;
    }
    int ans = 1; // current node
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNodes(root->children.at(i)); // current node + child nodes
    }
    return ans;
}

// Maximum data node
TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return root;
    }
    TreeNode<int> *maxNode = root;
    TreeNode<int> *node = nullptr;
    for (int i = 0; i < root->children.size(); i++)
    {
        node = maxDataNode(root->children.at(i));
        if (node->data > maxNode->data)
        {
            maxNode = node;
        }
    }
    return maxNode;
}

// Height of a tree [Empty tree(root == nullptr) -> 0, only root tree -> 1,...]
int height(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int h = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int h1 = height(root->children.at(i));
        if (h1 > h)
        {
            h = h1;
        }
    }
    return 1 + h;
}

// Depth of a node [How far the node is from root. depth of root = 0. level and depth can be used interchangibly as level works the same way as depth]
void printAtLevelK(TreeNode<int> *root, int k)
{
    if (root == nullptr)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children.at(i), k - 1);
    }
}

// Number of Leaf nodes
int numLeafNodes(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->children.size() == 0)
    {
        return 1;
    }
    int leafs = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        leafs += numLeafNodes(root->children.at(i));
    }
    return leafs;
}

// Traversals

// pre-order traversal
void preorder(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children.at(i));
    }
}

// post-order traversal
void postorder(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children.at(i));
    }
    cout << root->data << " ";
}

/*
void deleteTree(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children.at(i));
    }
    delete root;
}
*/

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main()
{
    /*
    // create individual three nodes of our tree
    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *node1 = new TreeNode<int>(2);
    TreeNode<int> *node2 = new TreeNode<int>(3);

    // first create individual nodes
    // Then connect the nodes according to child and parent hieracrchy

    root->children.push_back(node1); // 1st child
    root->children.push_back(node2); // 2nd child
    printTree(root);
    */

    TreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    cout << "num: " << numNodes(root) << endl;
    cout << "Level 2: " << endl;
    printAtLevelK(root, 2);
    cout << "pre-order: "
         << " ";
    preorder(root);
    cout << endl;
    cout << "post-order: "
         << " ";
    postorder(root);
    cout << endl;

    // delete the tree

    // method 1: using function
    // deleteTree(root);

    // method 2: usinf destructor <- deleting a object means calling it's destructor
    delete root;
}