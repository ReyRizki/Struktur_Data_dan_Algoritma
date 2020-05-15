// Program		: linkedList.h
// Author		: Rey Rizki
// Description	: Linked List ADT header file
// Date			: Friday, 17 April 2020
// Version		: V 2.5 (Calibrated for hobby field in Student ADT)
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#ifndef LIST_H_
#define LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <iso646.h>

#define u unsigned
#define s short
#define ll long long
#define REP(i, a, b) for (i = (a); i < (b); i++)
#define REPR(i, a, b) for (i = (a-1); i >= (b); i--)

typedef char* dataType;
typedef struct Node *address;

// struct for a node
typedef struct Node
{
    dataType data; // data of linked list
    address next;  // next node's address of a linked list
} Node;

// struct for a linked list
typedef struct
{
    address head; // head address of a linked list
} List;

// CONSTRUCTORS AND DESTRUCTORS
// ============================

// Description		: Function to create a new linked list
// Input			: -
// Output			: Linked list
List createList();

// Description		: Function to create a new node
// Input			: -
// Output			: Node
Node *createNode();

// Description		: Procedure to assign n to data in a node
// Initial State	: Node is not assigned yet
// Final State		: Node is assigned
void assignNode(Node *node, dataType n);

// Description		: Procedure to delete a node of a linked list
// Initial State	: Node is exist
// Final State		: Node is deleted
void deleteNode(Node *node);

// VALIDATOR
// =========

// Description		: Function to check if a list is empty or not
// Input			: Linked list
// Output			: True if empty and false if not empty
bool isListEmpty(List list);

// NODE INSERTION
// ==============

// Description		: Procedure to insert a new node in head
// Initial State	: Node is not inserted yet
// Final State		: Node is inserted
void insertAtHead(List *list, dataType n);

// Description		: Procedure to insert a new node in an index (the index cannot be greater than size of the list)
// Initial State	: Node is not inserted yet
// Final State		: Node is inserted
void insertAt(List *list, dataType n, u int index);

// Description		: Procedure to insert a new node in tail
// Initial State	: Node is not inserted
// Final State		: Node is inserted
void insertAtTail(List *list, dataType n);

// NODE DELETION
// =============

// Description		: Procedure to delete a node in head
// Initial State	: Node is not deleted yet
// Final State		: Node is deleted
void deleteAtHead(List *list);

// Description		: Procedure to delete a node in an index (the index cannot be greater than size of the list)
// Initial State	: Node is not deleted yet
// Final State		: Node is deleted
void deleteAt(List *list, u int index);

// Description		: Procedure to delete a node in tail
// Initial State	: Node is not deleted yet
// Final State		: Node is deleted
void deleteAtTail(List *list);

// LINKED LIST TRANSVERSAL
// =======================

// Description		: Procedure to print all the nodes in linked list
// Initial State	: List is not printed yet
// Final State		: List is printed
void printList(List list);

// Description		: Function to get the size of the list
// Input			: Linked list
// Output			: Size of the list
u int listSize(List list);

// ADDRESS ACCESSOR
// ================

// Description		: Function to get address of a node in an index (Index cannot be greater than the size of the list)
// Input			: Linked list and index
// Output			: Address of an index in linked list (NULL if index > size)
address addressAt(List list, u int index);

// Description		: Function to get address of tail of a linked list
// Input			: Linked list
// Output			: Address of tail node
address addressOfTail(List list);

// DATA ACCESSOR
// =============

// Description		: Function to get data in the head of linked list
// Input			: Linked list
// Output			: Data of the head node
dataType dataOfHead(List list);

// Description		: Function to get a data in an index of a linked list (index cannot be greater than size of the list)
// Input			: Linked list, index
// Output			: Data in an index of linked list (-1 if index > size)
dataType dataAt(List list, u int index);

// Description		: Function to get data in the tail of linked list
// Input			: Linked list
// Output			: Data of the tail node
dataType dataOfTail(List list);

#endif