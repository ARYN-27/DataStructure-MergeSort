# **Data Structure Project** 

# **Project 9 - MergeSort - Group 6**

## **Question** : 
- One of the advantages of mergesort is that it can easily be adapted to sort a linked list of values. This is because the algorithm retrieves the values from the two lists being merged in the order that they occur in the lists. If the lists are linked lists, then that algorithm can simply move down the list node after node. With heapsort or quicksort the algorithm needs to move values from random location in the array, so they do not adapt as well to sorting a linked list. Write a program that sorts a linked list of integers using mergesort. This will require additional linked lists, but you should use linked lists, not arrays, for all your list storage.

## **What does this code do?**
- This code performs MergeSort that sorts a list of intergers given to it.

## **How to run this code**
- ```gcc Project9-V2.c -o Project9-V2.exe```
- ```.\Project9-V2.exe```
> Run this code in a terminal. Do not execute the .exe outside of the terminal.

## **Functions in this Code** :
-  ```void MergeSort(struct Node **headRef)```
-  ```struct Node *SortedMerge(struct Node *a, struct Node *b)```
-  ```void Split(struct Node *source, struct Node **frontRef, struct Node **backRef)```
-  ```void Display(struct Node *node)```
-  ```void Insert(struct Node **head_ref, int new_data)```

## **Functions Purposes** :
### 1. ```void MergeSort(struct Node **headRef)```
- This function sorts the linked list by changing the next pointer.
### 2. ```struct Node *SortedMerge(struct Node *a, struct Node *b)```
- This function takes two list sorted in increasing order and splits their nodes into one large sorted list.
### 3. ```void Split(struct Node *source, struct Node **frontRef, struct Node **backRef)```
- This function split the nodes of the given list into 2 parts :  front and back halves then returns the two lists using the reference parameters. If the length is odd, the extra node should go in the front list. Uses the fast/slow pointer strategy.
### 4. ```void Display(struct Node *node)```
- This function does what it states. It displays the sorted linked list.
### 5. ```void Insert(struct Node **head_ref, int new_data)```
- This function inserts node in begining of the linked list.


## **Error when Running in Dev-C++ ?**
- Change `.c` files to `.cpp` when running in Dev-C++