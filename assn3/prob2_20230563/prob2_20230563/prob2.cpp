#include "prob2.h"
#include <iostream>

void add(OrderedSet* ordered, int v)    // Function to add a single value to the list
{
    Node* newNode = new Node;   // Allocate a new node dynamically
    newNode->data = v;           // Store data in the new node
    Node* findNode = ordered->head;     // Create a traversal node
    Node* preNode = nullptr;           // Create a previous node for the traversal node

    while (findNode != nullptr && findNode->data < v)        // Finding the position where the new value should be inserted
    {
        preNode = findNode;
        findNode = findNode->next;
    }
    if (findNode != nullptr)     // If the value is duplicated, delete the node and return
    {
        if(findNode->data == v)
        {
            delete newNode;    
            return;
        } 
    }

    if (preNode == nullptr)   // When the new node should become the head
    {
        newNode->next = ordered->head;
        ordered->head = newNode;
    }
    else                       // When inserting a node in the middle
    {
        preNode->next = newNode;
        newNode->next = findNode;
    }
        
    
    ordered->m_size = size(ordered);    // Update the size of the list
}

void add(OrderedSet* ordered, const int* arr, int size)     // Function to add array values to the list
{
    for (int i = 0; i < size; ++i)
    {
        add(ordered, arr[i]);       // Add each element of the array to the list
    }
}

void remove(OrderedSet* ordered, int index)     // Function to remove the value at the index from the list
{
    Node* findNode = ordered->head;     // Create a traversal node
    Node* preNode = nullptr;            // Create a previous node for the traversal node
    for (int i = 0; i < index; ++i)     // Find the node to delete
    {
        preNode = findNode;
        findNode = findNode->next;
    }
    if (preNode != nullptr)             // When the previous node exists
        preNode->next = findNode->next; // Connect the previous node of the node to be deleted to the next node
    else                                // When the previous node does not exist
        ordered->head = findNode->next; // Set the next node of the node to be deleted as the head

    delete findNode;                    // Freeing the memory of the deleted node
    ordered->m_size = size(ordered);    // Update the size of the list
}

int size(OrderedSet* ordered)          // Function to return the size of the list
{
    int count = 0;
    Node* countNode = ordered->head;
    while (countNode != nullptr)        // Traverse the list and count the number of nodes
    {
        countNode = countNode->next;
        count++;
    }
    return count;
}

bool contains(OrderedSet* ordered, int v)  // Function to check if a specific value exists in the list
{
    Node* findNode = ordered->head;
    while (findNode != nullptr)         // Traverse the list and check for a specific value
    {
        if (findNode->data == v) return true;
        else findNode = findNode->next;
    }
    return false;
}

int getValue(OrderedSet* ordered, int idx) // Function to return the value at a specific index in the list
{
    if (idx >= ordered->m_size) return std::numeric_limits<int>::min(); // Return the minimum value if the index is greater than the size of the list

    Node* getValueNode = ordered->head;
    for (int i = 0; i < idx; ++i)           // Find the node at a specific index
    {
        getValueNode = getValueNode->next;
    }
    return getValueNode->data;              // Return the corresponding value
}
