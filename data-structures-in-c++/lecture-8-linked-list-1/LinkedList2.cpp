/*
    First node of Linked List is called head and we store it's address
    Second node of Linked List is called tail which contains NULL at the next
    Always create nodes dynamically
*/

#include <iostream>
#include "Node2.cpp"
using namespace std;

/******************************************************************************************************************************
 * TAKE INPUT IN THE LIST 
 */
Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = nullptr; // head is created in this function, so, we need to return it
    Node *tail = nullptr;
    while (data != -1)
    {
        // Node node(data); // It's scope is only one iteration of while as it is created statically
        // So allocate dynamically
        // As they don't get deallocated automatically
        Node *node = new Node(data);
        // node pointer is statically created but the heap memory created with new keyword is dynamically created
        if (head == nullptr)
        {
            head = node;
            tail = head;
        }
        else
        {
            /*
            // Time complexity of the function with this while loop is O(n^2)
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            */

            // With tail node, the time complexity of this function is O(n)
            tail->next = node;
            tail = tail->next;
        }

        cin >> data;
    }
    return head;
}

/*******************************************************************************************************************************
 * INSERT NODE IN iTH POSITION
 */
Node *insertNode(Node *head, int i, int data) // This head is a new pointer that holds the address that is in the pointer that is passed
{
    // Just like arrays, any changes made to head or the list associated to head will be reflected in main
    // So, we don't need to return anythong
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;
    if (i == 0)
    {
        newNode->next = head;
        head = newNode; // main head is not changed. So, we need to return the updated head.
        return head;
    }
    while (temp != nullptr && count < i - 1)
    { // temp == NULL means that the list ended and we are at the next of the last node
        // Go to the index before which we need to insert the new node
        temp = temp->next;
        count++;
    }
    if (temp != nullptr)
    { // Execute if we are not at the next node of the last node of the list, which is NULL

        newNode->next = temp->next;
        // first connect the next node of temp to new newNode's next
        // If we do not do this first, then the connection between temp ant's next node will belost
        // And we will lose the rest of the nodes
        // So, after connecting temp's next to newNode's next then we can connect temp next to new node
        temp->next = newNode;
    }
    return head; // We actually need to return when we are changing the head node itself
}

/*******************************************************************************************************************************
 * INSERT NODE IN iTH POSITION RECURSIVELY
 */
Node *insertNodeRecursively(Node *head, int i, int data) // This head is a new pointer that holds the address that is in the pointer that is passed
{
    if (head == nullptr)
    {
        return head;
    }
    if (i == 0)
    {
        Node *node = new Node(data);
        node->next = head;
        head = node;
        return head;
    }
    if (i == 1)
    {
        Node *node = new Node(data);
        node->next = head->next;
        head->next = node;
        return head;
    }
    head->next = insertNodeRecursively(head->next, i - 1, data); // Link the updated list with head
    return head;
}

/*******************************************************************************************************************************
 * DELETE NODE AT iTH POSITION
 */
Node *deleteNode(Node *head, int i) // This head is a new pointer that holds the address that is in the pointer that is passed
{
    Node *temp = nullptr;
    int count = 0;
    if (i == 0)
    {
        temp = head->next;
        delete head;
        return temp;
    }
    temp = head;
    Node *node = nullptr;
    while (temp->next != nullptr && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next != nullptr)
    {
        node = temp->next;
        temp->next = temp->next->next;
        delete node;
    }

    return head;
}

/*******************************************************************************************************************************
 * DELETE NODE AT iTH POSITION RECURSIVELY
 */
Node *deleteNodeRecursively(Node *head, int i) // This head is a new pointer that holds the address that is in the pointer that is passed
{
    if (head == nullptr)
    {
        return head;
    }
    if (i == 0)
    {
        Node *node = head->next;
        delete head;
        return node;
    }
    if (i == 1 && head->next != nullptr) // If head->next == NULL for i == 1, then that means we are trying to delete NULL(i = 0).
                                         // Which is not feasible
    {
        Node *node = head->next->next;
        delete head->next;
        head->next = node;
        return head;
    }
    head->next = deleteNodeRecursively(head->next, i - 1);
    return head;
}

/*******************************************************************************************************************************
 * PRINT THE LIST 
*/
void print(Node *head)
{
    Node *node;
    node = head;
    // If we directly used the head pointer then only the copy of head in print() will be changed
    // but the head in main() will remain unchanged
    // and keep pointing to the first node
    while (node != nullptr)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

/*******************************************************************************************************************************
 * MAIN
 */
int main()
{
    /*
    // Statically
    Node n1(1);
    Node *head = &n1; // store the address of the node n1

    Node n2(2);

    n1.next = &n2; // store the address of node n2 in the next of the n1 and link the nodes

    cout << n1.data << " " << n2.data << endl;
    cout << head->data << " " << head->next->data << endl;

    // Dynamically
    Node *n3 = new Node(10);
    Node *head = n3; // store head

    Node *n4 = new Node(20);
    n3 -> next = n4; // (*n3).next = n4 
    // store the address that is stored in n4,
    // in the next of the node that is stored in the address,
    // which is stored in n3
    */

    /*   
    // Statically Create the lists
    Node n1(1);
    Node *head = &n1; // store the address of first node in head pointer

    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    // Link the lists
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    */

    /*
    // Dynamically Create the lists
    Node *head = new Node(10);
    Node *n1 = new Node(20);
    Node *n2 = new Node(30);
    Node *n3 = new Node(40);
    Node *n4 = new Node(50);

    // Link the lists
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    */

    /*
    // print the list
    print(head);
    */

    Node *head = takeInput();
    print(head);

    /*
    // insert a node
    int data, index;
    cin >> index >> data;
    head = insertNode(head, index, data);
    print(head);
    */

    /*
    // delete a node
    int index;
    cin >> index;
    head = deleteNode(head, index);
    print(head);
    */

    /*
    // insert a node recursively
    int index, data;
    cin >> index >> data;
    head = insertNodeRecursively(head, index, data);
    print(head);
    */

    /*
    // delete a node recursively
    int index;
    cin >> index;
    head = deleteNodeRecursively(head, index);
    print(head);
    */
}
