//Data Struct-Group6-Project9
/*
Project 9
One of the advantages of mergesort is that it can easily be adapted to sort a linked list of values. 
This is because the algorithm retrieves the values from the two lists being merged in the order that 
they occur in the lists. If the lists are linked lists, then that algorithm can simply move down the 
list node after node. With heapsort or quicksort the algorithm needs to move values from random 
location in the array, so they do not adapt as well to sorting a linked list. Write a program that sorts 
a linked list of integers using mergesort. This will require additional linked lists, but you should 
use linked lists, not arrays, for all your list storage.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

struct Node
{
    int data;
    struct Node *next;
} * stnode;

struct Node *SortedMerge(struct Node *a, struct Node *b);
void Split(struct Node *source, struct Node **frontRef, struct Node **backRef);

// This function sorts the linked list by changing the next pointer.
void MergeSort(struct Node **headRef) 
{
    struct Node *head = *headRef;
    struct Node *a;
    struct Node *b;

    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }

    Split(head, &a, &b);

    MergeSort(&a);
    MergeSort(&b);

    *headRef = SortedMerge(a, b);
}

//Takes two list sorted in increasing order and splits their nodes into one large sorted list.
struct Node *SortedMerge(struct Node *a, struct Node *b)
{
    struct Node *result = NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    //Selects between a / b, then repeats
    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

/*Splits the nodes of the given list into 2 parts : front and back halves then,
returns the two lists using the reference parameters. If the length is odd, the 
extra node should go in the front list. Uses the fast/slow pointer strategy.*/

void Split(struct Node *source, struct Node **frontRef, struct Node **backRef)
{
    struct Node *fast;
    struct Node *slow;
    slow = source;
    fast = source->next;

    //Move "fast" by 2 nodes 
    //Move "slow" by 1 node
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

//Displays the sorted linked list.
void Display(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %d  ", node->data);
        node = node->next;
    }
}

//Inserts node at begining
void Insert(struct Node **head_ref, int new_data)
{
    //Node allocation
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    //Inserts Data
    new_node->data = new_data;

    //Links the old list off latest node
    new_node->next = (*head_ref);

    //Points to the new node as Head
    (*head_ref) = new_node;
}

int main()
{

    int input, size;
    struct Node *res = NULL;
    struct Node *a = NULL;
    
    system("color 47");

    printf("\n");
    printf("==================================================================================================\n");
    printf("==============================\t\tProject 9: Merge Sort\t\t==========================\n");
    //printf("==================================================================================================\n");
    printf("\n");
    printf("\tProject Developers:\n");
    printf("\t\t%6c 1.DEV1 \t\t\t@ DEV1\n");
    printf("\t\t%6c 2.DEV2 \t@ DEV2\n");
    printf("\t\t%6c 3.DEV3 \t\t@ DEV3\n");
    printf("\t\t%6c 4.DEV4 \t\t@ DEV4\n");
    printf("\t\t%6c 5.DEV5 \t\t@ DEV5\n");
    printf("\n");
    //printf("==================================================================================================\n");
    printf("==================================================================================================\n\n");

    printf("===================================\t\tINPUT\t\t==================================\n");
    printf("\n");
    MessageBeep(MB_OK);
    printf("Enter the Size of the array : ");
    scanf("%d", &size);

    printf("\n");

    for (int i = 0; i < size; i++)
    {
        printf("Value %d : ",i+1);
        scanf("%d", &input);
        Insert(&a, input);
    }

    MergeSort(&a);
    printf("\n");
    printf("===================================\t\tOUTPUT\t\t==================================\n");
    printf("\n");
    printf("Sorted Linked List: ");
    Display(a);
    printf("\n");
    printf("\n==================================================================================================\n");
    MessageBeep(MB_OK);
    return 0;
}
