#pragma once
#include <limits>
#include <iostream>


struct Node                  // Structure that holds data and points to the next node
{
    int data;
    Node* next = nullptr;
};

struct OrderedSet            // Structure that holds the head of nodes and the size of the list
{
    int m_size = 0;
    Node* head = nullptr;
};

void add(OrderedSet* ordered, int v);  // Function to add a single value to the set
void add(OrderedSet* ordered, const int* arr, int size);  // Function to add array values to the set
void remove(OrderedSet* ordered, int index);  // Function to remove the value at the index from the set
int size(OrderedSet* ordered);  // Function to return the size of the set
bool contains(OrderedSet* ordered, int v);  // Function to check if a specific value exists in the set
int getValue(OrderedSet* ordered, int idx);  // Function to return the value at a specific index in the set
