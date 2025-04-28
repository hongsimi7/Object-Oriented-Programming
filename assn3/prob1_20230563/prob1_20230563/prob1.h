#pragma once
#include <limits>
#include <iostream>

struct Node             // Structure that holds data and points to the next node
{
    int data;
    Node* next = nullptr;
};

struct OrderedList      // Structure that holds the head of nodes and the size of the list
{
    int m_size = 0;
    Node* head = nullptr;
};

void add(OrderedList* ordered, int v);  // Function to add a single value to the list
void add(OrderedList* ordered, const int* arr, int size);  // Function to add array values to the list
void remove(OrderedList* ordered, int index);  // Function to remove the value at the index from the list
int size(OrderedList* ordered);  // Function to return the size of the list
bool contains(OrderedList* ordered, int v);  // Function to check if a specific value exists in the list
int getValue(OrderedList* ordered, int idx);  // Function to return the value at a specific index in the list
