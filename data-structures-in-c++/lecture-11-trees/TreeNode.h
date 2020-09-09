#include <vector>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
    // Even if we don't write <T> then  TreeNode will automatically hold the same data type as T
    // If it's not T, then in children vector we will not be able to insert values
    // Because the parent and children must be of same type
    // parent data is of type T, so, the TreeNode of children by default will be of type T

    /*
        Each children has a TreeNode class as the children vector's elements are of TreeNode class pointers
        So, whatever memory will be allocated, it will be allocated for the TreeNode class 
        and each children will hold those memory addresses 
        i.e, each children point tp their respective TreeNode classes in the heap memory
        Now, each TreeNode class will require a template T to be defined. 
        Which is by default set to the same data type as the parent class
    */

    TreeNode(T data)
    {
        this->data = data;
    }

    // destructor
    ~TreeNode()
    {
        for (int i = 0; i < this->children.size(); i++)
        {
            delete this->children.at(i);
        }
    }

    /*
    Whenever a object is deleted, it's destructor is called first then it is deleted
    */
};